//OBST
#include <iostream>
using namespace std;



int find(float c[][10], int r[][10], int i, int j) 
{ 
    float minCost = 1e9 // Set a very high initial value for minimum cost
    int minIndex = i;//stores the indec which gives the minimum cost

    for (int m = r[i][j - 1]; m <= r[i + 1][j]; m++) 
    {
        if ((c[i][m - 1] + c[m][j]) < minCost) 
        {
            minCost = c[i][m - 1] + c[m][j];
            minIndex = m;
        }
    }
    return minIndex;
}

void obst(float p[], float q[], int n) 
{
    float w[10][10] = {0};  
    float c[10][10] = {0};  
    int r[10][10] = {0};    

    // Initialize base cases for OBST
    for (int i = 0; i <= n; i++) 
    {
        w[i][i] = q[i];
        r[i][i] = 0;
        c[i][i] = 0;
    }

    // OBST for length 1
    for (int i = 0; i < n; i++) 
    {
        w[i][i + 1] = q[i] + q[i + 1] + p[i + 1];
        r[i][i + 1] = i + 1;//Root: Only one key, so the root is that key.
        c[i][i + 1] = w[i][i + 1];//Cost: Cost is just the total weight for one key.
    }

    w[n][n] = q[n];
    r[n][n] = 0;
    c[n][n] = 0.0;

    // OBST for lengths 2 and more(j-i)
    for (int m = 2; m <= n; m++) //m is length of subtree
    {
        for (int i = 0; i <= n - m; i++) 
        {
            int j = i + m;
            w[i][j] = w[i][j - 1] + p[j] + q[j];
            int k = find(c, r, i, j);  
            c[i][j] = w[i][j] + c[i][k - 1] + c[k][j];
            r[i][j] = k;
        }
    }

    // Output cost matrix
    cout << "\nCost Matrix (c):" << endl;
    int k=0;//k is used to control starting index of the j in the inner loop
    for (int i = 0; i <= n; i++) 
    {
        for (int j = 0+k; j <= n; j++) 
        {
            cout <<"w["<<i<<"]["<<j<<"]="<<w[i][j] << "\t";
            cout <<"c["<<i<<"]["<<j<<"]="<<c[i][j] << "\t";
            cout <<"r["<<i<<"]["<<j<<"]="<<r[i][j] << "\n";
        }
         k++;
        cout << endl;
    }


    // Optimal cost, weight, and root
    cout << "\nOptimal cost: " << c[0][n] << endl;
    cout << "Weight: " << w[0][n] << endl;
    cout << "Root value: " << r[0][n] << endl;
}

int main() 
{
    float p[]={0,3,3,1,1}, q[]={2,3,1,1,1}, c[10][10];
int n=4;
    // cout << "Enter n: ";
    // cin >> n;

    // cout << "Enter probabilities of successful search:\n";
    // for (int i = 1; i <= n; i++) {
    //     cout << "p[" << i << "] = ";
    //     cin >> p[i];
    // }

    // cout << "Enter probabilities of unsuccessful search:\n";
    // for (int i = 0; i <= n; i++) {
    //     cout << "q[" << i << "] = ";
    //     cin >> q[i];
    // }

    obst(p, q, n);
    return 0;
}
//he outer loop iterates over i, and for each i, the inner loop iterates over j. But, the starting point for j changes with each iteration of the outer loop due to k
//thus for the same k is used as a couter variable
