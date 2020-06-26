#ifndef TSP_AL
#define TSP_AL 


#include <string>
#include <vector>
#include <limits>
#include <chrono>
#include <iostream>
#include "list_customers.h"
#include "Solution.h"
#include "Label.h"
#include "LKMatrix.h"
#include "LPT.h"



class TSPalgorithm
{
public:

	std::chrono::high_resolution_clock::time_point start, end;
	std::chrono::duration <double> duration;
	double ms;
	CoordMatrix matrix;
	ListOfCustomers T, T_vehicle, T_drone, T_opt_vehicle;
	int  n;
	int m;
	double BestCost;
	vector <ListOfCustomers> T_opt_drone;
	vector <vector<int>> T_opt_drone_vect;
	Solution Sol, BestSol;
	double UB1 = numeric_limits<double>::max(); // UB1 is the value of best solution so far, so UB1 is set to positive infinity for initialization.
	double UB2, UB3, UB;
	vector <double> LB_veh, LB_tot;
	ListLabel List;
	
	

	void Initialize(
					 CoordMatrix* mat );
	void SetupMatrix(CoordMatrix *mat );

	TSPalgorithm(void);
	~TSPalgorithm(void);

	bool valid_arc(const int& j, const int& i);
	double CalDroneCost(const int& j, const int& i);
	int tour_size;
	void UB2Cal();
	void UB3Cal();
	void LB_vehCal();
	void LB_totCal();
	void DynamicProgramming();
	void Split();
	bool BoundingMechanisms(pair <double,double>& L, int index);
	void CreateSolution();
	void CreateTestSolution();
	void ReOptimizeVehicle();
	void ReOptimizeDrone();
	void MainAlgorithm();
	void BestInsertion();
	void test();

private:

	

};

#endif