#include<iostream>
using namespace std;

int min_cost_path(int a[][4], int i, int j, int n)
{
    // Base case
    if(i == n-1 && j ==n-1)
    {
        return a[i][j];
    }

    if(i>=n || j>=n)
    {
        return INT_MAX;
    }

    int right = min_cost_path(a, i, j+1, n);
    int left = min_cost_path(a, i+1, j, n);

    return a[i][j] + min(right , left);
}

int min_cost_path_t_d(int a[][4], int i, int j, int n, int dp[][100])
{
    // Base case
    if(i == n-1 && j ==n-1)
    {
        return dp[i][j] = a[i][j];
    }

    if(i>=n || j>=n)
    {
        return INT_MAX;
    }

    if(dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int right = min_cost_path(a, i, j+1, n);
    int left = min_cost_path(a, i+1, j, n);

    return dp[i][j] = a[i][j] + min(right , left);
}
int main()
{
    int a[][4] = {
        {1, 1, 3, 8},
        {2, 1, 1, 9},
        {3 , 5, 1, 1},
        {4, 8, 6, 1}
    };
    int dp[100][100];
    memset(dp, -1, sizeof(dp));
    int n= 4;
    cout<<min_cost_path(a, 0, 0, n)<<endl;

    cout<<min_cost_path_t_d(a, 0, 0, n, dp);
}