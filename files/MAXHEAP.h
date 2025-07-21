#ifndef MAXHEAP_H
#define MAXHEAP_H
#include <string>
using namespace std;
#include <iostream>

class MAXHEAP{
    //Αrray η δυναμική λίστα που αποθηκεύονται οι κόμβοι με την βοήθεια της οποία υλοποιείτε η σωρός μεγίστων
    int* array =new int[1000];
    //Το μέγεθος της σωρού
    int size;
    public:
        //Βοηθιτικές συναρτήσεις για την υλοποίηση της σωρού (Περιγράφονται στο .cpp)
        void BUILD_MAXHEAP(string filename);
        int GetSizeMaxHeap();
        int FINDMAX_MAXHEAP();
        void INSERT_MAXHEAP(int num);
        void DELETE_MAXHEAP();
};
#endif