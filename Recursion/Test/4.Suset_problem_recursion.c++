#include<iostream>
using namespace std;
void count(int l);

void subset(int *arr, int n, int t,int i)
{
    //Base
    if(i==n)
    {
        return;
    }
    //Recursive
    if(arr[i]==t)
    {cout<<arr[i]<<"  ";}

    for(int j=i+1; j<n; j++)
    {
        if(arr[i]+arr[j]==t && arr[i]>arr[j])
        {cout<<arr[j]<<" "<<arr[i]<<"  ";}
        if(arr[i]+arr[j]==t && arr[j]>arr[i])
        {cout<<arr[i]<<" "<<arr[j]<<"  ";}
    }
    for(int j=i+1; j<n; j++)
    {
        for(int k=0;k<n && arr[k]!=arr[j] && arr[k]!=arr[i] ;k++)
        {
            if(t-(arr[i]+arr[j])==arr[k]&& arr[i]>arr[j]&& arr[j]>arr[k])
            {
                cout<<arr[k]<<" "<<arr[j]<<" "<<arr[i]<<"  ";
            }
            else if(t-(arr[i]+arr[j])==arr[k]&& arr[i]>arr[j]&& arr[j]<arr[k] && arr[i]>arr[k] )
            {
                cout<<arr[j]<<" "<<arr[k]<<" "<<arr[i]<<"  ";
            }
            else if(t-(arr[i]+arr[j])==arr[k]&& arr[i]>arr[j]&& arr[j]<arr[k] && arr[i]<arr[k] )
            {
                cout<<arr[j]<<" "<<arr[i]<<" "<<arr[k]<<"  ";
            }
            else if(t-(arr[i]+arr[j])==arr[k]&& arr[i]<arr[j]&& arr[j]<arr[k])
            {
                cout<<arr[i]<<" "<<arr[j]<<" "<<arr[k]<<"  ";
            }
            else if(t-(arr[i]+arr[j])==arr[k]&& arr[i]<arr[j]&& arr[j]>arr[k]&& arr[i]>arr[k])
            {
                cout<<arr[k]<<" "<<arr[i]<<" "<<arr[j]<<"  ";
            }
            else if(t-(arr[i]+arr[j])==arr[k]&& arr[i]<arr[j]&& arr[j]>arr[k]&& arr[i]<arr[k])
            {
                cout<<arr[i]<<" "<<arr[k]<<" "<<arr[j]<<"  ";
            }
        }
    }
    subset(arr,n,t,i+1);
}
int main()
{
    //number of elements
    int n;
    cin>>n;
    //array
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    //target sum
    int t;
    cin>>t;
    subset(arr,n,t,0);
}