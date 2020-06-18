
#include "TSPalgorithm.h"
#include "Label.h"
#include <iostream>
#include <functional>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <random>
#include <chrono>
#include <vector>  
#include<limits>
#include <cstdlib>

using namespace std;

TSPalgorithm::TSPalgorithm(void)
{
}


TSPalgorithm::~TSPalgorithm(void)
{
}


//Set up TSP problem to run
void TSPalgorithm::Initialize( //const int& iter,
							   CoordMatrix* mat )
{
	// Set the matrix pointer for Tour object
	T.SetMatrix( mat );
    T_drone.SetMatrix(mat);
    

	
	//iterations = iter;
}

// void TSPalgorithm::SetupMatrix(CoordMatrix *mat )
// {
// 	for (int i = 0; i < NumberOfParticles; i++)
// 	{
// 		for (int j = 0; j <NumberOfSalesman; j++) 
// 		{
// 			A.AllSolution.at(i).Solution.at(j).SetMatrix(mat);
// 		}
// 	}

// }

default_random_engine dre (chrono::steady_clock::now().time_since_epoch().count());     // provide seed
int random (int lim)
{
    uniform_int_distribution<int> uid {1,lim};   // help dre to generate nos from 0 to lim (lim included);
    return uid(dre);    // pass dre as an argument to uid to generate the random no
}



void TSPalgorithm::CreateSolution()
{
	   
    // readTSP file
    matrix.Initialize("/home/quanghuy205/truck_uav_sal/tsp_data/att48.tsp");
    
   std::cout << "Problem name: "<<  matrix.GetFileTitle() << std::endl;
   // Initialize algorithm
   Initialize(&matrix);

}
//check arc(j,i) is valid (j before i in T && every node between j and i are drone-eligible)
bool TSPalgorithm::valid_arc(const int& j, const int& i) {
    for (int k = j + 1; k < i; k++) {
        if (matrix.DroneCost.at(T.cities.at(k)) == 0)               
            return false; 
    } 
    return true;
};


double TSPalgorithm::CalDroneCost(const int& j, const int& i)
{
	double cost = 0.0;
    for (int k = j+1; k < i; k++) {
        cost += matrix.DroneCost.at(T.cities.at(k));    
    }
    return cost;
}
void TSPalgorithm::UB2Cal()
{
    
	ListLabel ListUB2;
    std::pair <double,double> temp;


    ListUB2.ListOfLabel.resize(n+2);
    ListUB2.ListOfLabel.at(0).push_back(make_pair(0.0,0.0));  
  


   for (int i = 1; i <= n + 1; i++)
   {
       for (int j = 0; j < i; j++) 
       {
           if (valid_arc(j,i))
           cout << T.cities.at(j) << " " << T.cities.at(i) << endl;
       }
   }
  

    int i = 0;
  

    while (i < n+1) {
        i++;
        for (int j = 0; j < i; j++) {
            if (valid_arc( j, i) ){
                for (int l = 0; l < ListUB2.ListOfLabel.at(j).size(); l++) {
                 
                   temp = make_pair(ListUB2.ListOfLabel.at(j).at(l).first + matrix.TestDistance(T.cities.at(j),
                   T.cities.at(i)),ListUB2.ListOfLabel.at(j).at(l).second + CalDroneCost(j,i));
                 
                   ListUB2.addWithDominance(i,temp);
                }           
            }       
        }        
    }
    
    ListUB2.print();
   
    pair <pair<double,double>, int > BestLabel = ListUB2.findBestLabel();
    UB2 = max (BestLabel.first.first,BestLabel.first.second);
} 

void TSPalgorithm::UB3Cal()
{
    int i = 0;
    pair <double, double> p_UB3;                   
    p_UB3.first = 0.0;
    p_UB3.second = 0.0;
    while (i < n + 1) {
        i++;
         cout << p_UB3.first << " " << p_UB3.second << endl;  
        if ((matrix.DroneCost.at(T.cities.at(i)) > 0) && ((p_UB3.second + matrix.DroneCost.at(T.cities.at(i))) <= max(p_UB3.first,p_UB3.second)))
            p_UB3.second += matrix.DroneCost.at(T.cities.at(i));
            else p_UB3.first += matrix.TestDistance(T.cities.at(i-1), T.cities.at(i));
         
    }
    UB3 =  max(p_UB3.first,p_UB3.second);
}
bool TSPalgorithm::BoundingMechanisms(pair <double,double>& L, int index)
{
    if ((L.second >= UB) || (L.first + LB_veh.at(index) >= UB) || (L.first + L.second + LB_tot.at(index) >= 2*UB))
    {
        return true;
    } else 
        return false;
}
void TSPalgorithm::LB_vehCal()
{
    LB_veh.resize(n+2);
    LB_veh.at(n+1) = 0.0;

    for (int i = 0; i < n  + 1; i++) {
        LB_veh.at(i) = numeric_limits<int>::max();;
    }


    for ( int i = n; i >= 0; i--) {
        for (int j = i; j <= n + 1; j++) {
            if (valid_arc(i,j)) {
                if (LB_veh.at(i) > LB_veh.at(j) + matrix.TestDistance(T.cities.at(i), T.cities.at(j))) {
                    LB_veh.at(i) = LB_veh.at(j) + matrix.TestDistance(T.cities.at(i), T.cities.at(j));
                }
            }
        }
    }
    cout << "LB_veh = ";
    for (int i = 0; i <= n + 1; i++) {
        cout << LB_veh.at(i) << " " ;
    }
}

void TSPalgorithm::LB_totCal()
{
    LB_tot.resize(n+2);
    LB_tot.at(n+1) = 0;
    for (int i = 0; i < n + 1; i++) {
        LB_tot.at(i) = numeric_limits<int>::max();;
    }

    for ( int i = n; i >= 0; i--) {
        for (int j = i; j <= n + 1; j++) {
            if (valid_arc(i,j)) {
                if (LB_tot.at(i) > LB_tot.at(j) + matrix.TestDistance(T.cities.at(i), T.cities.at(j)) + CalDroneCost(i,j)) {
                    LB_tot.at(i) = LB_tot.at(j) + matrix.TestDistance(T.cities.at(i), T.cities.at(j)) + CalDroneCost(i,j);
                }
            }
        }
    }
    cout << "LB_tot = ";
    for (int i = 0; i <= n + 1; i++) {
        cout << LB_tot.at(i) << " " ;
    }

}

void TSPalgorithm::Split()
{
    
    std::pair <double,double> temp;


    List.ListOfLabel.resize(n+2);
    List.ListOfLabel.at(0).push_back(make_pair(0.0,0.0));  
  


    int i = 0;
  

    while (i < n+1) {
        i++;
        for (int j = 0; j < i; j++) {
            if (valid_arc( j, i) ){
                for (int l = 0; l < List.ListOfLabel.at(j).size(); l++) {
                 
                   temp = make_pair(List.ListOfLabel.at(j).at(l).first + matrix.TestDistance(T.cities.at(j),
                   T.cities.at(i)),List.ListOfLabel.at(j).at(l).second + CalDroneCost(j,i));
                //    if (!BoundingMechanisms(temp,i))
                   {
                        List.addWithDominance(i,temp);
                   }
                  
                }           
            }       
        }        
    }

       List.print();
   
    pair<pair<double,double>, int> BestLabel;
    BestLabel = List.findBestLabel();
    cout << "Best Label: " << "(" << BestLabel.first.first << "," << BestLabel.first.second << ")";
   
 
    // pair <pair<double,double>, int > BestLabel = ListUB2.findBestLabel();
    // UB2 = max (BestLabel.first.first,BestLabel.first.second);
}
void TSPalgorithm::Optimize()
{	
    matrix.CreateTestCostMatrix();
    Initialize(&matrix);
    T.cities.push_back(0);
    T.cities.push_back(1);
    T.cities.push_back(2);
    T.cities.push_back(3);
    T.cities.push_back(4);
    T.cities.push_back(5);
   T.cities.push_back(0);

  //  T.GetNearestNeighbourTour();
   
  //  T.printTour();
   cout << T.Tour_VehicleCost();
   UB2Cal();

    cout << "UB2 = " << UB2 << endl;
    UB3Cal();
    cout << "UB3 = " << UB3 << endl;
    LB_vehCal();
    cout << endl;
    LB_totCal();
    UB = min(min(UB1,UB2),UB3);
    cout << endl;
    cout << "UB = " << UB << endl;

    Split();

} 


void TSPalgorithm::Test()
{

}


	
		