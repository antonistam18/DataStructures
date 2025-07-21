#ifndef GRAPH_H
#define GRAPH_H
#include <string>
#include <iostream>

using namespace std;

class GRAPH {
private:

    //Array- Πίνακας γιτνίαση για γράφο που αποθηκεύει το βάρος των συνδε΄σεων όλων των κόμβων του γράφου(Max 3000 κόμβοι)
    int array[3000][3000]; 
    //Πλήθος κόμβων
    int komvoi;
public:
    
    //Συναρτήσεις που για την λειτουργία του γράφου (Η εξήγηση τους στο graph.cpp)
    void BUILD_GRAPH(string filename); 
    int GetSizeGraph();
    void INSERT_GRAPH(int num1, int num2, int varos);
    void DELETE_GRAPH(int num1, int num2);
    int COMPUTESHORTESTPATH_GRAPH(int num1, int num2);
    int COMPUTESPANNINGTREE_GRAPH();
    int FINDCONNECTEDCOMPONENTS_GRAPH();
};

#endif