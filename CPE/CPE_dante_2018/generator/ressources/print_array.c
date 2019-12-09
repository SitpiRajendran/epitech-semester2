/*
** EPITECH PROJECT, 2019
** print_array.c
** File description:
** print_array.c
*/

#include "generator.h"

void print_array(char **tab)
{
    if (tab == NULL)
        return;
    for (int i = 0; tab[i] != NULL; i++) {
        write(1, tab[i], strlen(tab[i]));
        (tab[i + 1] == NULL) ? (i = i) : write(1, "\n", 1);
    }
}
