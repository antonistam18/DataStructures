#ifndef AVLTREE_H
#define AVLTREE_H
#include <string>
using namespace std;

class AVLTREE {
    private:

        struct Node {
            //Κόμβος του δέντρου που περιέχει τον δείκτη του αριστερού και του δεξιού του κόμβου-παιδια
            //Το ypsos το ύψος του δέντρου
            int num;
            Node* right;
            Node* left;
            int ypsos;

            //Δημιουργία κ΄όμβου
            Node(int var) {
                num = var;
                left = nullptr;
                right = nullptr;
                ypsos = 1;
            }
        };
        //Δήλωση κόμβου ρία
        Node* riza;
        int size;
        
        // Βοηθηττικές συναρτήσεις
        int getBalance(Node* node); //Υπολογίζει διαφορά μέγιστου και ελάχιστου ύψους δέντρου   
        int height(Node* node); //Επιστρέφει ύψος τουτ δέντρου με ρίζα τον κόμβο εισόδου
        Node* rotateRight(Node* y); //Δεξιόστροφη Περιστροφή
        Node* rotateLeft(Node* x); //Αριστερόστροφη Περιστροφή
        Node* insert(Node* node, int num); //Εισαγωγή κόμβου`
        Node* deleteNode(Node* node, int num); //Διαγραφή κόμβου
    public:
    
        //Δήλωση συναρτήσεων που αφορούν το AVLTREE και περιγράφονται στην main
        void BUILD_AVLTREE(string filename);
        int GetSizeAvlTree();
        int FINDMIN_AVLTREE();
        string SearchAvlTree(int num);
        void INSERT_AVLTREE(int num);
        void DELETE_AVLTREE(int num);
};
#endif