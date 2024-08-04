//max sum of subarray using single loop

#include<iostream>
using namespace std;

int main()
{
    int a[]={1, 4, 3, -10, 2, 6, 8, -4, 5, 7};
    int n = sizeof(a)/sizeof(int);
    int sum=0, ans=0;
    for(int i=0; i<n ;i++)
    {
       sum +=a[i];
       if(sum>ans)
       {
        ans = sum;
       } 
       if(sum <0)
       {
        sum =0;
       }

    }
    cout<<ans;
}