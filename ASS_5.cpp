/*
Name : sakshi
Roll no. : 20
Class : TY-A
Assignment 7 : Develop a program to implement 0/1 Knapsack problem using Dynamic Programming.*/
#include<iostream>
using namespace std;
class knapsack
{
    public :
            void tabular(int p[],int w[],int n,int m)
            {
                int table[51][51]={0};
                for(int i=1;i<=n;i++)
                {
                    for(int j=1;j<=m;j++)
                    {
                        if(w[i-1] <= j)
                        
                        
                        
                        {
                            table[i][j]=max(p[i-1]+table[i-1][j-w[i-1]],table[i-1][j]);
                        }
                        else
                        {
                            table[i][j]=table[i-1][j];
                        }
                    }
                }
                cout<<"Tabular Form :\n";
                cout<<"----------------------------------------------------------------\n\t|\t";
                for(int i=0;i<=m;i++)
                {
                    cout<<i<<"\t|\t";
                }
                cout<<"\n----------------------------------------------------------------\n";
                for(int i=0;i<=n;i++)
                {
                    cout<<i<<"\t|\t";
                    for(int j=0;j<=m;j++)
                    {
                        cout<<table[i][j]<<"\t|\t";
                    }
                    cout<<endl;
                }
                cout<<"-----------------------------------------------------------------\n";
                printselected(p,w,table,n,m);
            }
            void printselected(int p[],int w[],int table[][51],int n,int m)
            {
                int selected[50]={0};
                int i=n,j=m;
                while(i>0 && j>0)
                {
                    if(table[i][j] != table[i-1][j])
                    {
                        selected[i-1]=1;
                        j=j-w[i-1];
                    }
                    i--;
                }
                cout<<"Selected items(index starting from 1) : ";
                int totalprofit=0;
                for(i=0;i<n;i++)
                {
                    if(selected[i]==1)
                    {
                        cout<<i+1<<"\t";
                        totalprofit+=p[i];
                    }
                }
                cout<<"\nTotal Profit : "<<totalprofit<<endl;
            }
};
int main()
{
    knapsack k;
    int p[20],w[20],n,m,i,j;
    cout<<"Enter the size : ";
    cin>>n;
    cout<<"Enter the capacity : ";
    cin>>m;
    cout<<"Enter the profit :\n";
    for(i=0;i<n;i++)
    {
        cout<<"p["<<i+1<<"] : ";
        cin>>p[i];
    }
    cout<<"Enter the weight :\n";
    for(i=0;i<n;i++)
    {
        cout<<"w["<<i+1<<"] : ";
        cin>>w[i];
    }
    k.tabular(p,w,n,m);
    return 0;
}
/*OUTPUT : 
Enter the size : 3
Enter the capacity : 6
Enter the profit :
p[1] : 1
p[2] : 2
p[3] : 5
Enter the weight :
w[1] : 2
w[2] : 3
w[3] : 4
Tabular Form :
----------------------------------------------------------------
	|	0	|	1	|	2	|	3	|	4	|	5	|	6	|	
----------------------------------------------------------------
0	|	0	|	0	|	0	|	0	|	0	|	0	|	0	|	
1	|	0	|	0	|	1	|	1	|	1	|	1	|	1	|	
2	|	0	|	0	|	1	|	2	|	2	|	3	|	3	|	
3	|	0	|	0	|	1	|	2	|	5	|	5	|	6	|	
-----------------------------------------------------------------
Selected items(index starting from 1) : 1	3	
Total Profit : 6

=== Code Execution Successful ===*/
