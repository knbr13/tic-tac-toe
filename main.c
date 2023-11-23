#include <stdio.h>

const char padding[5] = "    ";

const char board[3][3] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '},
};

const char *print_cell(const char c)
{
    switch (c)
    {
    case 'X':
        return " X ";
        break;
    case 'O':
        return " O ";
        break;
    default:
        return "   ";
    }
}

void print_board()
{
    printf("\n%s+---+---+---+\n", padding);
    for (int i = 0; i < 3; i++)
    {
        printf("%s|", padding);
        for (int j = 0; j < 3; j++)
        {
            printf("%s|", print_cell(board[i][j]));
        }
        printf("\n%s+---+---+---+\n", padding);
    }
}

int main()
{
    printf("hello world\n");
}
