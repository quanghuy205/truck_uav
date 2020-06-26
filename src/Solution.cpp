#include <iostream>
#include <Solution.h>
#include <vector>
#include <utility>
 #include <algorithm>
using namespace std;


Solution::Solution(void)
{
}


Solution::~Solution(void)
{
}


bool Solution::isBetterSolution(Solution& B)
{   
    double CostOfA = max(VehicleCost(),DroneCost());
    double CostOfB = max(B.VehicleCost(), B.DroneCost());

    if ((CostOfA < CostOfB) ||( (CostOfA == CostOfB) && (min(VehicleCost(),DroneCost()) < min(B.VehicleCost(), B.DroneCost())))) return true;
    else return false;
}

double Solution::VehicleCost()
{   
    
    
    double cost =  VehicleTour.Tour_VehicleCost();
  
    return cost;
   
}
double Solution::DroneCost()
{
    vector <double> DronCostVect;
    if (DroneTour.empty()) return 0.0;
    for (int i = 0; i < DroneTour.size(); i++)
    {
        DronCostVect.push_back(DroneTour.at(i).Tour_DroneCost());
    }

    return *std::max_element(DronCostVect.begin(),DronCostVect.end());
}


double Solution::Cost()
{
    return max(VehicleCost(),DroneCost());
}
void Solution::Reset()
{
    std::vector <int> ().swap(VehicleTour.cities);
    for (int i = 0; i < DroneTour.size(); i++)
    {
        std::vector <int> ().swap(DroneTour.at(i).cities);
    }
}