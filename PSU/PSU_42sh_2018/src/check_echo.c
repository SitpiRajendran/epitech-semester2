/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** All the functions about checking the echo command
*/

#include "my.h"

void check_echo(mini_t *mini_s)
{
    int i = 1;

    if (mini_s->arg_nbr == 1)
        return my_putstr("\n", 1);
    if (my_strcmp(mini_s->arg[1], "-n", 1) == 1)
        i = 2;
    for (; mini_s->arg[i] != NULL; i = i + 1) {
        my_putstr(mini_s->arg[i], 1);
        if (mini_s->arg[i + 1] != NULL)
            my_putchar(' ');
    }
    if (my_strcmp(mini_s->arg[1], "-n", 1) == 1)
        my_putchar('%');
    my_putchar('\n');
}
