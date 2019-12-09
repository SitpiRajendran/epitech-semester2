/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** manage all my env options
*/

#include "my.h"

int check_my_env(mini_t *mini_s)
{
    if (my_strcmp(mini_s->arg[0], "env", 1) == 1) {
        display_my_env(mini_s);
        return (1);
    }
    if (my_strcmp(mini_s->arg[0], "setenv", 1) == 1) {
        check_setenv(mini_s);
        if (mini_s->set_error == 1)
            my_putstr("Unmatched \'\'\'.\n", 2);
        if (mini_s->set_error == 2)
            my_putstr("Unmatched \'\"\'.\n", 2);
        return (1);
    }
    if (my_strcmp(mini_s->arg[0], "unsetenv", 1) == 1) {
        check_unsetenv(mini_s);
        return (1);
    }
    return (0);
}

void check_setenv(mini_t *mini_s)
{
    if (mini_s->arg_nbr > 3)
        my_putstr("setenv: Too many arguments.\n", 2);
    if (mini_s->arg_nbr == 1)
        display_my_env(mini_s);
    if (mini_s->arg_nbr == 1 || mini_s->arg_nbr > 3)
        return;
    if (scan_my_setenv_buffer(mini_s) == 1)
        return;
    if (mini_s->arg_nbr == 2)
        mini_s->env = add_in_my_env(mini_s->env,
        change_my_buffer(mini_s->arg[1], "", 0));
    if (mini_s->arg_nbr == 3) {
        if (check_setenv_second_arg(mini_s, mini_s->arg[2]) == 1)
            return;
        mini_s->env = add_in_my_env(mini_s->env,
        change_my_buffer(mini_s->arg[1], mini_s->arg[2], 1));
    }
}

int check_setenv_second_arg(mini_t *mini_s, char *buffer)
{
    int first = 0;
    int second = 0;

    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\'')
            first++;
        if (buffer[i] == '\"')
            second++;
    }
    if (first % 2 == 1)
        mini_s->set_error = 1;
    if (second % 2 == 1)
        mini_s->set_error = 2;
    if (mini_s->set_error > 0)
        return (1);
    return (0);
}

void check_unsetenv(mini_t *mini_s)
{
    if (mini_s->arg_nbr < 2) {
        my_putstr("unsetenv: Too few arguments.\n", 2);
        return;
    }
    for (int i = 1; i != mini_s->arg_nbr; i++)
        mini_s->env = remove_my_env(mini_s->env,
        find_my_env(mini_s, mini_s->arg[i]));
}

char *copy_my_env_line(char *new_env, char *old_env)
{
    int y = 0;

    for (; old_env[y] != '\0'; y++)
        new_env[y] = old_env[y];
    new_env[y] = '\0';
    return (new_env);
}