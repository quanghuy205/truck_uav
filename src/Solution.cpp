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


bool Solution::isBetterSolution(Solution A, Solution B)
{   
    double CostOfA = max(A.VehicleCost(),A.DroneCost());
    double CostOfB = max(B.VehicleCost(), B.DroneCost());

    if ((CostOfA < CostOfB) ||( (CostOfA == CostOfB) && (min(A.VehicleCost(),A.DroneCost()) < min(B.VehicleCost(), B.DroneCost())))) return true;
    else return false;
}

double Solution::VehicleCost()
{
    return VehicleTour.Tour_VehicleCost();

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