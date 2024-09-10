#include<iostream>
using namespace std;
bool is_array_sorted(int *a, int i, int n)
{
    if(i==n-1)
    {
        return true;
    }

    if(a[i]<=a[i+1] && is_array_sorted(a,i+1,n))
    {
        return true;
    }
    return false;
}
int main()
{
    int a[]={5, 6, 7, 8, 9};
    int n = sizeof(a)/sizeof(int);

    if(is_array_sorted(a,0,n))
    {
        cout<<"Sorted\n";
    }
    else
    {
        cout<<"Not sorted";
    }
}