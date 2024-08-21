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
    int sr=0,sc=0;
    int er = (sizeof(a)/sizeof(a[0]))-1;
    int ec = (sizeof(a[0])/sizeof(int))-1;

    while(sr<=er && sc<=ec)
    {
        for(int col=sc;col<=ec; col++)
        {
            cout<<a[sr][col]<<" ";
        }
        sr++;

        for(int row=sr;row<=er; row++)
        {
            cout<<a[row][ec]<<" ";
        }
        ec--;
        if(er>=sr)
        {
            for(int col=ec;col>=sc; col--)
            {
                cout<<a[er][col]<<" ";
            }
            er--;
        }
        if(ec>=sc)
        {
            for(int row=er;row>=sr; row--)
            {
                cout<<a[row][sc]<<" ";
            }
            sc++;
        }
    }
}