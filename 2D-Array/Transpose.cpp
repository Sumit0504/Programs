#include<iostream>
using namespace std;

int main()
{
    int a[][4]={
    {1,2,3,4},
    {5,6,7,8},
    {9,10,11,12},
    {13,14,15,16}
    };
    int row = sizeof(a)/sizeof(a[0]);
    int col = sizeof(a[0])/sizeof(int);

    for(int i=0; i<row; i++)
    {
        for(int j=i+1; j<col; j++)
        {
            swap(a[i][j],a[j][i]);
        }
    }
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}