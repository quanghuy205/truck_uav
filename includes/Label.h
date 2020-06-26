#ifndef LABEL
#define LABEL

#include <vector>
#include <utility>
#include <set>
#include <limits>
#include "list_customers.h"
using namespace std;

class ListLabel {
public:
   //copy constructor
    ListLabel(void);

    ListLabel(const ListLabel& t);

    // Assignment operator
	ListLabel& operator=( const ListLabel& t );
    ~ListLabel(void);
    
    vector <vector <pair<double,double>>> ListOfLabel;

    bool isEmptyto(const int& index);
    void print();
    void addLabel (const int& ListIndex, const pair <double,double> &L);
    
    void addWithDominance(const int& ListIndex, pair <double,double>& L);
    void addWithDominanceUB2(const int& ListIndex, pair <double,double>& L);
    int dominance (pair <double,double>&  A, pair <double,double>&  B);
    bool dominanceUB2 (pair <double,double>&  A, pair <double,double>&  B);
    void removeLabel(const int & ListIndex, const int& LabelIndex);
    void Reset();
    pair <pair<double,double>, int> findBestLabel();
    private:
    
};

#endif
