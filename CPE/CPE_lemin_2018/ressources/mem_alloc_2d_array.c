/*
** EPITECH PROJECT, 2018
** mem_alloc_2d_array
** File description:
** allocate memory for 2d char array
*/

#include <stdlib.h>

char **mem_alloc_2d_array(int nb_rows, int nb_cols)
{
    char **tab;
    int i = 0;

    tab = malloc(sizeof(char *) * (nb_rows));
    while (i < nb_rows) {
        tab[i] = malloc(sizeof(char) * (nb_cols));
        i++;
    }
    return (tab);
}
