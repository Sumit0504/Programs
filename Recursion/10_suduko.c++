#include<iostream>
using namespace std;
bool issafe(int i, int j, int board[][9], int n, int num)
{
    for(int k=0; k<n; k++)
    {
        if(board[i][k]==num || board[k][j]==num )
        {
            return false;
        }
    }
    int si = (i/3)*3;
    int sj = (j/3)*3;

    for(int m = si; m<si+3; m++)
    {
        for(int n = sj; n<sj+3; n++)
        {
            if(board[m][n]==num)
                return false;
        }    
    }
    return true;
}
bool suduko(int i, int j, int board[][9], int n)
{
    //base
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
    //corners
    if(j==n)
    {
        return suduko(i+1, 0,board, n);   
    }
    if(board[i][j]!=0)
    {
        return suduko(i, j+1,board, n);
    }
    //recursive
    for(int num = 1; num<=n; num++)
    {
        if(issafe(i, j, board, n, num))
        {
            board[i][j] = num;
            if(suduko(i, j+1,board, n)) return true;
        }
        board[i][j]=0;
    }
    return false;
}

int main()
{
    int board[9][9] ={
        {0, 0, 0, 0, 8, 0, 2, 0, 0},
		{0, 6, 9, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 3, 0, 0, 0, 0},
		{0, 0, 0, 4, 0, 0, 0, 9, 7},
		{5, 0, 0, 0, 0, 0, 3, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 6, 0},
		{0, 0, 0, 6, 0, 7, 0, 4, 0},
		{8, 0, 0, 0, 0, 0, 5, 0, 0},
		{0, 0, 0, 9, 0, 0, 0, 0, 0}
    };
    suduko(0, 0,board, 9);
}