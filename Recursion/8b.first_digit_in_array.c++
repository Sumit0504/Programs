#include<iostream>
using namespace std;
int find(int* a, int s, int d)
{
    if(s<=0) return -1;
    if(a[0]==d) return 0;
    int k = find(a+1,s-1,d);
    if(k!=-1) return k+1;
    return -1;
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