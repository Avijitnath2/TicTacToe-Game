#include <iostream>
using namespace std;
bool wincondition(char board[3][3], char val, int row, int col)
{
    int count = 0;
    // rowcondition
    for (int i = 0; i < 3; i++)
    {
        if (board[row][i] == val)
        {
            count++;
        }
        else
        {
            count = 0;
            break;
        }
        if (count == 3)
        {
            return true;
        }
    }
    // column condition
    for (int i = 0; i < 3; i++)
    {
        if (board[i][col] == val)
        {
            count++;
        }
        else
        {
            count = 0;
            break;
        }
        if (count == 3)
        {
            return true;
        }
    }
    // diagonal condition
    for (int i = 0; i < 3; i++)
    {
        if (board[i][i] == val)
        {
            count++;
        }
        else
        {
            count = 0;
            break;
        }
        if (count == 3)
        {
            return true;
        }
    }
    // rev diagonal condition
    if (board[0][2] == val && board[1][1] == val && board[2][0] == val)
    {
        return true;
    }
    return false;
}
bool drawcondition(char board[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
            {
                return false;
            }
        }
    }
    return true;
}
// print the board
void showboard(char board[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        cout << board[i][0] << "|" << board[i][1] << "|" << board[i][2] << endl;
        if (i == 2)
        {
            continue;
        }
        cout << "-|-|-" << endl;
    }
}
int main()
{
    char board[3][3] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    int row, col;
    int move = 1;
    cout << "--------TICTACTOE--------" << endl;
    char player;
    cout << endl;
    while (1)
    {
        cout << "Enter your position - " << endl;
        if (move % 2 == 1)
        {
            player = 'X';
        }
        else
        {
            player = 'O';
        }
        cout << "Player " << player << ": ";
        while (1)
        {
            cin >> row >> col;
            if (board[row][col] != ' ')
            {
                cout << "Already a value exists there! Please select a new position! " << endl;
            }
            else
            {
                break;
            }
        }
        if (move % 2 == 1)
        {
            board[row][col] = player;
        }
        else
        {
            board[row][col] = player;
        }
        showboard(board);
        if (wincondition(board, player, row, col))
        {
            cout << "Player " << player << " win!!" << endl;
            break;
        }
        if (drawcondition(board))
        {
            cout << "It is a Draw!!";
            break;
        }
        move++;
    }
    return 0;
}