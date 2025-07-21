#include "AVLTREE.h"
#include <fstream>
#include <iostream>
using namespace std;
#include <string>

//Υπολογισμός ύψος δέντρου με ρίζα τον κόμβο που δίνεται ώς έισοδος
int AVLTREE::height(Node* node) {
    if (node == nullptr){
        return 0;    
    }
    else {
        return node->ypsos;
    }
}

int AVLTREE::getBalance(Node* node) {
    //Υπολογίζει και επιστρέφει αν το δέντρο με ρίζα τον κόμβο που δίνεται ως είσοδος είναι ισορροπιμένο (Επιστρέφει την διαφορά ανάμεσα στο
    //στο ύψος του αριστερόυ και του δεξιού υποδέντρου
    if (node == nullptr) {
        return 0; 
        
     }
        
    return height(node->left) - height(node->right);
}

AVLTREE::Node* AVLTREE::rotateRight(Node* y) {
    //Δεξιόστροφη περιστρογή για να μετατραπεί το δέντρο και πάλι σε ισορροπιμένο αν το αριστρό υποδέντρο είναι αρκετά 
    //μεγαλύτερο από το δεξί (>1)
    //Επιστρέφει τον καινούργιο κόμβο ρίζα
    Node* x = y->left;
    Node* dendro_2 = x->right;

    x->right = y;
    y->left = dendro_2;

    y->ypsos = max(height(y->left), height(y->right)) + 1;
    x->ypsos = max(height(x->left), height(x->right)) + 1;

    return x;
}

AVLTREE::Node* AVLTREE::rotateLeft(Node* x) {
    //Αριστερόστροφη περιστρογή για να μετατραπεί το δέντρο και πάλι σε ισορροπιμένο αν το δεξί υποδέντρο είναι αρκετά 
    //μεγαλύτερο από το αριστερό (>1)
    //Επιστρέφει τον καινούργιο κόμβο ρίζα
    Node* y = x->right;
    Node* dendro_2 = y->left;

    y->left = x;
    x->right = dendro_2;

    x->ypsos = max(height(x->left), height(x->right)) + 1;
    y->ypsos = max(height(y->left), height(y->right)) + 1;

    return y;
}

AVLTREE::Node* AVLTREE::insert(Node* node, int num) {
    //Εισαγωγή ενός στοιχείου στο ΄δέντο ελέγχοντας παράλληλα αν το δέντρο πρόκειτε για ισορροπιμένο και 
    // Κάνοντας τις καταλληλες περιστροφές αν αυτό είναι απαραίτητο
    //Ανανεώνει και το ύψος του δέντρου
    if (node == nullptr) {
        size++;
        return new Node(num);
    }
    if (num < node->num){ 
        node->left = insert(node->left, num);
    }
    else if (num > node->num) {
        node->right = insert(node->right, num);
    }
    else{
        return node;    
    }
    //Ανανέωση του ύψους
    node->ypsos = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);
    
    //Περιστροφές
    if (balance > 1 && num < node->left->num){
        return rotateRight(node);//LL
    }
    if (balance < -1 && num > node->right->num){
        return rotateLeft(node);//RR
    }
    if (balance > 1 && num > node->left->num) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);//LR
    }
    if (balance < -1 && num < node->right->num) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);//RL
    }
    return node;
}

void AVLTREE::BUILD_AVLTREE(string filename) {
    //Δημιουργία δέντρου με εισαγωγή στοιχείων 1-1 σε αυτό
    riza = nullptr;
    size = 0;
    ifstream file(filename);
    int num;
    while (file >> num){
        riza = insert(riza, num);    
    } 
}

//Επιστρέφει το μέγεθος του δέντρου
int AVLTREE::GetSizeAvlTree() {
    return size;
}

// Επιστρέφει το ελάχιστο στοιχείο του δέντρου
int AVLTREE::FINDMIN_AVLTREE() {
    Node* temp = riza;
    while (temp->left != nullptr){
        temp = temp->left;
    }
    return temp->num;
}


//Αναζητά ένα στοιχείο στο δέντρο και επιστρέφει αντίστοιχο μήνυμα
string AVLTREE::SearchAvlTree(int number) {
    Node* temp = riza;
    while (temp != nullptr) {
        if (number == temp->num){
            return "SUCCESS";
        }
        else if (number < temp->num){
            temp = temp->left;
        }
        else{
            temp = temp->right;    
        } 
    }
    return "FAILURE";
}

//Ανδρομική κλήση της insert AVLTREE για τους κόμβους εισώδου 
void AVLTREE::INSERT_AVLTREE(int num) {
    riza = insert(riza, num);

}


//Διαγράφει ένα στοιχείο από το δέντρο διατηρόντας το σε αύξουσα διάταξη (με in-order traversal)
void AVLTREE::DELETE_AVLTREE(int num) {
    Node* current = riza;
    Node* parent = nullptr;
    
    //Αναζήτηση κόμβου
    while (current != nullptr && current->num != num) {
        parent = current;
        if (num < current->num){
            current = current->left;
        }
        else{
            current = current->right;
        }
    }
    //Αν έχει δύο παιδιά βρίσκουμε τον successor (με inorder διάχηση)
    if (current->left != nullptr && current->right != nullptr) {
        Node* successorParent = current;
        Node* successor = current->right;
        while (successor->left != nullptr) {
            successorParent = successor;
            successor = successor->left;
        }
        current->num = successor->num;
        current = successor;
        parent = successorParent;
        num = successor->num;
    }
    //Αντικατάσταση του current κόμβου με το μοναδικό παιδί 
    Node* child = nullptr;
    if (current->left != nullptr){
        child = current->left;    
    } 
    else{
        child = current->right;    
    } 


    if (parent == nullptr){
        riza = child;    
    } 
    else if (parent->left == current) {
        parent->left = child;
    }
    else{
        parent->right = child;    
    } 
    delete current;
    size--;

    //Ξαναυπολογίζουμε το ύψος και γίνονται οι κατάλληλες περιστροφές για διατήρηση της διάταξης
    Node* stack[1000];
    int top = -1;
    Node* node = riza;
    if (node != nullptr){
        stack[++top] = node;    
    } 

    while (top >= 0) {
        node = stack[top--];

        node->ypsos = 1 + max(height(node->left), height(node->right));
        int balance = getBalance(node);

        if (balance > 1 && getBalance(node->left) >= 0){
            node = rotateRight(node);    
        } 
        else if (balance > 1 && getBalance(node->left) < 0) {
            node->left = rotateLeft(node->left);
            node = rotateRight(node);
        } 
        else if (balance < -1 && getBalance(node->right) <= 0){
            node = rotateLeft(node);
        } 
        else if (balance < -1 && getBalance(node->right) > 0) {
            node->right = rotateRight(node->right);
            node = rotateLeft(node);
        }

        if (node->left){
            stack[++top] = node->left;    
        } 
        if (node->right){
            stack[++top] = node->right;    
        } 
    }
}