/*
** EPITECH PROJECT, 2019
** PSU Tetris
** File description:
** map
*/

#include "tetris.h"

void get_map(t_params *params, char *type)
{
    char *number = malloc(sizeof(char) * 5);
    int i = 0;
    int j = 0;
    static int a = 0;

    for (; type[i] != '=' && type[i] != '\0'; i++);
    for (i += 1; type[i] != ',' && type[i] != '\0'; i++, j++)
        number[j] = type[i];
    number[j] = '\0';
    if (a % 2 == 0)
        params->rows = my_getnbr(number);
    else
        params->cols = my_getnbr(number);
    a++;
    free(number);
}