#include<iostream>
using namespace std;

bool  is_sorted_array(int *a, int n)
{
    if(n==0)
    {
        return true;
    }

    if(a[n-1]>=a[n-2] && is_sorted_array(a,n-1))
    {
        return true;
    }
    return false;
}
int main()
{
    int a[]={8, 2, 5, 1, 3, 4};
    int n = sizeof(a)/sizeof(int);

    if(is_sorted_array(a,n))
    {
        cout<<"Sorted\n";
    }
    else
    {
        cout<<"Not sorted";
    }
}