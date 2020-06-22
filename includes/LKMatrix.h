#ifndef LK_MATRIX
#define LK_MATRIX

#include <vector>
using namespace std;

class LKMatrix {
  public:
    int size;
    LKMatrix(vector <vector<double> >VehicleCost, vector<int> &ids);
    vector<int> getCurrentTour();
    double getCurrentTourDistance();
    void optimizeTour();
    void printTour();
    void printTourIds(vector <int> &T_opt_vehicle);
    vector<int> tour;

  private:
    
    vector<vector<int> > edgeFlags;
    vector<pair<double, double> > coords;
    // double VehicleCost[][n+2];
    vector<int> ids;
    void joinLocations(int i, int j);
    vector<vector<double> > edgeDistances;
    void LKMove(int tourStart);
    void reverse(int start, int end);
    bool isTour();
};

#endif
