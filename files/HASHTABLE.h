#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <string>
#include <iostream>
using namespace std;
class HASHTABLE {
private:
    //Table υλοποιεί έναν πίνακα που αποθηκεύει τον αριθμό των κόμβων στον πίνακα κατακερματισμού
    int table[1000];
    //Ο πίνακας αληθείας katilimeno αποθηκεύειτο άν ένα κελί είναι κατηλλημένο ή όχι
    bool katilimeno[1000];
public:

    //Size είναι ο αριθμός των κόμβων στον πίνακα
    int size;
    //Συναρτήσεις που υλοποιούν τον πίνακα κατακερματισμού (Η περιγραφή του υπάρχει στο .cpp αρχείο)
    void BUILD_HASHTABLE(string filename);
    int GetSizeHashtable();
    void INSERT_HASHTABLE(int num);
    string SearchHashtable(int num);
};
#endif