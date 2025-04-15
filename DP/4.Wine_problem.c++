#include<iostream>
using namespace std;

// wine_r is recursive approach 
int wine_r(int *wine, int l, int r, int day)
{
    // Base case
    if(l>r)
    {
        return 0;
    }

    int op1 = wine[l]*day + wine_r(wine, l+1, r, day+1);
    int op2 = wine[r]*day + wine_r(wine, l, r-1, day+1);

    return max(op1, op2);
}

// wine_t_d is top down approach 
int wine_t_d(int *wine, int l, int r, int day, int dp[][100])
{
    // Base case
    if(l>r)
    {
        return 0;
    }
    if(dp[l][r] != -1)
    {
        return dp[l][r];
    }
    int op1 = wine[l]*day + wine_t_d(wine, l+1, r, day+1, dp);
    int op2 = wine[r]*day + wine_t_d(wine, l, r-1, day+1, dp);

    return dp[l][r] = max(op1, op2);
}

// wine_b_u is top down approach 
int wine_b_u(int *wine, int n)
{
    int dp[100][100]= {0};

    for(int l=n-1; l>=0; l--)
    {
        for(int r =l; r<n; r++)
        {
            int day = n-(r-l);
            int op1 = wine[l]*day + ((l+1 < n) ? dp[l+1][r] : 0) ; // ternary opeartor
            int op2 = wine[r]*day + ((r-1 >= 0) ? dp[l][r-1] : 0);        
            dp[l][r] = max(op1, op2);
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n ;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[0][n-1];
}

int main()
{
    int wine[] = {2, 5, 1, 3, 4};
    int n = sizeof(wine)/sizeof(wine[0]);
    int dp[100][100];
    memset(dp, -1, sizeof(dp));
    wine_t_d(wine, 0, n-1, 1, dp);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n ;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<"bottom:"<<wine_b_u(wine, n);
    // cout<<"profit after selling the wine is: "<<;
}