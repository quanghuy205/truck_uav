#include<iostream>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<limits>
#include "LPT.h"
using namespace std;
// Driver function to sort the vector elements 
// by second element of pairs 
bool sortbysec(const pair<int,int> &a, 
              const pair<int,int> &b) 
{ 
    return (a.second < b.second); 
} 
  

void optimizePMS(vector<vector <int> > &T_opt_drone, vector <int> T_drone, vector<vector <double> > VehicleCost,  vector <double> DroneCost, int M) {
    vector <pair<int,double>> cost_length;   
    vector <double> Total_time_assign(M,0);
    vector <vector<int> > T_opt_drone_1(M);
    vector <pair <int,double>> drone_customer;
//    pair <vector<int>,vector<int>> customer_assign; 
    for (int i  = 0; i < T_drone.size(); i++) 
    {
        drone_customer.push_back(make_pair(T_drone.at(i),DroneCost.at(T_drone.at(i))));
      
    }

    double min;
    
    for (int i = 0; i < T_drone.size(); i++) 
    {
        cost_length.push_back(drone_customer.at(i));    
    }

    
    sort(cost_length.begin(), cost_length.end(),sortbysec);
  
    // for (int i = 0; i < cost_length.size(); i++) 
    // { 
    //     // "first" and "second" are used to access 
    //     // 1st and 2nd element of pair respectively 
    //     cout << cost_length[i].first << " "
    //          << cost_length[i].second << endl; 
    // } 
    
    while (!cost_length.empty()) {
      
        min = *min_element(Total_time_assign.begin(), Total_time_assign.end());
        for (int i = 0; i < Total_time_assign.size(); i++) {
            
            if (Total_time_assign[i] == min) {
                Total_time_assign.at(i) += cost_length.back().second;

                
                T_opt_drone_1.at(i).push_back(cost_length.back().first);
                cost_length.pop_back();
                break;
            }
            
        }     
    }        
    
    T_opt_drone = T_opt_drone_1;
    // for (int i = 0; i < T_opt_drone.size(); i++) {
    //     cout << "Drone " << i << ": ";
    //     for (int j = 0; j < T_opt_drone[i].size(); j++) {
    //         cout << T_opt_drone[i][j]<< " ";
    //     }
    //     cout << endl;
    // }
}