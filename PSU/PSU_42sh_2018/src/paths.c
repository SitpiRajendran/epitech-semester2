/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** find my bin path
*/

#include "my.h"

int find_my_path(mini_t *mini_s)
{
    mini_s->command = malloc(sizeof(char) * (my_strlen(mini_s->arg[0]) + 1));
    mini_s->command = my_strncpy(mini_s->command, mini_s->arg[0], 0, 0);
    if (access(mini_s->arg[0], X_OK) == 0)
        return (0);
    if (find_my_bin_path(mini_s, find_my_env(mini_s, "PATH")) == 1)
        return (1);
    return (0);
}

int find_my_bin_path(mini_t *mini_s, int i)
{
    char *adress;
    int y = 5;
    int n = 5;

    if (i == -1)
        return (1);
    while (mini_s->env[i][y] != '\0') {
        if (mini_s->env[i][y] == ':') {
            y++;
            n = y;
        }
        for (; mini_s->env[i][y] != '\0' && mini_s->env[i][y] != ':'; y++);
        adress = malloc(sizeof(char) * (y + 2));
        mini_s->arg[0] = my_strcat(fill_my_adress(mini_s, adress, i, n),
        mini_s->command);
        if (access(mini_s->arg[0], X_OK) == 0)
            return (0);
    }
    return (1);
}

char *fill_my_adress(mini_t *mini_s, char *adress, int i, int n)
{
    int m = 0;

    for (; mini_s->env[i][n] != '\0' && mini_s->env[i][n] != ':'; n++) {
        adress[m] = mini_s->env[i][n];
        m++;
    }
    adress[m] = '/';
    adress[m + 1] = '\0';
    return (adress);
}

void display_cd_error(char *path)
{
    my_putstr(path, 2);
    my_putstr(": Not a directory.\n", 2);
}