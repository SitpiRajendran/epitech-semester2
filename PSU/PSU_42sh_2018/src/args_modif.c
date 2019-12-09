/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** functions about arg modif
*/

#include "my.h"

int search_env(char **env, char *str)
{
    int i = 0;
    int j = 0;
    int k = 0;

    for (; env[i] != NULL; i++) {
        for (j = 0; env[i][j] == str[j]; j++);
        for (k = 0; env[i][k] != '='; k++);
        if (j == k)
            return (i);
    }
    return (-1);
}

char *get_env(char **env, char *str)
{
    int i = 0;
    int k = 0;
    char *envstr = NULL;
    char *path = NULL;

    if ((i = search_env(env, str)) == -1) {
        if (str[0] != '?') {
            my_putstr(str, 1);
            my_putstr(": Undefined variable.", 1);
        }
        return (NULL);
    }
    envstr = env[i];
    for (i = 0; envstr[i] != '='; i++);
    path = malloc(sizeof(char) * my_strlen(envstr));
    for (k = 0, i = i + 1; envstr[i] != '\0' && envstr[i] != '\n'; k++)
        path[k] = envstr[i++];
    path[k] = '\0';
    return (path);
}

char *del_dol(char *str)
{
    int len = my_strlen(str);

    for (int i = 1; i < len; i++)
        str[i - 1] = str[i];
    return (str);
}

void change_dollar(mini_t *mini_s)
{
    char *str = NULL;

    for (int i = 0; mini_s->arg[i] != NULL; i++)
        if (change_dollar_sec(mini_s, str, i) == 1)
            return;
}

int change_dollar_sec(mini_t *mini_s, char *str, int i)
{
    if (my_strcmp("$?", mini_s->arg[i], 1) == 1) {
        mini_s->arg[i] = my_itoc(mini_s->v_return);
        return (1);
    }
    if ((my_strncmp("$", mini_s->arg[i], 1) == 1)
    && my_strcmp("$", mini_s->arg[i], 1) == 0)
        if ((str = get_env(mini_s->env, del_dol(mini_s->arg[i]))) != NULL)
            mini_s->arg[i] = str;
    return (0);
}