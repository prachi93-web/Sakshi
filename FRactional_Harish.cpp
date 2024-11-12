#include<iostream>
using namespace std;
int main()
{
    int n,m,cnt=0,val;
    float frac,sw=0,sp=0;
    cout<<"Enter the number of items: ";
    cin>>n;
    cout<<"Enter the capacity of knapsack : ";
    cin>>m;
    float v[n],w[n],it[n],r[n],s[n];//s[n] which stores the selected item to be put into the knapsack
    //
    cout<<"Enter the values and weight for following items."<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"Value of item "<<i+1<<" : "<<endl;
        cin>>v[i];
        cout<<"Weight of item "<<i+1<<" : "<<endl;
        cin>>w[i];
    }
    cout<<"Step 1: Calculate the ratio of value and weight."<<endl;
    for(int i=0;i<n;i++)
    {
        it[i]=i+1;
        r[i]=v[i]/w[i];
    }
    //Display table..
    cout<<"Displaying Table"<<endl<<endl;
    cout<<"Items\tValues\tWeights\tRatio"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"Item"<<it[i]<<"\t"<<v[i]<<"\t"<<w[i]<<"\t"<<r[i]<<endl;
    }

    cout<<"Step 2: Arrange the table in decreasing ratio."<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(r[i]>r[j])
            {
                swap(w[i],w[j]);
                swap(v[i],v[j]);
                swap(it[i],it[j]);
                swap(r[i],r[j]);
            }
        }
    }
    //Display table....
     cout<<"Displaying Table"<<endl<<endl;
    cout<<"Items\tValues\tWeights\tRatio"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"Item"<<it[i]<<"\t"<<v[i]<<"\t"<<w[i]<<"\t"<<r[i]<<endl;
    }

    cout<<"Step 3: Finding the required values."<<endl;
    for(int i=0;i<n;i++)
    {
        int sum;
        sum = sw+w[i];
        if(sum<=m)
        {
            sw=sw+w[i];
            sp=sp+v[i];
            s[cnt]=it[i];//stores item number inselected item array
            cnt++;//increases counter for number of selected itemms
            //s[0] = it[0] = 1  // First item selected
			//cnt = 1 and soo on
        }
        else {
            val=m-sw;
            frac= (val /w[i])*v[i]);
            sp=sp+frac;
            s[cnt]=it[i];
            cnt++;
            break;
        }
    }
    cout<<"Items selected are {";
    for(int i=0;i<cnt;i++)
    {
        cout<<"Item "<<s[i]<<"  ";
    }
    cout<<"}."<<endl;
    cout<<"Weight in knapsack is : "<<sw<<endl;
    cout<<"Profit obtained is : "<<sp<<endl;


}

