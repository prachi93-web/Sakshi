#include<iostream>
using namespace std;

class knapsack 
{
    public:
    void demo(int n, int m, int profit[], int weight[]) 
    {
        int table[n+1][m+1];
        for (int i = 0; i <= n; i++) 
        {
            for (int j = 0; j <= m; j++) 
            {
                if (i == 0 || j == 0) 
                {
                    table[i][j] = 0; 
                } 
                else if (weight[i-1] <= j) 
                {
                                                               
                    table[i][j] = max(profit[i-1] + table[i-1][j-weight[i-1]], table[i-1][j]);
                } 
                else 
                {
                    table[i][j] = table[i-1][j];
                }
            }
        }
        cout<<"Tabular form : \n\t";
        for(int j = 0; j <= m; j++)
        {
            cout<<j<<"\t";
        }
        cout<<endl;
        cout<<"------------------------------------------------------------------\n";
        for (int i = 0; i <= n; i++) 
        {
            cout<<i<<"\t|\t";
            for (int j = 0; j <= m; j++) 
            {
                cout<<table[i][j]<<"\t";
            }
            cout<<endl;
        }
        cout<<"-------------------------------------------------------------------\n";
        cout << "\nMaximum profit gain from knapsack: " << table[n][m] << endl;
    }
};

int main() 
{
    int n, m;
    cout << "\nEnter the number of objects: ";
    cin >> n;
    cout << "\nEnter the capacity of knapsack: ";
    cin >> m;	

    int profit[n], weight[n];
    for (int i = 0; i < n; i++) {
        cout << "\nEnter the profit of object " << i+1 << " : ";
        cin >> profit[i];
        cout << "\nEnter the weight of object " << i+1 << " : ";
        cin >> weight[i];
    }

    knapsack obj;
    obj.demo(n, m, profit, weight);
    return 0;
}
