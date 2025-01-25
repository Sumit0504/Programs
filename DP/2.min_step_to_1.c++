#include<iostream>
#include<cstring>
using namespace std;
int stepto_1_r(int n)
{
    // base
    if(n==1)
    {
        return 0;
    }
    // Recursive 
    int op1, op2, op3;
    op1 = op2 = op3 = INT_MAX;
    if(n%3 == 0)
    {
        op1 = stepto_1_r(n/3);
    }
    if(n%2 == 0)
    {
        op2 = stepto_1_r(n/2);
    }
    
    op3 = stepto_1_r(n-1);

    return min(min(op1,op2),op3)+1;
}
int stepto_1_t_d(int n, int *dp)
{
    if(n==1)
    {
        dp[n] = n;
        return 0;
    }

    int op1, op2, op3;
    op1 = op2 = op3 = INT_MAX;
    if(n%3 == 0)
    {
        op1 = stepto_1_t_d(n/3, dp);
    }
    if(n%2 == 0)
    {
        op2 = stepto_1_t_d(n/2, dp);
    }
    
    op3 = stepto_1_t_d(n-1, dp);
    if(dp[n] != -1)
    {
        return dp[n];
    }
    return dp[n] = min(min(op1,op2),op3)+1;
}

int stepto_1_b_u(int n)
{
    int dp[1000];
    
        dp[1] = 0;

    int op1, op2, op3;
    op1 = op2 = op3 = INT_MAX;
    for(int i=2 ;i<=n; i++)
    {
        if(i%3 == 0)
        {
            op1 = dp[i/3];
        }
        if(n%2 == 0)
        {
            op2 = dp[i/2];
        }
    
        op3 = dp[i-1];
        dp[i] = min(min(op1,op2),op3)+1;
    }
    
    return dp[n];
}
int main()
{
    int n;
    cout<<"enter n: ";
    cin>>n;
    cout<<"Using Recursive: "<<stepto_1_r(n)<<endl;

    int dp[1000];
    memset(dp, -1, sizeof dp);
    cout<<"Using Top Down: "<<stepto_1_t_d(n,dp)<<endl;

    cout<<"Using Bottom Up: "<<stepto_1_b_u(n)<<endl;
}