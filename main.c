#include <stdio.h>
#include <stdlib.h>

const char padding[4] = "   ";

char board[3][3] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '},
};

char current_player = 'X';

void clear_console()
{
    system("clear || cls");
}

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
    printf("\n%s    1   2   3  ", padding);
    printf("\n%s  +---+---+---+\n", padding);
    for (int i = 0; i < 3; i++)
    {
        printf("%s%d |", padding, i + 1);
        for (int j = 0; j < 3; j++)
        {
            printf("%s|", print_cell(board[i][j]));
        }
        printf("\n%s  +---+---+---+\n", padding);
    }
}

int check_rows()
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2])
        {
            return 1;
        }
    }
    return 0;
}

int check_columns()
{
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i])
        {
            return 1;
        }
    }
    return 0;
}

int check_diagonals()
{
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return 1;
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return 1;
    return 0;
}

int check_win()
{
    return check_columns() || check_rows() || check_diagonals();
}

int check_draw()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
                return 0;
        }
    }
    return 1;
}

void switch_player()
{
    if (current_player == 'X')
        current_player = 'O';
    else
        current_player = 'X';
}

int is_valid_move(int row, int col)
{
    return row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ';
}

void clear_input_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

void reset_game()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
    current_player = 'X';
}

int restart_prompt()
{
    char restart;
    printf("\n%s y for yes, other for no\n%s do you want to restart? ", padding, padding);
    scanf("%c", &restart);

    if (restart == 'y' || restart == 'Y')
    {
        return 1;
    }

    return 0;
}

int main()
{
    clear_console();

    printf("\n");
    printf(" ==================================================================\n");
    printf("  _______ _____ _____   _______       _____   _______ ____  ______ \n");
    printf(" |__   __|_   _/ ____| |__   __|/\\   / ____| |__   __/ __ \\|  ____|\n");
    printf("    | |    | || |         | |  /  \\ | |         | | | |  | | |__   \n");
    printf("    | |    | || |         | | / /\\ \\| |         | | | |  | |  __|  \n");
    printf("    | |   _| || |____     | |/ ____ \\ |____     | | | |__| | |____ \n");
    printf("    |_|  |_____\\_____|    |_/_/    \\_\\_____|    |_|  \\____/|______|\n\n");
    printf(" ==================================================================\n");
    printf("\n\t\t%sThe game will start in 3 seconds%s\t\t\n", padding, padding);
    sleep(3);

    while (1)
    {
        clear_console();
        print_board();

        int row, col;
        printf("\n%sPlayer %c's turn. \n%sEnter your move (row column): ", padding, current_player, padding);
        scanf("%d %d", &row, &col);
        clear_input_buffer();

        row--;
        col--;
        if (is_valid_move(row, col))
        {
            board[row][col] = current_player;
            clear_console();
            print_board();

            if (check_win())
            {
                printf("\n%s  player %c wins\n", padding, current_player);
                int i = restart_prompt();
                if (i)
                {
                    reset_game();
                    continue;
                }
                break;
            }

            if (check_draw())
            {
                printf("\n%s  draw!\n", padding);
                int i = restart_prompt();
                if (i)
                {
                    reset_game();
                    continue;
                }
                break;
            }

            switch_player(current_player);
        }
    }
}
