#include "GRAPH.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

/*
    This function reads data from a file and builds the graph.
    It fills the adjacency matrix with weights between connected nodes.
    It also keeps track of the total number of nodes in the graph.
*/


void GRAPH::BUILD_GRAPH(string filename) {
    //Ανάγνωση στοιχείων από αρχείο και δημιουργία πίνακα γιτνίασης (2 διαστάσεων) για την 
    //αποθήκευση του βάρους των συνδέσεων
    for (int x = 0; x < 3000; x++)
        for (int y = 0; y < 3000; y++)
            array[x][y] = 0;
            
    //Αριθμός κόμβων μέσα στον γράφο
    komvoi = 0;

    ifstream c(filename);
    int nodeA, nodeB, weight;

    while (c >> nodeA >> nodeB >> weight) {
        array[nodeA][nodeB] = weight;
        array[nodeB][nodeA] = weight;

        if (nodeA + 1 > komvoi) {
            komvoi = nodeA + 1;
        }
        if (nodeB + 1 > komvoi) {
            komvoi = nodeB + 1;
        }
    }
    c.close();
}

//Συνάρτηση επιστροφής των συνολικών κόμβων του γράφου
int GRAPH::GetSizeGraph() {
    return komvoi;
}

//Δημιουργία σύνδεσης μεταξύ 2 κόμβων και ανανέωση του πίνακα γιτνίασης
void GRAPH::INSERT_GRAPH(int n1, int n2, int w) {
    if (array[n1][n2] == 0) {
        array[n1][n2] = w;
        array[n2][n1] = w;

        if (n1 + 1 > komvoi) komvoi = n1 + 1;
        if (n2 + 1 > komvoi) komvoi = n2 + 1;
    }
}

//Διαγραφή της σχέσης/διαδρομής μεταξύ δύο κόμβων
void GRAPH::DELETE_GRAPH(int n1, int n2) {
    if (array[n1][n2] != 0) {
        array[n1][n2] = 0;
        array[n2][n1] = 0;
    }
}

//Αλγόριθμος Dijkstra για την εύρεση της ελάχιστης διαδρομής μεταξύ δύο κόμβων
int GRAPH::COMPUTESHORTESTPATH_GRAPH(int start, int end) {
    const int INF = 1000000;
    int dist[3000];
    bool done[3000];

    for (int i = 0; i < komvoi; i++) {
        dist[i] = INF;
        done[i] = false;
    }
    dist[start] = 0;

    int Count = 0;
    while (Count < komvoi) {
        int pos = -1;
        int minDist = INF + 1;

        for (int i = 0; i < komvoi; i++) {
            if (!done[i] && dist[i] <= minDist) {
                minDist = dist[i];
                pos = i;
            }
        }
        if (pos == -1) break; 

        done[pos] = true;
        Count++;

        for (int neighbor = 0; neighbor < komvoi; neighbor++) {
            if (array[pos][neighbor] > 0 && !done[neighbor]) {
                int diaf = dist[pos] + array[pos][neighbor];
                if (diaf < dist[neighbor]) dist[neighbor] = diaf;
            }
        }
    }

    return dist[end];
}

//Αλγόριθμος του Prim, εύρεση του ελάχιστου δέντρου του δέντρου του γράφου και επιστρέφει 
//Το σύνολο του βάρους όλως των διαδρομών
int GRAPH::COMPUTESPANNINGTREE_GRAPH() {
    int ap = 100000;
    int min[3000];
    bool visited[3000];
    int totalCost = 0;

    for (int i = 0; i < komvoi; i++) {
        min[i] = ap;
        visited[i] = false;
    }

    min[0] = 0;

    for (int i = 0; i < komvoi; i++) {
        int u = -1;
        int minVal = ap;

        for (int j = 0; j < komvoi; j++) {
            if (!visited[j] && min[j] < minVal) {
                minVal = min[j];
                u = j;
            }
        }

        if (u == -1) {
            break;
        }
        visited[u] = true;
        totalCost += min[u];
        for (int v = 0; v < komvoi; v++) {
            if (array[u][v] > 0 && !visited[v] && array[u][v] < min[v]){
                min[v] = array[u][v];    
            }
        }
    }
    return totalCost;
}

//Depth-First Search για την ανζήτηση κόμβου στον γράφο
//Πίνακας αληθείας για στοιχεία που επισκευτήμαμε ήδη
void DFS(int node, bool visited[], int komvoi, int array[3000][3000]) {
    visited[node] = true;
    for (int geit = 0; geit < komvoi; geit++){
        if (array[node][geit] > 0 && !visited[geit]){
            DFS(geit, visited, komvoi, array);    //Αναδρομικά ξανκαλείτε
        } 
    } 
}


//Συνάρτηση που βρίσκει τον αριθμό των συνδεδεμέων κόμβων με την βοήθεια της αναζήτησης κατά βά΄θο(DFS)
int GRAPH::FINDCONNECTEDCOMPONENTS_GRAPH() {
    bool visited[3000];
    for (int i = 0; i < 3000; i++)
        visited[i] = false;

    int comp = 0;

    for (int i = 0; i < komvoi; i++) {
        if (!visited[i]) {
            comp++;
            DFS(i, visited, komvoi, array);
        }
    }
    return comp;
}