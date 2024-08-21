#include<iostream>
using namespace std;

int main()
{
    int a[][4] = {
        {1,3,5,7},
        {2,4,6,8},
        {11,12,13,14}
    };
    int row = sizeof(a)/sizeof(a[0]);
    int col = sizeof(a[0])/sizeof(int);
    for(int j=0; j<col; j++)
    {
        if(j%2==0)
        {
            for(int i=0; i<row; i++)
            {
                cout<<a[i][j]<<" ";
            }
        }
        else
        {
            for(int i=row-1; i>=0; i--)
            {
                cout<<a[i][j]<<" ";
            }
        }
        cout<<endl;
    }
}