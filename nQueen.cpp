#include<bits/stdc++.h>
using namespace std;
#define MAX 30
int solutions = 0;
bool found = false;
char board[MAX][MAX];
void nQueens(int row, int n);
bool isSafe(int row, int col, int n);
int main()
{
    int n;
    cout << "Enter number of Queens: ";
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            board[i][j] = '.';
        }
    }
    int row = 0;
    nQueens(row, n);
    if(!found)
    {
        cout << "No solution exists.\n";
    }
    return 0;
}
void nQueens(int row, int n)
{
    if(row == n)
    {
        found = true;
        /*solutions++;
        cout << "Solution: " << solutions << '\n';*/
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cout << board[i][j] << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
        return;
    }
    for(int col = 0; col < n; col++)
    {
        if(isSafe(row, col, n))
        {
            board[row][col] = 'Q';
            nQueens(row + 1, n);
            if(found)
            {
                return;
            }
            board[row][col] = '.';
        }
    }
}
bool isSafe(int row, int col, int n)
{
    for(int i = 0; i < n; i++)
    {
        if(board[row][i] == 'Q')
        {
            return false;
        }
    }
    for(int i = 0; i < n; i++)
    {
        if(board[i][col] == 'Q')
        {
            return false;
        }
    }
    for(int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if(board[i][j] == 'Q')
        {
            return false;
        }
    }
    for(int i = row, j = col; i >= 0 && j < n; i--, j++)
    {
        if(board[i][j] == 'Q')
        {
            return false;
        }
    }
    return true;
}