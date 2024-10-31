#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isUnique(char **board, int row, int col, char num);
bool fillNum(char **board);

void solveSudoku(char **board, int boardSize, int *boardColSize)
{
    fillNum(board);
}

// funciton to check is number is uniaue in row, column and 3x3 sub grid
bool isUnique(char **board, int row, int col, char num)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[row][i] == num)
            return (false);

        if (board[i][col] == num)
            return (false);

        if (board[(row / 3) * 3 + i / 3][(col / 3) * 3 + i % 3] == num)
            return (false);
    }
    return (true);
}

bool fillNum(char **board)
{
    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
        {
            if (board[row][col] == '.')
            {
                // Try placing a number from '1' to '9' in the cell
                for (char num = '1'; num <= '9'; num++)
                {
                    // Check if placing number num in this cell is ok
                    if (isUnique(board, row, col, num))
                    {
                        board[row][col] = num;

                        // Recursive call to keep placing numbers on the board
                        if (fillNum(board))
                        {
                            // When the last cell is filled with a valid number, the board is solved
                            return (true);
                        }
                        // If no numbers placed are valid, reset the current cell to '.'
                        board[row][col] = '.';
                    }
                }
                // False when no numbers placed are valid and triggers the backtracking
                return (false);
            }
        }
    }
    return (true);
}

int main()
{

    //added this function in here because we don't need it in the submission for Leetcode
    void printSolvedBoard(char **board)
    {
        for (int row = 0; row < 9; row++)
        {
            for (int col = 0; col < 9; col++)
            {
                printf("%c ", board[row][col]);
            }
            printf("\n");
        }
    }

    char row0[] = {'5', '3', '.', '.', '7', '.', '.', '.', '.'};
    char row1[] = {'6', '.', '.', '1', '9', '5', '.', '.', '.'};
    char row2[] = {'.', '9', '8', '.', '.', '.', '.', '6', '.'};
    char row3[] = {'8', '.', '.', '.', '6', '.', '.', '.', '3'};
    char row4[] = {'4', '.', '.', '8', '.', '3', '.', '.', '1'};
    char row5[] = {'7', '.', '.', '.', '2', '.', '.', '.', '6'};
    char row6[] = {'.', '6', '.', '.', '.', '.', '2', '8', '.'};
    char row7[] = {'.', '.', '.', '4', '1', '9', '.', '.', '5'};
    char row8[] = {'.', '.', '.', '.', '8', '.', '.', '7', '9'};

    char *board[9] = {row0, row1, row2, row3, row4, row5, row6, row7, row8};

    int boardColSize[9];

    solveSudoku(board, 9, boardColSize);

    printf("Solution:\n");
    printSolvedBoard(board);

    return 0;
}
