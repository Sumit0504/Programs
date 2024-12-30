#include<iostream>
using namespace std;

//start from top f(n) = f(n-1) + f(n-2) + f(n-3) for k=3
//k = at a time can jump no. of k steps

int stairs(int n, int k)
{
    if(n==0 || n==1)
    {return 1;}
    if(n<0)
    {return 0;}
    

    //recursive 
    int a=0;
    for(int i=1; i<=k; i++)
    {
        a += stairs(n-i, k);
    }
    return a;

}
int main()
{
    cout<<stairs(4,3);
}