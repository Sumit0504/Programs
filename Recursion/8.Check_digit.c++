#include<iostream>
using namespace std;
bool find(int* a, int s, int n)
{
    if(s<0)
    {
        return false;
    }

    if(a[0]==n)
    {
        return true;
    }
    return find(a+1,s-1,n);
}
int main()
{
    int s;
    cin>>s;
    int *a = new int[s];
    for(int i=0; i<s; i++)
    {
        cin>>a[i];
    }
    int n;
    cin>>n;
    cout<<find(a,s-1,n);
}