#include <iostream>
#include "list_customers.h"
#include <vector>
#include <utility>

using namespace std;


ListOfCustomers::ListOfCustomers(void)
{
}


ListOfCustomers::~ListOfCustomers(void)
{
}


// Copy constructor
ListOfCustomers::ListOfCustomers( const ListOfCustomers& t )
{
	cities = t.cities;
}

// Assignment operator
ListOfCustomers& ListOfCustomers::operator=( const ListOfCustomers& t )
{
	if ( this != &t )
	{
		cities = t.cities;
	}

	return *this;
}

// Set pointer to cost / distance matrix object
void ListOfCustomers::SetMatrix( CoordMatrix* mat )
{
	matrix = mat;
}

// Get distance bewteen selected cities
double ListOfCustomers::VehicleDistance( const int& c1, 
		               const int& c2 ) const
{
	return matrix ->TestDistance( c1, c2 );
}

double ListOfCustomers::DroneDistance(const int& c) const
{
	return matrix->DroneCost.at(c);
}

double ListOfCustomers::Tour_VehicleCost()
{
    double cost = 0.0;

	int size = (int) cities.size();
	int c1, c2;

	for ( int i = 0; i < size - 1; i++ )
	{
		c1 = cities.at( i );
		c2 = cities.at( i + 1 );
		cost += VehicleDistance( c1, c2 );
	} 

	// And back to the beginning city
	c1 = cities.at( size - 1 );
	c2 = cities.at( 0 );
	cost += VehicleDistance( c1, c2 );

	return cost;
}

double ListOfCustomers::Tour_DroneCost()
{
    int cost = 0.0;
    int size = (int) cities.size();
    for (int i = 0; i < size; i ++) {
        cost += DroneDistance(cities.at(i));
    }
    return cost;
}

int ListOfCustomers::GetTourSize() const
{
	return (int) cities.size();
}

void ListOfCustomers::Reset()
{
	std::vector< int >().swap( cities );
}


void ListOfCustomers::printTour() 
{
	cout << "Tour: " ;
	for (int i = 0; i < cities.size(); i++) 
	{
		cout  << cities.at(i) << " ";
	}	
}




//Nearest Neighbour

bool ListOfCustomers::check_all_visited(int& n, vector<int> visited) {
    for (int i = 0; i <= n ; i++) {
        if (!visited[i]) {
            return false;
        }
    }
    return true;
} 

int ListOfCustomers::find_nearest_neighbour(int& n, vector <int> visited, int& current_vertex) {
    double min_distance = numeric_limits<int>::max();
    int min_index = 0;
    for (int i = 0; i <= n; i++) {
        if (!visited[i] && matrix->TestDistance(current_vertex,i) < min_distance) {
            min_distance = matrix->TestDistance(current_vertex,i);
            min_index = i;
        }
    }
    return min_index;
}

void ListOfCustomers::GetNearestNeighbourTour()
{
    int n = matrix->VehicleCost.size() - 2;
	//start node = depot = node 0
    int start_node = 0;
    // initialize visited array
	vector <int> visited;    
    for (int i = 0; i <= n; i++) {
        visited.push_back(0);
    }

    visited.at(start_node) = 1;
    int current_vertex = start_node;
    cities.push_back(current_vertex);

    while (!check_all_visited(n,visited)) {
        current_vertex = find_nearest_neighbour(n,visited, current_vertex);
        visited[current_vertex] = 1;
        cities.push_back(current_vertex);
    }
    cities.push_back(0); 
}                      