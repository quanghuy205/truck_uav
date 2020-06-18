#ifndef SPLIT
#define SPLIT

#include <vector>
using namespace std;

struct Label {
    int vehicle_cost;
    int drone_cost;
};

int dominance (Label A, Label B);
bool valid_arc(int j, int i, vector <int> DroneCost, vector <int> T); 
int CalculateDroneCost(int j, int i, vector <int> DroneCost,vector <int> T);
int calculateUB2 (vector<vector<int> > VehicleCost, int DroneCost[], int NumberOfCustomer, vector <int> T);
int calculateUB3 (vector<vector<int> > VehicleCost, vector <int> DroneCost, int NumberOfCustomer, vector <int> T);
int *calculateLB_veh(vector<vector<int> > VehicleCost, vector <int> DroneCost, int NumberOfCustomer, vector <int> T);
int *calculateLB_tot(vector<vector<int> > VehicleCost, vector <int> DroneCost, int NumberOfCustomer, vector <int> T);
void split(vector <int> T, vector <int> &T_vehicle, vector <int> &T_drone, int n, vector <vector<int> > VehicleCost, vector <int>  DroneCost);

#endif