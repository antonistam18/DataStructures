#include "MINHEAP.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void MINHEAP::BuildMinHeap(string filename) {
    //Διάβασμα αριθμών από αρχείο και εισαγωγή τους στην λίστα ένα πρός ένα
    size=0;
    ifstream a(filename);
    int value;

    while (a >> value) {
        int pos = size;
        //Κάθε αριθμός μπάινει στο τ΄έλος της λίστας της σωρού
        pin[pos] = value;

        while (pos > 0) {
            ////Σταδιακά τα στοιχεία ανεβαίνουν προς τα επάνω της σωρού μέχρι να ισχύει η ιδιότητα της MINHEAP
            int parent = (pos - 1) / 2;
            if (pin[pos] < pin[parent]) {
                swap(pin[pos], pin[parent]);
                pos = parent;
            } else break;
        }
        //Αύξοηση της σωρού κατά ένα στοιχείο
        ++size;
    }
    a.close();
}

//Επιστρέφει το μέγεθος της σωρού
int MINHEAP::GetSizeMinHeap() {
    return size;
}

//Επιστρέφει το ελάχιστο στοιχείο την σωρού που βρίσκεται πάντα στον κόμβο ρίζα
int MINHEAP::FINDMIN_MINHEAP() {
    if (size > 0) return pin[0];
    return -1;
}

void MINHEAP::INSERTMIN_MINHEAP(int num) {
    //Εισαγωγή στοιχείου στη σωρό
    int pos = size;
    //Αρχικά εισάγετε στο τέλος της λίστας της σωρού
    pin[pos] = num;
    ++size;

     while (pos != 0) {
        //Σταδικά με αντιμεταθέσεις -swap αλλάζουν θέσεις τα στοιχεία ώστε να διατηρηθεί η ιδιότητα της σωρούς μεγίστων
        int parent = (pos - 1) / 2;
        if (pin[pos] >= pin[parent]) break;
        swap(pin[pos], pin[parent]);
        pos = parent;
    }
}


//Διαγραφή του ελάχιστου κόμβου-ρίζας της σωρού. Η ρίζα αντικαθιστάτε από το τελευταίο στοιχείου,
//της λίστας έπειτα διαγράφετε και σταδιακά ο καινούργιος κόμβου ρίζας κατεβαίνει προς τα κάτω εκεί που 
//αρχικά ΄ήταν η θέση του(Σταδιακές συγκρίσεις μεταξύ 
//πατέρα και του μεγαλύτερου παιδιού) => η διάταξη της σωρού παραμένει ορθή 
void MINHEAP::DELETEMIN_MINHEAP() {
    pin[0] = pin[size - 1];
    --size;
    int pos = 0;
    while (1) {
        int left = 2 * pos + 1;
        int right = 2 * pos + 2;
        int smallest = pos;
        if (left < size && pin[left] < pin[smallest]){
            smallest = left;    
        } 
        if (right < size && pin[right] < pin[smallest]){
            smallest = right;    
        } 
        if (smallest != pos) {
            swap(pin[pos], pin[smallest]);
            pos = smallest;
        }
        else break;
    }
}