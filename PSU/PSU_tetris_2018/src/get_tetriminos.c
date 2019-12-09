/*
** EPITECH PROJECT, 2019
** PSU Tetris
** File description:
** Get infos on files
*/

#include "tetris.h"

char *get_name_m(char *str)
{
    char *tmp = malloc(sizeof(char) * 12);
    int i = 0;
    int j = 0;

    if (tmp == NULL)
        return "error";
    for (; str[i] != '\0'; i++);
    for (; str[i] != '.' && i != 0; i--);
    for (; str[i] != '\0'; i++, j++)
        tmp[j] = str[i];
    tmp[j] = '\0';
    if (my_strcmp(tmp, ".tetrimino") != 0)
        return "error";
    free(tmp);
    if ((tmp = malloc(sizeof(char) * (my_strlen(str) - 9))) == NULL)
        return "error";

    for (i = 0; str[i] != '.'; i++)
        tmp[i] = str[i];
    tmp[i] = '\0';
    return tmp;
}

int get_online(char *str, int space)
{
    int i = 0;
    int j = 0;
    char *tmp = malloc(sizeof(char) * 12);

    for (int count = 0; count != space && str[i] != '\0'; i++)
        if (str[i] == ' ')
            count++;
    if (str[i] == '\0')
        return -2;
    for (; str[i] != ' ' && str[i] != '\n' && str[i] != '\0'; i++, j++)
        tmp[j] = str[i];
    tmp[j] = '\0';
    i = my_getnbr(tmp);
    free(tmp);

    return i;
}

char *get_obj(char *str)
{
    char *tmp = malloc(sizeof(char) * 200);
    int i = 0;
    int j = 0;

    for (; str[i] != '\n' && str[i] != '\0'; i++);
    if (str[i] == '\0')
        return "";
    i++;
    for (; str[i] != '\0'; i++, j++)
        tmp[j] = str[i];
    if (tmp[j - 1] == '\n')
        tmp[j - 1] = '\0';
    else
        tmp[j] = '\0';

    return tmp;
}

void verif_tetriminos(elem_t *new)
{
    int i = 0;
    int j = 1;

    if (new->obj[0] == '\0')
        new->cols = -2;
    for (; new->obj[i] != '\0'; i++) {
        if (new->obj[i] != '*' && new->obj[i] != ' ' && new->obj[i] != '\n')
            new->cols = -2;
        (new->obj[i] == '\n') ? j++ : (j = j);
    }
    if (j != new->cols)
        new->cols = -2;
}