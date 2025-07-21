#include "HASHTABLE.h"
#include <fstream>
#include <string>
#include <iostream>

using namespace std;


//Συνάρτηση δημιουργίας πίνακα κατακερματισμού διαβάζοντας αριθμούς από το αρχέιo 
void HASHTABLE::BUILD_HASHTABLE(string filename) {
    size = 0;
    for (int i = 0; i < 1000; ++i) {
        //Καθαρίζει τον πίνακα και βάζει για όλες τις τιμές = 0
        katilimeno[i] = false;
        table[i] = 0;
    }

    ifstream file(filename);
    int num;
    //Διβάζοντας από το αρχείο εισάγωνται διαδοχικά τα στοιχεία στον πίνακα με γραμμική δοκιμή
    while (file >> num) INSERT_HASHTABLE(num);
    file.close();
}

//Επιστρέφει τον αριθμό των στοιχείων που βρίσκονται μέσα στον πίνακα
int HASHTABLE::GetSizeHashtable() {
    return size;
}


//Εισαγωγή ενός στοιχείου στον πίνκα χρησιμοποιώντας μια γραμμική συνάρτηση κατακερματισμού (num mod 1000)
//Έτσι εντοπίζεται η σωστή θέση που πρέπει να εισαχθεί το στοιχείο αν η προηγούμενη είναι κατηλλημένη
//ΠΧ Αν in:1003 inMOD1000=3 ελέυθερη θέση 
//Αν τώρα in:2003 inMOD1000=3 κατηλλημένη θέσση -> Μεταφέρομαι στην αμέσως επόμενη διαθέισμη (τώρα στην 4)
void HASHTABLE::INSERT_HASHTABLE(int num) {
    int pos = num % 1000;
    int original = pos;

    while (katilimeno[pos]) {
        if (table[pos] == num) return ;
        pos = (pos + 1) % 1000;
        if (pos == original) return ; 
    }

    table[pos] = num;
    katilimeno[pos] = true;
    ++size;
}


string HASHTABLE::SearchHashtable(int num) {
    //Αναζήτηση στοιχείου στον πίνακα
    //Ξεκινάει από την δηλωμένη θέση και ελέγχει σειριακά αν το στοιχείο υπάρχει στο κάθε επόμενο κελί
    int pos = num % 1000;
    int start = pos;

    while (katilimeno[pos]) {
        //Αν το βρει Επιστρέφει SUCCESS
        if (table[pos] == num) return "SUCCESS";
        pos = (pos + 1) % 1000;
        if (pos == start) break;
    }
    //Αλλιώς Επιστρέφει FAILURE αν βρει κενό κελί ή ολοκκληρώσει ένα ολόκληρο κύκλο
    return "FAILURE";
}