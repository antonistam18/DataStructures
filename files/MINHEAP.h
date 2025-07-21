#ifndef MINHEAP_H
#define MINHEAP_H
#include <string>
using namespace std;
#include <iostream>

class MINHEAP{

    //Όπως και στην MAXHEAP και η σωρός ελαχίστων υλοποιείτε με μία δυναμική λίστα
    int* pin = new int[2000];
    //Μέγεθος σωρού
    int size;
    public:
        //Συναρτήσεις απαραίτητες για την υλοποίηση της σωρού ελαχίστων
        void BuildMinHeap(string filename);
        int GetSizeMinHeap();
        int FINDMIN_MINHEAP();
        void INSERTMIN_MINHEAP(int number);
        void DELETEMIN_MINHEAP();
};
#endif