/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** history
*/

#include "my.h"

void put_in_history(char *str, mini_t *stru)
{
    static int i = 0;
    int j = 0;

    if (i == 0)
        if ((stru->history = malloc(sizeof(char *) * 500)) == NULL)
            exit(0);
    if (i == 500)
        i = 0;
    if ((stru->history[i] = malloc(sizeof(char) * my_strlen(str) + 2)) == NULL)
        exit(0);
    for (; str[j] != '\0'; j++)
        stru->history[i][j] = str[j];
    stru->history[i][j] = '\n';
    stru->history[i][j + 1] = '\0';
    stru->history[i + 1] = NULL;
    i = i + 1;
}

void print_history(mini_t *stru)
{
    for (int i = 0; stru->history[i] != NULL; i++)
        my_putstr(stru->history[i], 1);
    return;
}

void free_history(mini_t *mini_s)
{
    for (int i = 0; mini_s->history[i] != NULL; i++)
        free(mini_s->history[i]);
    free(mini_s->history);
}

void print_one_history(mini_t *mini_s)
{
    int i = my_getnbr(mini_s, mini_s->arg[1]);
    int j = 0;

    if (i < 1) {
        for (; mini_s->history[j] != NULL; j++);
        j = j + i;
        if (j < 0)
            return;
        my_putstr(mini_s->history[j], 1);
    } else
        my_putstr(mini_s->history[i - 1], 1);
}