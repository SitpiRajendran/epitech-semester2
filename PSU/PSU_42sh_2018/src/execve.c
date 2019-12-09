/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** all fork functions
*/

#include "my.h"

int create_my_fork(mini_t *mini_s)
{
    int status = 0;

    if ((mini_s->fork_val = fork()) == -1) {
        perror("fork: ");
        return (84);
    }
    if (mini_s->fork_val > 0)
        wait(&status);
    error_status(status);
    if (mini_s->fork_val == 0)
        if (execve(mini_s->arg[0], mini_s->arg, mini_s->env) == -1) {
            display_exec_error(mini_s);
            exit(0);
        }
    mini_s->v_return = WEXITSTATUS(status);
    return (0);
}

int manage_my_cd_hyphen(mini_t *mini_s, char *buffstock)
{
    if (mini_s->arg_nbr == 2 && my_strcmp(mini_s->arg[1], "-", 1) == 1) {
        if (mini_s->compt == 0) {
            my_putstr(": No such file or directory.\n", 2);
            return (1);
        }
        else if (chdir(mini_s->path) == -1)
            return (1);
        change_my_env_path(mini_s, mini_s->path);
        mini_s->path = buffstock;
        return (1);
    }
    return (0);
}

char *change_my_buffer(char *buff1, char *buff2, int mode)
{
    char *buffstock = malloc(sizeof(char) *
    (my_strlen(buff1) + my_strlen(buff2) + 2));
    int i = 0;

    for (; buff1[i] != '\0'; i++)
        buffstock[i] = buff1[i];
    buffstock[i] = '=';
    if (mode == 1) {
        i++;
        for (int i2 = 0; buff2[i2] != '\0'; i2++) {
            buffstock[i] = buff2[i2];
            i++;
        }
    }
    if (mode == 0)
        i++;
    buffstock[i] = '\0';
    return (buffstock);
}

int scan_my_setenv_buffer(mini_t *mini_s)
{
    if (mini_s->arg[1][0] < 65 || mini_s->arg[1][0] > 90)
        if (mini_s->arg[1][0] < 97 || mini_s->arg[1][0] > 122) {
            my_putstr("setenv: Variable name must begin with a letter.\n", 2);
            return (1);
        }
    for (int i = 0; mini_s->arg[1][i] != '\0'; i++)
        if (aplhanumeric_verification(mini_s->arg[1][i]) == 1) {
            my_putstr("setenv: Variable name must ", 2);
            my_putstr("contain alphanumeric characters.\n", 2);
            return (1);
        }
    return (0);
}

int aplhanumeric_verification(char c)
{
    if ((c < 65 || c > 90) && (c < 97 || c > 122))
        if (c < 48 || c > 57)
            return (1);
    return (0);
}
