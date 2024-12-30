#include <iostream>
using namespace std;
bool issafe(int i, int j, int n, int board[][10])
{
    for(int k=0; k<i; k++)
    {
        if(board[k][j]) return false;
    }
    int old_i = i;
    int old_j = j;

    while(i>=0 && j>=0)
    {
        if(board[i--][j--]==1) return false;
    }
    i = old_i;
    j = old_j;

    while(i>=0 && j<n)
    {
        if(board[i--][j++]==1) return false;
    }
    return true;
}
bool nqueen(int i, int n, int board[][10])
{
    if(i==n)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
        return true;
    }

    for(int j=0; j<n; j++)
    {
        if(issafe(i, j, n ,board))
        {
            board[i][j]=1;

            bool placed = nqueen(i+1, n, board);
            if(placed) return true;
            board[i][j]=0;
        }
    }
    return false;
}
int main() {
    int board[10][10]={0};
    int n =4;
    nqueen(0, n,board);
    return 0;
}