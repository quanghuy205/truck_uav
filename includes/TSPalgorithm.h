#ifndef TSP_AL
#define TSP_AL 


#include <string>
#include <vector>
#include <limits>
#include "list_customers.h"
#include "Solution.h"
#include "Label.h"
#include "LKMatrix.h"
#include "LPT.h"
class TSPalgorithm
{
public:

	CoordMatrix matrix;
	ListOfCustomers T, T_vehicle, T_drone, T_opt_vehicle;
	const int n = 5;
	const int m = 2;
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

private:

	

};

#endif