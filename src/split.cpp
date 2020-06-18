#include<iostream>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<limits>
#include "split.h"    
using namespace std;


//dominance rule : return 0 if A > B. return 1 if A < B, else return 2
int dominance (Label A, Label B) {
    if (((A.vehicle_cost < B.vehicle_cost)&&(A.drone_cost <= B.drone_cost)) || ((A.vehicle_cost <= B.vehicle_cost)&&(A.drone_cost < B.drone_cost)))
        return 0;
        else if (((A.vehicle_cost > B.vehicle_cost)&&(A.drone_cost >= B.drone_cost)) || ((A.vehicle_cost >= B.vehicle_cost)&&(A.drone_cost > B.drone_cost)))
           return 1;
           else return 2;        
};

//check arc(j,i) is valid (j before i in T && every node between j and i are drone-eligible)
bool valid_arc(int j, int i, vector <int> DroneCost, vector <int> T) {
    for (int k = j + 1; k < i; k++) {
        if (DroneCost[T[k]] == 0)               
            return false; 
    } 
    return true;
};

//calculate dronecost if vehicle travels directly from j -> i
int CalculateDroneCost(int j, int i, vector <int> DroneCost,vector <int> T) {
    int cost = 0;
    for (int k = j+1; k < i; k++) {
        cost += DroneCost[T[k]];    
    }
    return cost;
}

//calculate UB2 (running algorithm split() without bouding mechanism and new dominance rule)
int calculateUB2 (vector<vector<int> > VehicleCost, vector<int> DroneCost, int NumberOfCustomer, vector <int> T) {
    int i = 0;
    int n = NumberOfCustomer;
    vector <Label> ListUB2[n+2];
    ListUB2[0].push_back({0,0});
    while (i < n+1) {
        i++;
        for (int j = 0; j < i; j++) {
            if (valid_arc(j,i, DroneCost, T)) {
                for (int l = 0; l < ListUB2[j].size(); l++) {
                    ListUB2[i].push_back({ListUB2[j][l].vehicle_cost + VehicleCost[T[j]][T[i]], ListUB2[j][l].drone_cost + CalculateDroneCost(j,i,DroneCost,T)});        
                    if (ListUB2[i].size() > 1) 
                        if (max(ListUB2[i].back().vehicle_cost, ListUB2[i].back().drone_cost) <= max(ListUB2[i].front().vehicle_cost, ListUB2[i].front().drone_cost)) 
                            ListUB2[i].erase(ListUB2[i].begin());
                            else 
                                ListUB2[i].pop_back();   
                }           
            }       
        }        
    }
   
    return max((ListUB2[i].back().vehicle_cost), ListUB2[i].back().drone_cost);
}

//calculate UB3 () : using greedy algorithm: Nodes are added to the vehicle tour τ vehicl e except when the two following conditions hold: node i
//is drone-eligible and adding i to the drone does not increase the completion time of the current partial solution.
int calculateUB3 (vector<vector<int> > VehicleCost, vector <int> DroneCost, int NumberOfCustomer, vector <int> T) {
    int i = 0;
int n = NumberOfCustomer;
    Label UB3;                   
    UB3.vehicle_cost = 0;
    UB3.drone_cost = 0;
    while (i < n + 1) {
        i++;
        if ((DroneCost[T[i]] > 0) && ((UB3.drone_cost + DroneCost[T[i]]) <= max(UB3.vehicle_cost,UB3.drone_cost)))
            UB3.drone_cost += DroneCost[T[i]];
            else UB3.vehicle_cost += VehicleCost[T[i-1]][T[i]];
    }
    return max(UB3.vehicle_cost,UB3.drone_cost);
}

//calculate LB_veh: the minimal vehicle cost c1(P) of any path P between i and n + 1
int *calculateLB_veh(vector<vector<int> > VehicleCost, vector <int> DroneCost, int NumberOfCustomer, vector <int> T) {
    int *LB_veh = new int[NumberOfCustomer+2];
    LB_veh[NumberOfCustomer+1] = 0;
    for (int i = 0; i < NumberOfCustomer + 1; i++) {
        LB_veh[i] = numeric_limits<int>::max();;
    }

    for ( int i = NumberOfCustomer; i >= 0; i--) {
        for (int j = i; j <= NumberOfCustomer + 1; j++) {
            if (valid_arc(i,j,DroneCost,T)) {
                if (LB_veh[i] > LB_veh[j] + VehicleCost[T[i]][T[j]]) {
                    LB_veh[i] = LB_veh[j] + VehicleCost[T[i]][T[j]];
                }
            }
        }
    }
    
    return LB_veh;
}

//calculate LB_tot: minimal total cost c1(P) + c2(P) of any path P between i and n + 1
int *calculateLB_tot(vector<vector<int> > VehicleCost, vector <int> DroneCost, int NumberOfCustomer, vector <int> T) {
    int *LB_tot = new int[NumberOfCustomer+2];
    LB_tot[NumberOfCustomer+1] = 0;
    for (int i = 0; i < NumberOfCustomer + 1; i++) {
        LB_tot[i] = numeric_limits<int>::max();;
    }

    for ( int i = NumberOfCustomer; i >= 0; i--) {
        for (int j = i; j <= NumberOfCustomer + 1; j++) {
            if (valid_arc(i,j,DroneCost, T)) {
                if (LB_tot[i] > LB_tot[j] + VehicleCost[T[i]][T[j]] + CalculateDroneCost(i,j,DroneCost,T)) {
                    LB_tot[i] = LB_tot[j] + VehicleCost[T[i]][T[j]] + CalculateDroneCost(i,j,DroneCost,T);
                }
            }
        }
    }
    
    return LB_tot;
}

void split(vector <int> T, vector <int> &T_vehicle, vector <int> &T_drone, int n, vector <vector<int> > VehicleCost, vector <int>  DroneCost) {   
    vector <Label> ListOfLabel[n+2];   
    //initialize ListOfLabel[0] = (0,0)
    ListOfLabel[0].push_back({0,0});
    //Bounding calculation
    int UB1 = numeric_limits<int>::max(); // UB1 is the value of best solution so far, so UB1 is set to positive infinity for initialization.
    int UB2 = calculateUB2(VehicleCost,DroneCost,n,T);
    int UB3 = calculateUB3(VehicleCost,DroneCost,n,T);
    int UB = min(min(UB1,UB2),UB3); // UB = min (UB1,UB2, UB3)
    cout << "LB_veh = ";
    int *ptr_LB_veh = calculateLB_veh(VehicleCost,DroneCost,n,T);
    for (int i = 0; i <= n + 1; i++) {
        cout << ptr_LB_veh[i] << " " ;
    }
    cout << endl;
    cout << "LB_tot = ";
    int *ptr_LB_tot = calculateLB_tot(VehicleCost,DroneCost,n,T);
    for (int i = 0; i <= n + 1; i++) {
        cout << ptr_LB_tot[i] << " " ;
    }
    cout << endl;
    cout <<  "UB1 = " << UB1 << endl <<  "UB2 = " << UB2 << endl <<  "UB3 = " << UB3 << endl <<  "UB = " << UB << endl;
   //Algorithm 2: split(T)
    //dynamic programming
    int i = 0;

    while (i < n+1) {
        i++;    
        for (int j = 0; j < i; j++) {
            if ((valid_arc(j, i, DroneCost,T)) && (ListOfLabel[j].size() != 0)) {    //check all j if arc (j,i) exist
                for (int l = 0; l < ListOfLabel[j].size(); l++) {                  // check all Label belongs to L[j]

                    ListOfLabel[i].push_back({ListOfLabel[j][l].vehicle_cost + VehicleCost[T[j]][T[i]], ListOfLabel[j][l].drone_cost + CalculateDroneCost(j,i,DroneCost,T)});  //calculate cost add to L[i]
                    
                    //bounding mechanism ( prune Label L with 3 rules: R1, R2, R3)
                    if ((ListOfLabel[i].back().drone_cost > UB) || (ListOfLabel[i].back().vehicle_cost + ptr_LB_veh[i] > UB) || (ListOfLabel[i].back().vehicle_cost + ListOfLabel[i].back().drone_cost + ptr_LB_tot[i] > 2*UB) ) {
                       ListOfLabel[i].pop_back();
                    }   
                    //dominance rule: compare new label to all of Labels in the ListOfLabel[i], if Label A dominates Label B, delete B.
                    if (ListOfLabel[i].size() > 1) {
                        for (int k = 0; k < ListOfLabel[i].size() - 1; k++) {
                            if (dominance(ListOfLabel[i].back(),ListOfLabel[i][k]) == 0) 
                                ListOfLabel[i].erase(ListOfLabel[i].begin()+k);
                                else if (dominance(ListOfLabel[i].back(),ListOfLabel[i][k]) == 1) 
                                    ListOfLabel[i].pop_back();  
                        }
                    }
                }           
            }               
        }        
    }

    delete ptr_LB_tot;
    delete ptr_LB_veh;

   //find best label 
    int tmp_MinLabel = max(ListOfLabel[n+1][0].vehicle_cost, ListOfLabel[n+1][0].drone_cost);
    int best_LabelIndex = 0;
    for (int v = 1; v < ListOfLabel[n+1].size(); v++) {
        //cout << "(" << ListOfLabel[n+1][v].vehicle_cost << "," <<  ListOfLabel[n+1][v].drone_cost << ")" << endl;
        if (tmp_MinLabel > max(ListOfLabel[n+1][v].vehicle_cost, ListOfLabel[n+1][v].drone_cost)) {
            tmp_MinLabel = max(ListOfLabel[n+1][v].vehicle_cost, ListOfLabel[n+1][v].drone_cost);
            best_LabelIndex = v;
        }
    }
    
    
    //print
    for (int j = 0; j <= n+1; j++) {
        cout << "ListOfLabel " << "L(" << j << ") :";
        if (!ListOfLabel[j].empty()){
            for (int v = 0; v < ListOfLabel[j].size(); v++) {
                cout << "(" << ListOfLabel[j][v].vehicle_cost << "," <<  ListOfLabel[j][v].drone_cost << ")" << ", ";
            }
        }    
        cout << endl;  
    }
    
    cout << "Best Label :" << "(" << ListOfLabel[n+1][best_LabelIndex].vehicle_cost << "," <<  ListOfLabel[n+1][best_LabelIndex].drone_cost << ")" << endl;
    
    // decomposition to assign customer sequence to T_vehicle and T_drone
    
    Label tmp = ListOfLabel[n+1][best_LabelIndex];
 
    i = n + 1;
    int j = 0;
    bool stop_check;
    while (i >= 1) {
        j = i - 1;
        stop_check = false;
            while (!stop_check) {
                if (ListOfLabel[j].empty()) {
                    T_drone.push_back(T[j]);
                    j--;
                } else {
                    for (int v = 0; v < ListOfLabel[j].size(); v++) {
                        if (tmp.vehicle_cost == ListOfLabel[j][v].vehicle_cost + VehicleCost[T[j]][T[i]] && tmp.drone_cost == ListOfLabel[j][v].drone_cost + CalculateDroneCost(j,i,DroneCost,T)) {
                            tmp.vehicle_cost = ListOfLabel[j][v].vehicle_cost;
                            tmp.drone_cost = ListOfLabel[j][v].drone_cost;
                            if ( j != 0) {
                                T_vehicle.push_back(T[j]);
                            }                            
                            stop_check = true;
                        }                    
                    }
                    if (!stop_check) {
                        T_drone.push_back(T[j]);
                        j--;
                    }
                }
            }    
        i = j;
    }
     
    reverse(T_vehicle.begin(),T_vehicle.end());
    reverse(T_drone.begin(),T_drone.end());

}


