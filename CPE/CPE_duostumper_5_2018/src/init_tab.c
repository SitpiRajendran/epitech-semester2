/*
** EPITECH PROJECT, 2019
** CPE Duostumper 5
** File description:
** Init tab for game
*/

#include <tictactoe.h>

char **init_tab(int size)
{
    char **tab = malloc(sizeof(char *) * (size + 1));

    if (tab == NULL)
        exit (84);

    for (int i = 0; i != size; i++) {
        if ((tab[i] = malloc(sizeof(char) * (size + 1))) == NULL)
            exit (84);
        for (int j = 0; j != size; j++)
            tab[i][j] = ' ';
        tab[i][size] = '\0';
    }

    return tab;
}
