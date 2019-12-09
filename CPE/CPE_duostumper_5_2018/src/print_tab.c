/*
** EPITECH PROJECT, 2019
** CPE Duostumper 5
** File description:
** Print tab for game
*/

#include "tictactoe.h"

void print_tab(char **tab, int size)
{
    int x = 0;
    int i = 0;

    write(1, "+", 1);
    for (; i != size; i++)
        write(1, "-", 1);
    write(1, "+\n",2);
    for (; tab[x] != NULL; x++) {
        write(1, "|", 1);
        write(1, tab[x], strlen(tab[x]));
        write(1, "|\n", 2);
    }
    write(1, "+", 1);
    for (i = 0; i != size; i++)
        write(1, "-", 1);
    write(1, "+\n", 2);
}
