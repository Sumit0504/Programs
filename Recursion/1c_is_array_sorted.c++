#include<iostream>
using namespace std;

bool is_array_sorted(int *a, int n)
{
    if(n==1)
    {
        return true;
    }
    if(a[0]<=a[1] && is_array_sorted(a+1,n-1))
    {
        return true;
    }
    return false;
}
int main()
{
    int a[]={5, 6, 7, 8, 9};
    int n = sizeof(a)/sizeof(int);

    if(is_array_sorted(a,n))
    {
        cout<<"Sorted\n";
    }
    else
    {
        cout<<"Not sorted";
    }
}