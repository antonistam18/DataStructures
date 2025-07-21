#include "MAXHEAP.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;


//Δημιουργία Σωρού Μεγίστων διαβάζοντας διαδοχικά από αρχείο
void MAXHEAP::BUILD_MAXHEAP(string filename) {
    size =0;
    ifstream b(filename);
    int val;

    while (b >> val) {
        int pos = size;
        //Τοποθετεί την input μεταβλητή στο τέλος της λίστας
        array[pos] = val;

        //Σταδιακά τα στοιχεία ανεβαίνουν προς τα επάνω της σωρού μέχρι να ισχύει η ιδιότητα της MAXHEAP
        while (pos > 0) {
            int parent = (pos - 1) / 2;
            if (array[pos] > array[parent]) {
                swap(array[pos], array[parent]);
                pos = parent;
            } 
            else break;
        }
        //Αύξοηση της σωρού κατά ένα στοιχείο
        ++size;
    }
    b.close();
}

//Επιστρέφει το μέγεθος της σωρού
int MAXHEAP::GetSizeMaxHeap() {
    return size;
}

//Επιστρέφει το μέγιστο στοιχείο την σωρού που βρίσκεται πάντα στον κόμβο ρίζα
int MAXHEAP::FINDMAX_MAXHEAP() {
    if (size > 0) return array[0];
    return -1;
}


//Εισαγωγή στοιχείου στη σωρό
void MAXHEAP::INSERT_MAXHEAP(int value) {
    int pos = size;
    //Αρχικά εισάγετε στο τέλος της λίστας της σωρού
    array[pos] = value;
    ++size;

    while (pos > 0) {
        //Σταδικά με αντιμεταθέσεις -swap αλλάζουν θέσεις τα στοιχεία ώστε να διατηρηθεί η ιδιότητα της σωρούς μεγίστων
        int parent = (pos - 1) / 2;
        if (array[pos] > array[parent]) {
            swap(array[pos], array[parent]);
            pos = parent;
        } 
        else break;
    }
}


//Διαγραφή του μεγίστου κόμβου-ρίζας της σωρού. Η ρίζα αντικαθιστάτε από το τελευταίο στοιχείου
//Της λίστας διαγράφετε και σταδιακά ο καινούργιος κόμβος ρίζα
//κατεβαίνει προς τα κάτω εκεί που αρχικά ΄ήταν η θέση του(Σταδιακές συγκρίσεις μεταξύ 
//πατέρα και του μεγαλύτερου παιδιού) =>η διάταξη της σωρού παραμένει ορθή 
void MAXHEAP::DELETE_MAXHEAP() {

    array[0] = array[size - 1];
    //Διαγράφετε ως τελευταίο στοιχείο της σωρού
    --size;

    int pos = 0;

    while (1) {
        int left = 2 * pos + 1;
        int right = 2 * pos + 2;
        int largest = pos;

        if (left < size && array[left] > array[largest]) largest = left;
        if (right < size && array[right] > array[largest]) largest = right;
        if (largest != pos) {
            swap(array[pos], array[largest]);
            pos = largest;
        } 
        else break;
    }
}