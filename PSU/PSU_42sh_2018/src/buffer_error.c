/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** buffer error management functions
*/

#include "my.h"

int command_error_management(mini_t *mini_s, char *buffer)
{
    int error = 0;

    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '|' || buffer[i] == '<' || buffer[i] == '>')
            error = first_operator_error(mini_s, buffer, i);
        if (error == 1)
            my_putstr("Invalid null command.\n", 2);
        if (error == 2)
            my_putstr("Missing name for redirect.\n", 2);
        if (error > 0)
            return (84);
    }
    return (0);
}

int first_operator_error(mini_t *mini_s, char *buff, int i)
{
    if (buff[i] == '|' && (i == 0 || buff[i + 1] == '\0'))
        return (1);
    if (buff[i + 1] != '\0' && buff[i] == '|')
        if (buff[i + 2] == ';' || buff[i + 2] == '<'
            || buff[i + 2] == '>')
            return (1);
    if ((buff[i] == '<' && buff[i + 1] == '<') ||
        (buff[i] == '>' && buff[i + 1] == '>')) {
        if (buff[i + 2] == '\0')
            return (2);
        if (i == 0)
            return (1);
        if (buff[i + 3] == ';' && buff[i + 3] == '|'
            && buff[i + 3] == '<' && buff[i + 3] == '>')
            return (2);
        if (buff[i - 2] == ';')
            return (1);
    }
    return (second_operator_error(mini_s, buff, i));
}

int second_operator_error(mini_t *mini_s, char *buff, int i)
{
    if (buff[i] == '<' || buff[i] == '>') {
        if (buff[i + 1] == '\0')
            return (2);
        if (i == 0)
            return (1);
        if (buff[i - 2] == ';')
            return (1);
        if (buff[i + 2] == ';' && buff[i + 2] == '|' &&
            buff[i + 2] == '<' && buff[i + 2] == '>')
            return (1);
    }
    return (0);
}

void error_status(int status)
{
    if (WTERMSIG(status) == SIGSEGV)
        my_putstr("Segmentation fault", 2);
    if (WTERMSIG(status) == SIGFPE)
        my_putstr("Floating exception", 2);
    if (WCOREDUMP(status))
        my_putstr("(core dumped)", 2);
    if (WIFSIGNALED(status) || WCOREDUMP(status))
        my_perror('\n');
}

void stock_my_arg(mini_t *mini_s, char *buffer)
{
    int compt = 0;
    int y = 0;

    mini_s->arg = malloc(sizeof(char *) * (mini_s->arg_nbr + 1));
    for (int i = 0; i != mini_s->arg_nbr; i++) {
        mini_s->arg[i] = malloc(sizeof(char) * (my_arg_len(buffer, compt) + 1));
        y = 0;
        for (; buffer[compt] != ' ' && buffer[compt] != '\0'; compt++) {
            mini_s->arg[i][y] = buffer[compt];
            y++;
        }
        mini_s->arg[i][y] = '\0';
        if (buffer[compt] == ' ' && buffer[compt] != '\0')
            compt++;
    }
    mini_s->arg[mini_s->arg_nbr] = NULL;
    free(buffer);
    change_dollar(mini_s);
}