//Εργασία Δομών Δεδομένων
//Χρήστος Παπαδόπουλος 4804
//Αντώνης Σταμάτης 4801

#include <string>
#include <fstream>
#include <sstream>
#include "MINHEAP.h"
#include "MAXHEAP.h"
#include "AVLTREE.h"
#include "HASHTABLE.h"
#include "GRAPH.h"
#include <chrono>

/* 
        ▸Χρησιμόποιούμε 4 εξωτερικές βιβλιοθήκες 
    1. Την String για την διαχείρηση των συμβολοσειρών (όπως αυτών που αντλούμε από το αρχείο command.txt)
    2. Την fstream για την διαχείρηση των αρχείων τόσο κατά το άνοιγμα (input) όσο και για το αποτέλεσμα της εκτέλεσης (output)
    3. Την sstream η οποία μας επιτρέπει να χρησιμοποιούμε strings σαν να ήταν ροές εισόδου
    4. Την Chrono για να υπολογίζουμε την ταχύτητα εκτέλεσης κάθε εντολής, κάτι πολύ χρήσιμο για μία βιβλιοθήκη δομών δεδομένων 
    όπου η μελέτη του χρόνου εκτέλεσης και των υπολογιστικών όρων είναι καίρια
    
        ▸Χρησιμόποιούμε την βιβλιοθήκη Chrono για να μετρήσουμε το χρόνο υλοποίησης κάθε εντολής, με 
    την βοήθεια της συνάρτησης high_resolution_clock με την οποοία καταγράφουμε 2 στιγμιότηπα χρόνου
    και με την χρήση της duration_cast υπολογίζουμε την διαφορά τους (δηλάδη το χρόνο εκτέλεσης της κάθε εντολής)
    σε nanosecond
    
        ▸Χρησιμοποιούμε το auto ώστε το αποτέλεσμα των συναρτήσεων της βιβλιοθήκης chrono να αποθηκεύονται σε μεταβλητές
    που καθορίζονται αυτόματα από τον compiler και να μην δηλώνονται κάθο φορά (πχ start, end)
    
    
*/
using namespace std;
//Δήλωση της κάθε δομής στην main
MINHEAP minheap;
MAXHEAP maxheap;
GRAPH graph;
AVLTREE avltree;
HASHTABLE hashtable;

/* 
*/
void CommandAction(const string& line, ofstream& output) {
    /* 
        ▸H CommandAction αποτελεί την συνάρτηση που παίρνει ως είσοδο ένα string που αφορρά την εκτέλεση μιας εντολής πάνω 
    σε μία δομή δεδομένων, την αναγνωρίζει και την εκτελεί κατάλληλη εντολή της αντίστοιχης δομής και εκτυπόντας
    στο τέλος το αποτέλεσμα στο output.txt (όποτε αυτό είναι απαραίτητο) και τον ανάλογο χρόνο εκτέλεσης

        ▸Χρησιμόποιούμε τις μεταβλητές "first" και "second" για να αποθηκεύσουμε την πρώτη και την δεύτερη λέξη 
    από το commands.txt με slicing, χωρίζοντας δηλαδή την ενιαία γραμμή σε λέξεις με την βοήθεια της stringstream
    Αυτό βολεύει γιατί αυτές οι δύο λέξεις είναι που μας δίνουν την κατάλληλη πληροφορ΄΄ια για το ποια εντολή 
    και για ποια δομή θα εκτελεστεί.
        ▸Η πρώτη λέξη καθορίζει το είδος της εντολής (πχ BUILD, GETSIZE) και η δεύτερη το σε ποια δομή αναφέρετε
    η εντολή (πχ MINHEAP,AVL) καλόντας έτσι κατάλληλα την κάθε μέθοδο για την αντίστοιχη δομή
    
    */
    string first, second; 
    stringstream str(line);
    str >> first >> second;
    if (first == "BUILD") {             //Αν η πρώτη λέξει πρόκειται για build τότε η δεύτερη λέξη καθορίζει ποιά δομή θα δημιουργηθεί
        string fileinfo;                //Δημιουργέι την αντίχτοιχη δομή με τα στοιχεία που βρίσκονται στο 
        str >> fileinfo;
        chrono::nanoseconds duration; //Μετράμε τον χρόνοσε nanoseconds ώστε να έχουμε ένα έυρος σύγκρισης με νόημα

        if (second == "MINHEAP") {
            //Η χρονομέτρηση κάθε εντολής λειτουργεί ως εξής: 
            //Με το start μετράμε την χρονική στιγμή πριν την εντολής
            auto start = chrono::high_resolution_clock::now();
            //Εκτελούμε την εντο΄λή
            minheap.BuildMinHeap(fileinfo);
            //Μετράμε την χρονική στιγμή μετά την εντολή
            auto end = chrono::high_resolution_clock::now();
            //υπολογίζουμε την χρονική διαφορά τους
            auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
        }
        else if (second == "MAXHEAP"){
          auto start = chrono::high_resolution_clock::now();   
          maxheap.BUILD_MAXHEAP(fileinfo);
          auto end = chrono::high_resolution_clock::now();
          auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
        }
        else if (second == "GRAPH"){
            auto start = chrono::high_resolution_clock::now();
            graph.BUILD_GRAPH(fileinfo);
            auto end = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
        }
        else if (second == "AVLTREE"){
            auto start = chrono::high_resolution_clock::now();
            avltree.BUILD_AVLTREE(fileinfo);
            auto end = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
        }
        else {
            auto start = chrono::high_resolution_clock::now();
            hashtable.BUILD_HASHTABLE(fileinfo);
            auto end = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
        }
        output<<"Build"<< second<< " Execution Time is: "<<duration.count() << "\n";
    }
    else if (first == "GETSIZE") {
        //Αν η πρώτη λέξη είναι GETSIZE τότε η δεύτερη λέξη είναι αυ΄τη που καθορίζει το μέγεθος ποιας δομής θα επιστραφεί
        chrono::nanoseconds duration;
        int result = 0;
        if (second == "MINHEAP"){
            auto start = chrono::high_resolution_clock::now();
            result = minheap.GetSizeMinHeap();
            auto end = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
        }
        else if (second == "MAXHEAP"){
            auto start = chrono::high_resolution_clock::now();
            result = maxheap.GetSizeMaxHeap(); 
            auto end = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
        } 
        else if (second == "GRAPH"){ 
            auto start = chrono::high_resolution_clock::now();
            result = graph.GetSizeGraph();
            auto end = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
        }
        else if (second == "AVLTREE"){ 
            auto start = chrono::high_resolution_clock::now();
            result = avltree.GetSizeAvlTree();
            auto end = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
        }
        else{
            auto start = chrono::high_resolution_clock::now();
            result = hashtable.GetSizeHashtable();
            auto end = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
        }
        output << "Size in "<<second<<" is: "<<result << "\n";
        output<< "GetSize in "<< second<<" Execution Time was: "<< duration.count() << "\n";
    }
    else if (first == "FINDMIN") {
        //Εύρεση ελαχίστου από σωρό ελαχίστου ή ισσοροπινμένο δυαδικό δέντρο αναζήτησης (AVL)
        chrono::nanoseconds duration;
        int result;
        if (second == "MINHEAP"){ 
            auto start = chrono::high_resolution_clock::now();
            result = minheap.FINDMIN_MINHEAP();
            auto end = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
        }
        else{
            auto start = chrono::high_resolution_clock::now();
            result = avltree.FINDMIN_AVLTREE();
            auto end = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
        }
        output<< "Findmin in "<<second<<" Execution Time was: "<< duration.count() << "\n";
       
    }
    else if (first == "FINDMAX") {
        //Εύρεση μεγίστου από σωρό μεγίστου
        int result;
        auto start = chrono::high_resolution_clock::now();
        result = maxheap.FINDMAX_MAXHEAP();
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
        output << "Max in MaxHeap is: "<<result << "\n";
        output<< "Find Max in Maxheap Execution Time is: "<< duration.count() << "\n";
    }
    else if (first == "SEARCH") {
        //Αναζήτηση στοιχείου στο AVL tree ή στον πίνακα κατακερματισμού (hashtable)
        int value;
        str >> value;
        string result;
        chrono::nanoseconds duration;
        if (second == "AVLTREE"){ 
            auto start = chrono::high_resolution_clock::now();
            result = avltree.SearchAvlTree(value);
            auto end = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
        }
        else{
            auto start = chrono::high_resolution_clock::now();
            result = hashtable.SearchHashtable(value);
            auto end = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
        }
        output << "Search in "<<second<<" was "<<result << "\n";
        output<< "Search in "<<second<<" Execution Time was: "<< duration.count() << "\n";

    }
    else if (first == "INSERT") {
        //Εισαγωγή στοιχείου στην αντίστοιχη δομή
        chrono::nanoseconds duration;
        if (second == "MINHEAP") {
            int val;
            str >> val;
            auto start = chrono::high_resolution_clock::now();
            minheap.INSERTMIN_MINHEAP(val);
            auto end = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
        }
        else if (second == "MAXHEAP") {
            int val;
            str >> val;
            auto start = chrono::high_resolution_clock::now();
            maxheap.INSERT_MAXHEAP(val);
            auto end = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
        }
        else if (second == "GRAPH") {
            int komvos1, komvos2, komvos3;
            str >> komvos1 >> komvos2 >> komvos3;
            auto start = chrono::high_resolution_clock::now();
            graph.INSERT_GRAPH(komvos1, komvos2, komvos3);
            auto end = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
        }
        else if (second == "AVLTREE") {
            int val;
            str >> val;
            auto start = chrono::high_resolution_clock::now();
            avltree.INSERT_AVLTREE(val);
            auto end = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
        }
        else {
            int val;
            str >> val;
            auto start = chrono::high_resolution_clock::now();
            hashtable.INSERT_HASHTABLE(val);
            auto end = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
        }
        output<<"Insert in "<<second<< " Execution Time is: "<< duration.count() << "\n";
    }
    else if (first == "COMPUTESHORTESTPATH") {
        //Ελάχιστη διαδρομή ανάμεσα σε 2 κόμβους ενός γράφου
        int u, v,res;
        str >> u >> v;
        auto start = chrono::high_resolution_clock::now();
        res= graph.COMPUTESHORTESTPATH_GRAPH(u, v);
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
        output<<"Shortest path: "<<res<< "\n";
        output<< "COMPUTESHORTESTPATH Execution Time is: "<< duration.count() << "\n";
    }
    else if (first == "COMPUTESPANNINGTREE") {
        //Υπολογισμός του ελάχιστου δέντρου του γράφου
        int res;
        auto start = chrono::high_resolution_clock::now();
        res= graph.COMPUTESPANNINGTREE_GRAPH();
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
        output<<"Spanning tree: "<<res<<"\n";
        output<< "COMPUTESPANNINGTREE Execution Time is: "<< duration.count() << "\n";
    }
    else if (first == "FINDCONNECTEDCOMPONENTS") {
        //Υπολογισμός των συνολικών συνδεδεμένων κόμβων των γράφων
        int res;
        auto start = chrono::high_resolution_clock::now();
        res= graph.FINDCONNECTEDCOMPONENTS_GRAPH();
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
        output<<"Connected components: "<<res<<"\n";
        output<< "FINDCONNECTEDCOMPONENTS Execution Time is: "<< duration.count() << "\n";
    }
    else if (first == "DELETE") {
        //Διαγραφή ενός κόμβου από κάθε αντίστοιχή δομή
        chrono::nanoseconds duration;
        if (second == "MINHEAP"){
          auto start = chrono::high_resolution_clock::now();
          minheap.DELETEMIN_MINHEAP();
          auto end = chrono::high_resolution_clock::now();
          auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
        } 
        else if (second == "MAXHEAP") {
            auto start = chrono::high_resolution_clock::now();
            maxheap.DELETE_MAXHEAP();
            auto end = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
        }
        else if (second == "GRAPH") {
            int komvos1, komvos2;
            str >> komvos1 >> komvos2;
            auto start = chrono::high_resolution_clock::now();
            graph.DELETE_GRAPH(komvos1, komvos2);
            auto end = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
        }
        else {
            int val;
            str >> val;
            auto start = chrono::high_resolution_clock::now();
            avltree.DELETE_AVLTREE(val);
            auto end = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
        }
        output<<"Delete in "<<second<< " Execution Time is: "<< duration.count() << "\n";
    }
}

int main() {
    // Άνοιγμα αρχείου commands.txt
    ifstream commands("commands.txt");
    if (!commands.is_open()) {
        cerr << "Error, could not open commands.txt" << endl;
        return 1;
    }
    //Άνοιγμα αρχείου για εγραφή με flag οout
    ofstream output("output.txt",ios::out);
    if (!output) {
        cerr << "Error with output file" << endl;
        return 1;
    }
    string var;
    output<<"(All execution times are counted in nanoseconds)"<<"\n\n";
    //Κλήση της CommandAction για κάθε γραμμή που διαβάζει από το commands.txt
    while (getline(commands, var)) {
        CommandAction(var, output);
    }
}