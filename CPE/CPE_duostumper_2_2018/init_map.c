/*
** EPITECH PROJECT, 2019
** duo stumper
** File description:
** initialize map
*/

#include "my.h"

char **init_map(int x, int y)
{
    char **board = malloc(sizeof(char *) * (x + 1));

    for (int i = 0; i < x; i++) {
        board[i] = malloc(sizeof(char) * (y + 1));
        for (int a = 0; a < y; a++)
            board[i][a] = '.';
    }
    return (board);
}

void print_map(char **board, int x, int y)
{
    for (int j = 0; j < y + 2; j++)
        printf("+");
    printf("\n");
    for (int i = 0; i < x; i++)
        printf("|%s|\n", board[i]);
    for (int k = 0; k < y + 2; k++)
        printf("+");
    printf("\n");
}
