#include <iostream>
#include "Label.h"
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;


ListLabel::ListLabel(void)
{
}
ListLabel::~ListLabel(void)
{
}


// Copy constructor
ListLabel::ListLabel( const ListLabel& t )
{
	ListOfLabel = t.ListOfLabel;
}

// Assignment operator
ListLabel& ListLabel::operator=( const ListLabel& t )
{
	if ( this != &t )
	{
		ListOfLabel = t.ListOfLabel;
	}

	return *this;
}


bool ListLabel::isEmptyto(const int& index)
{
    for (int i = 0; i < index; i++)
    {
        if (!ListOfLabel.at(i).empty()) return false;
         
    }
    return true;
}


void ListLabel::removeLabel(const int& ListIndex, const int& LabelIndex)
{   
    std::vector <std::pair<double,double>>::iterator it;
    it = ListOfLabel.at(ListIndex).begin() + LabelIndex;
    ListOfLabel.at(ListIndex).erase(it);
}

void ListLabel::addLabel(const int& ListIndex, const pair <double,double> &L)
{
    ListOfLabel.at(ListIndex).push_back(L);
}

void ListLabel::print()
{
    for (int i = 0; i < ListOfLabel.size(); i++) 
    {
        std::cout <<  "L(" << i << "): ";
        for (int j = 0; j < ListOfLabel.at(i).size(); j++)
        {
            cout << "(" << ListOfLabel.at(i).at(j).first << "," <<  ListOfLabel.at(i).at(j).second << ")" << ", ";
        }
        std::cout << endl;
    }
    

}
//dominance rule : return 0 if A > B. return 1 if A < B, else return 2
int ListLabel::dominance (pair <double,double>&  A, pair <double,double>&  B) {
    if (((A.first < B.first)&&(A.second <= B.second)) || ((A.first <= B.first)&&(A.second < B.second)))
        return 0;
        else if (((A.first > B.first)&&(A.second >= B.second)) || ((A.first >= B.first)&&(A.second > B.second)))
           return 1;
           else return 2;        
};

void ListLabel::addWithDominance(const int& Listindex, pair <double,double>& L)
{
    
    bool isDiscard = false;
    for (int i = 0; i < ListOfLabel.at(Listindex).size(); i++)
    {   
        if (dominance(L , ListOfLabel.at(Listindex).at(i)) == 0)
        {
            ListOfLabel.at(Listindex).erase(ListOfLabel.at(Listindex).begin() + i);      
        } else 
        if(dominance(L , ListOfLabel.at(Listindex).at(i)) == 1)
        {
            isDiscard = true;
        }
    }
    if (!isDiscard) 
    {
        ListOfLabel.at(Listindex).push_back(L);
    }

}

pair <pair<double,double>, int>  ListLabel::findBestLabel()
{
    int index = ListOfLabel.size() - 1;
    
    vector <double> Max_LabelCost, Min_LabelCost;
   
 
    for (int i = 0; i < ListOfLabel.at(index).size(); i++)
    {
        Max_LabelCost.push_back(max(ListOfLabel.at(index).at(i).first,ListOfLabel.at(index).at(i).second ));
        Min_LabelCost.push_back(min(ListOfLabel.at(index).at(i).first,ListOfLabel.at(index).at(i).second ));
    }
    double minElement = Max_LabelCost.at(0);
    int bestLabelIndex = 0;
    
    for (int i = 1; i < ListOfLabel.at(index).size(); i++)
    {
        if ( (minElement > Max_LabelCost.at(i)) || ((minElement == Max_LabelCost.at(i) && (Min_LabelCost.at(bestLabelIndex) > Min_LabelCost.at(i) ))))
        {
            minElement = Max_LabelCost.at(i);
            bestLabelIndex = i; 
        }
    }
    
    pair <double,double> bestLabel = make_pair (ListOfLabel.at(index).at(bestLabelIndex).first,ListOfLabel.at(index).at(bestLabelIndex).second );
    return make_pair(bestLabel,bestLabelIndex);
}

void ListLabel::Reset()
{
    vector <vector <pair<double,double>>> ().swap(ListOfLabel); 
}


