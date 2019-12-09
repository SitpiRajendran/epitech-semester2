/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** env, arg and path functions
*/

#include "my.h"

void count_my_arg(mini_t *mini_s, char *buffer)
{
    mini_s->arg_nbr = 1;
    for (int i = 0; buffer[i] != '\0'; i++)
        if (buffer[i] == ' ')
            mini_s->arg_nbr++;
}

int my_arg_len(char *buffer, int compt)
{
    int i = 0;

    for (; buffer[compt] != ' ' && buffer[compt] != '\0'; compt++)
        i++;
    return (i);
}

void display_my_perror(char *buffer)
{
    my_putstr(buffer, 2);
    my_putstr(": ", 2);
    perror("");
}

int my_strstrlen(char **buff2d)
{
    int size = 0;

    for (; buff2d[size] != NULL; size++);
    return (size);
}

void display_my_env(mini_t *mini_s)
{
    for (int i = 0; mini_s->env[i] != NULL; i++) {
        my_putstr(mini_s->env[i], 1);
        my_putchar('\n');
    }
}