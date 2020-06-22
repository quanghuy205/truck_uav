#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
#include <utility>
#include <set>
#include <limits>
#include "list_customers.h"
using namespace std;

class Solution {
public:

    Solution(void);
    ~Solution(void);
    ListOfCustomers VehicleTour;
    vector <ListOfCustomers> DroneTour; 
    bool isBetterSolution(Solution& B);
    double VehicleCost();
    double DroneCost();
    double Cost();
    void Reset();
}; 

#endif
