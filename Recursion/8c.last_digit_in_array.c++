#include<iostream>
using namespace std;
int find(int* a, int s, int d)
{
    if(s<=0) return -1;
    if(a[s]==d) return s;
    return find(a,s-1,d);
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
    int d;
    cin>>d;
    cout<<find(a,s-1 ,d);
}