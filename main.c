#include <stdio.h>

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

int main()
{
    printf("hello world\n");
}
