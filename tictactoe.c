#include <stdio.h>

int wincondition(char board[3][3], char val, int row, int col)
{
    // rowcondition
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == val && board[i][1] == val && board[i][2] == val)
        {
            return 1;
        }
    }
    // column condition
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == val && board[1][i] == val && board[2][i] == val)
        {
            return 1;
        }
    }
    // diagonal condition
    if (board[0][0] == val && board[1][1] == val && board[2][2] == val)
    {
        return 1;
    }

    // rev diagonal condition
    if (board[0][2] == val && board[1][1] == val && board[2][0] == val)
    {
        return 1;
    }
    return 0;
}
int drawcondition(char board[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
            {
                return 0;
            }
        }
    }
    return 1;
}
// print the board
void showboard(char board[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf(" %c ", board[i][j]);
            if (j < 2)
            {
                printf("|");
            }
        }
        printf("\n");
        if (i < 2)
        {
            printf("---+---+---\n");
        }
    }
}
int main()
{
    char board[3][3] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    int row, col;
    int move = 1;
    printf("--------TICTACTOE--------");
    char player;
    printf("\n");
    while (1)
    {
        printf("Enter your position - \n");
        if (move % 2 == 1)
        {
            player = 'X';
        }
        else
        {
            player = 'O';
        }
        printf("Player %c : ", player);
        while (1)
        {
            scanf("%d%d", &row, &col);
            if (board[row][col] != ' ')
            {
                printf("Invalid Move! ");
            }
            else
            {
                break;
            }
        }
        board[row][col] = player;
        showboard(board);
        if (wincondition(board, player, row, col))
        {
            printf("Player %c win!!\n", player);
            break;
        }
        if (drawcondition(board))
        {
            printf(" It is a Draw !!");
            break;
        }
        move++;
    }
    return 0;
}