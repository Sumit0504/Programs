#include<iostream>
#include<cstring>
using namespace std;
// Top down approach
int fibbo_t_d(int n, int *dp)
{
    if(n==0 || n==1)
    {
        dp[n] = n; // return se pehle store
        return n;
    }
    //check if already exists in aray or not
    if(dp[n] != -1)
    {
        return dp[n];
    }

    return dp[n] = fibbo_t_d(n-1, dp) + fibbo_t_d(n-2, dp);
}
// bottom up approach
int fibbo_b_u(int n)
{
    int dp[1000];
    // base case become initialisation
    dp[0] = 0;
    dp[1] = 1;

    for(int i=2; i<=n; i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}
int main()
{
    int n;
    cout<<"enter n: ";
    cin>>n;
    int dp[100];
    memset(dp, -1, sizeof dp);
    cout<<"Using Top Down: "<<fibbo_t_d(n,dp)<<endl;

    for(int i=0; i<=n; i++)
    {
        cout<<dp[i]<<" ";
    }
cout<<endl<<"Using Bottom Up: "<<fibbo_b_u(n)<<endl;
}