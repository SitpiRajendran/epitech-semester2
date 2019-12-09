/*
** EPITECH PROJECT, 2019
** DuoStumper 5
** File description:
** get position
*/

#include "tictactoe.h"

int get_pos_y(char *str)
{
    int i = 0;
    int k = 0;
    char *tmp = malloc(sizeof(char) * 12);

    if (tmp == NULL)
        exit (84);
    for (; str[i] != ',' && str[i] != '\n' && str[i] != '\0'; i++);
    for (i = i + 1; str[i] != '\n' && str[i] != '\0'; i++, k++) {
        if (str[i] < '0' || str[i] > '9')
            break;
        tmp[k] = str[i];
    }
    tmp[k] = '\0';
    if (strcmp(tmp, "") == 0)
        return -2;
    i = my_getnbr(tmp);
    free(tmp);
    return i;
}

int get_pos_x(char *str)
{
    int i = 0;
    int k = 0;
    char *tmp = malloc(sizeof(char) * 12);

    if (tmp == NULL)
        exit (84);
    for (; str[i] != ',' && str[i] != '\n' && str[i] != '\0'; i++, k++)
        tmp[k] = str[i];
    tmp[k] = '\0';
    if (strcmp(tmp, "") == 0)
        return -2;
    i = my_getnbr(tmp);
    free(tmp);
    return i;
}
