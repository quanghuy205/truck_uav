#ifndef LIST_CUS
#define LIST_CUS

#include <vector>
#include <utility>
#include <set>
#include <limits>
#include "CoordMatrix.h"
using namespace std;

class ListOfCustomers {
public:
    //copy constructor
    ListOfCustomers(void);

    ListOfCustomers(const ListOfCustomers& t);
    // Assignment operator
	ListOfCustomers& operator=( const ListOfCustomers& t );

    ~ListOfCustomers(void);
    vector <int> cities;
    double VehicleDistance(const int& c1, const int& c2) const;
    double DroneDistance(const int& c) const;
    double Tour_VehicleCost ();
    double Tour_DroneCost ();
    void SetMatrix( CoordMatrix* mat );  
    int GetTourSize() const;
    void printTour();
    void Reset();
    
    bool check_all_visited(int& n, vector <int> visited);
    int find_nearest_neighbour(int& n, vector <int> visited, int& current_vertex);
    int get_nearest_neighbour_ct(int& n, vector <int> visited, int& current_vertex);
    std::vector <int> GetNearestNeighbourTour();
    void CreateNearestNeighbourTour();
    
    
    
private:
//	std::vector< int > cities;
	CoordMatrix* matrix;
};

#endif
