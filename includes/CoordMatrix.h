
#ifndef Coord
#define Coord 

#include <vector>
#include <map>
#include <fstream>
#include <tuple> 
#include <string>


class CoordMatrix
{
public:
	enum EDGE_WEIGHT_TYPE
	{
		ATT = 0,
		EUC_2D = 1
	};

	CoordMatrix(void);
	~CoordMatrix(void);

	void Initialize( std::string filepath ); 

	double CalcPseudoEuclidDistance( const double& x1,
		                             const double& x2,
								     const double& y1,
								     const double& y2 );
	double MDistance (const int &c1, const int &c2);
	bool valid_arc(const int& j, const int& i);
	double Distance( const int& c1, const int& c2 );	
	double TestDistance( const int& c1, const int& c2 );	
	double CalDroneCost(const int& j, const int& i);
	int size() const;
	int GetX( const int& index ) const;
	int GetY( const int& index ) const;
	int GetMinX() const;
	int GetMinY() const;
	int GetMaxX() const;
	int GetMaxY() const;
	void CreateTestCostMatrix();
	void SetDistanceMatrix();
	void SetDroneCostMatrix();
	void SetVehicleCostMatrix();
	std::string GetFileTitle() const;
	std::vector< std::pair<double, double> > coords;
	std::map< std::pair<int,int>, double > distMatrix;
	std::map< std::pair<int,int>, double > ManhattandistMatrix;
	std::string title;
	std::vector <bool> DroneTooHeavy;
	std::vector <double> DroneCost;
	std::vector <std::vector<double>> VehicleCost;
	int minx;
	int miny;
	int maxx;
	int maxy;
	int edge_weight_type;
private:
	
	void tokenize( std::vector<std::string>& tokens,  
				   const std::string& text,  
				   const std::string& delimiter );  


	
	void Reset();
};

#endif