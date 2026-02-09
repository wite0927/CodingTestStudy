// B 2239
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int N, S, D;
vector<vector<int>> board(9, vector<int>(9, 0));

bool is_valid(int row, int col, int num)
{
    for(int i = 0; i < 9; i++)
    {
        if(board[row][i] == num || board[i][col] == num)
        {
            return false;
        }
    }

    int S_row = row - row % 3;
    int S_col = col - col % 3;
    for(int i = 0; i < 3; i++)
    {
        for(int j =0; j<3; j++)
        {
            if(board[S_row + i][S_col + j] == num)
            {
                return false;
            }
        }
    }

    return true;
}

pair<int,int> find_empty()
{
    for(int i = 0; i < 9; i++)
    {
        for(int j =0; j<9; j++)
        {
            if(board[i][j] == 0)
            {
                return {i,j};
            }
        }
    }
    return {-1,-1};
}

void Sudoku()
{
    pair<int, int> pos = find_empty();
    if(pos.first == -1)
    {
        return;
    }

    for(int i = 1; i <= 9; i++)
    {
        if(is_valid(pos.first, pos.second, i))
        {
            board[pos.first][pos.second] = i;
            Sudoku();
            if(find_empty().first == -1)
                return;
            board[pos.first][pos.second] = 0;
        }
    }
}

int main()
{
    for(int i = 0; i < 9; i++)
    {
        string s; cin>>s;
        for(int j =0; j< 9; j++) board[i][j] = s[j] - '0';
    }

    Sudoku();

    for(int i = 0; i < 9; i++)
    {
        for(int j =0; j<9; j++)
        {
            cout << board[i][j];
        }
        cout << "\n";
    }
}