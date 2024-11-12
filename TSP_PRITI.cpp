#include <iostream>
#include <climits>
using namespace std; 

#define N 10 
int n;
int adjMatrix[N][N]; 
int minCost = INT_MAX; 
int finalPath[N]; 
bool visited[N];

void copyToFinal(int currPath[]) {
    for (int i = 0; i < n; i++) {
        finalPath[i] = currPath[i];
    }
}

int calculateBound(int currPath[], int level, int currCost) {
    int bound = currCost;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            int minEdge = INT_MAX;
            for (int j = 0; j < n; j++) {
                if (!visited[j] && adjMatrix[i][j] && adjMatrix[i][j] < minEdge) {
                    minEdge = adjMatrix[i][j];
                }
            }
            bound += (minEdge == INT_MAX) ? 0 : minEdge;
        }
    }

    return bound;
}

void tspBranchAndBound(int currPath[], int level, int currCost) {
    if (level == n) { 
        if (adjMatrix[currPath[level - 1]][currPath[0]]) { 
            int totalCost = currCost + adjMatrix[currPath[level - 1]][currPath[0]];
            if (totalCost < minCost) {
                minCost = totalCost;
                copyToFinal(currPath);
            }
        }
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i] && adjMatrix[currPath[level - 1]][i]) { 
            visited[i] = true;
            currPath[level] = i;

            int newCost = currCost + adjMatrix[currPath[level - 1]][i];
            int bound = calculateBound(currPath, level + 1, newCost);

            if (bound < minCost) { 
                tspBranchAndBound(currPath, level + 1, newCost);
            }

            visited[i] = false; 
        }
    }
}

int main() {


    cout << "Enter the number of cities: ";
    cin >> n;

    cout << "Enter the adjacency matrix (use 0 for no direct path):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adjMatrix[i][j];
        }
    }

    int startCity;
    cout << "Enter the starting city (1 to " << n << "): ";
    cin >> startCity;
    startCity--; 

    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }
    int currPath[N];
    currPath[0] = startCity;
    visited[startCity] = true;

    tspBranchAndBound(currPath, 1, 0);

    cout << "The minimum cost is: " << minCost << endl;
    cout << "The path is: ";
    for (int i = 0; i < n; i++) {
        cout << finalPath[i] + 1 << " "; 
    }
    cout << startCity + 1 << endl; 

    return 0;
}
//Why Use the Bound?
The bound is a prediction of the minimum possible cost to complete the tour based on the current partial path.
