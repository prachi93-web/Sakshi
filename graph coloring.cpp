#include<iostream>
using namespace std;
bool safe(int node,int graph[10][10],int color[10],int M,int n,int acolor)//used to chack whether to assign a particualer color to the current node
{
for(int i=0;i<n;i++)
{
if(graph[node][i]==1 && color[i]==acolor)

{
return false;
}
}
return true;
}
bool graphs(int node,int color[10],int graph[10][10],int M,int n)
{
if(node==n)//if all nodes are successfully colored without any conflict
{
return true;
}
for(int acolor=1;acolor<=M;acolor++)//This loop tries assigning each color to each an devery node
{
if(safe(node,graph,color,M,n,acolor))//chwcks whethr color assignment is safe and valid.
{
color[node]=acolor;
if(graphs(node+1,color,graph,M,n))//After assigning the color to
// the current node, the function recursively calls itself with the next node (node + 1).
// This process continues until all nodes are colored.
{
return true;
}
color[node]=0;//backtrack
}
}
return false;//otherwise it will return false until no color is found
}
bool colorgraph(int graph[10][10],int M,int n,int color[10])//he function colorgraph serves as the initial entry point for solving the graph coloring problem.
{
color[n]={0};//bcz no color is assigned yet
if(graphs(0,color,graph,M,n))
{
return true;
}
return false;
}
int main(){
int n,M;
cout<<"Enter the number of vertices:";
cin>>n;
M=n-1;
int graph[10][10];
cout<<"Enter the value in adjacency matrix if edge is present assign 1 else 0";
for(int i=0;i<n;i++)
{
for(int j=0;j<n;j++)
{
cout<<"Value in matrix for "<<i<<" and "<<j<<" : ";
cin>>graph[i][j];
}
}
int color[10];
if(colorgraph(graph,M,n,color))
{
cout<<"\nSolution Exist\n";
for(int i=0;i<n;i++)
{
cout<<"Vertex: "<<i+1<<"color "<<color[i]<<endl;
}
}
else
{
cout<<"Solution do not exist";
}
return 0;
}





