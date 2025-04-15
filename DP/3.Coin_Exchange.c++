#include<iostream>
#include<cstring>
using namespace std;

int exchange_r(int amt, int *arr, int n)
{
    // base
    if(amt ==0 ) return 0;

    // recursive
    int ans = INT_MAX;
    for(int i=0; i<n; i++)
    {
        if(amt >= arr[i])
        {
            int new_amt = amt - arr[i];
            int x = exchange_r(new_amt, arr, n);
            if(x != INT_MAX) // because INT_MAX + 1 = INT_MIN as it is circular array
            ans = min(ans, x+1);
        }       
    }
    return ans;
}

//Top down approach
int exchange_t_d(int amt, int *arr, int n, int *dp)
{
    // base
    if(amt ==0 ) 
    {
        dp[amt] = amt;
        return 0;
    }

    
    //check before calculations
    if(dp[amt] != -1)
    {
        return dp[amt];
    }
    // recursive
    int ans = INT_MAX;
    for(int i=0; i<n; i++)
    {
        if(amt >= arr[i])
        {
            int new_amt = amt - arr[i];
            int x = exchange_t_d(new_amt, arr, n, dp);
            if(x != INT_MAX) // because INT_MAX + 1 = INT_MIN as it is circular array
            ans = min(ans, x+1);
        }       
    }
    // store before return
    return dp[amt] = ans;
}
int exchange_b_u(int amt, int *arr, int n)
{
    int dp[1000];
    // base
    if(amt ==0 ) 
    {
        dp[amt] = amt;
        return 0;
    }

    
    //check before calculations
    if(dp[amt] != -1)
    {
        return dp[amt];
    }
    // recursive
    int ans = INT_MAX;
    for(int i=0; i<n; i++)
    {
        if(amt >= arr[i])
        {
            int new_amt = amt - arr[i];
            int x = exchange_t_d(new_amt, arr, n, dp);
            if(x != INT_MAX) // because INT_MAX + 1 = INT_MIN as it is circular array
            ans = min(ans, x+1);
        }       
    }
    // store before return
    return dp[amt] = ans;
}

int main()
{
    int coins[100];
    int amt;
    cin>>amt;
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>coins[i];
    }
    int dp[1000];
    memset(dp, -1, sizeof dp);
    cout<<"Using recursive: "<<exchange_r(amt, coins, n)<<endl;
    cout<<"Using Top Down: "<<exchange_t_d(amt, coins, n, dp)<<endl;

}