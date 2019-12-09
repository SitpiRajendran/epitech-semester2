/*
** EPITECH PROJECT, 2019
** PSU Tetris
** File description:
** Game laucnh
*/

#include "tetris.h"

char **strtoarr(int lines, int cols)
{
    int k = 0;
    char **arr = malloc(sizeof(char *) * (lines + 1));

    if (arr == NULL)
        exit(84);
    for (int i = 0; i < lines; i++) {
        if ((arr[i] = malloc(sizeof(char) * (cols + 1))) == NULL)
            exit(84);
    }
    for (int j = 0; j < lines; j++)
        for (int i = 0; i < cols; i++)
            arr[j][i] = ' ';
    return (arr);
}

void print_game(t_params *game, char **arr)
{
    for (int i = 0; i < game->cols + 2; i++)
        printw("-");
    for (int i = 0; i < game->rows; i++)
        printw("\n|%s|", arr[i]);
    printw("\n");
    for (int i = 0; i < game->cols + 2; i++)
       printw("-");
}

void window_size(t_params *game)
{
    while (game->cols > COLS || game->rows > LINES) {
        clear();
        mvprintw(LINES / 2 , (COLS / 2) - 9, "Resize the window");
        refresh();
    }
}
void gamelaunch(t_params *game)
{
    char **arr = strtoarr(game->rows, game->cols);

    initscr();
    keypad(stdscr, true);
    while (1) {
        window_size(game);
        clear();
        print_game(game, arr);
        refresh();
        getch();
    }
}
