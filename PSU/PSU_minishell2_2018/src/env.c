/*
** EPITECH PROJECT, 2019
** psu minishell
** File description:
** setenv commande
*/

#include "minishell.h"


int notalpha(char *st)
{
    int valid = 0;

    for (int i = i; st[i] != '\0'; i++) {
        if ((st[i] < 'a' || st[i] > 'z') && (st[i] < 'A' || st[i] > 'Z'))
            valid++;
        if (st[i] >= '0' && st[i] <= '9')
            valid = 0;
        if (valid == 1) {
            write (1, "setenv: Variable name must contain ", 35);
            write (1, "alphanumeric characters.\n", 25);
            return 1;
        }
        valid = 0;
    }
    if ((st[0] < 'a' || st[0] > 'z') && (st[0] < 'A' || st[0] > 'Z')) {
        write (1, "setenv: Variable name must begin with a letter.\n", 48);
        return 1;
    }
    return 0;
}

char **env_set(char **tab, char **env)
{
    char **new;
    int line = 0;

    for (; env[line] != NULL; line++);
    if (search_env(env, tab[1]) != line) {
        env = put_in_env(env, tab[1], tab[2]);
        return (env);
    } else if (notalpha(tab[1]) != 0)
        return (env);
    new = malloc(sizeof(char *) * (line + 2));
    for (line = 0; env[line] != NULL; line++)
        new[line] = env[line];
    if (tab[2] == NULL) {
        new[line] = malloc(sizeof(char) * my_strlen(tab[1]));
        new[line] = my_strcat(tab[1], "=");
    } else if (tab[2] != NULL) {
        new[line] = malloc(sizeof(char) *my_strlen(tab[1])+my_strlen(tab[2]));
        new[line] = my_strcat(my_strcat(tab[1], "="), tab[2]);
    }
    new[line + 1] = NULL;
    return (new);
}

char **env_unset(char **tab, char **env)
{
    char **new;
    int line = 0;
    int find = 0;

    if (tab[1] == NULL)
        return (env);
    for (; env[line] != NULL; line++);
    new = malloc(sizeof(char *) * (line));
    if ((find = search_env(env, tab[1])) == line)
        return (env);
    line = 0;
    for (int k = 0; env[k] != NULL; k++) {
        (k == find && env[k + 1] != NULL) ? k++ : (k = k);
        if (k == find && env[k + 1] == NULL) {
            new[line] = NULL;
            break;
        }
        new[line++] = env[k];
    }
    new[line] = NULL;
    return (new);
}