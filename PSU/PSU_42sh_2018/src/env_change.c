/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** change my path, home etc
*/

#include "my.h"

char *get_my_home_path(mini_t *mini_s)
{
    char *home_path = NULL;

    for (int i = 0; mini_s->env[i] != NULL; i++)
        if (my_strncmp(mini_s->env[i], "HOME=", 5) == 1) {
            home_path = malloc(sizeof(char) * (my_strlen(mini_s->env[i]) + 1));
            home_path = my_strncpy(home_path, mini_s->env[i], 0, 5);
            return (home_path);
        }
    return ("\0");
}

void change_my_env_path(mini_t *mini_s, char *buffer)
{
    for (int i = 0; mini_s->env[i] != NULL; i++)
        if (my_strncmp(mini_s->env[i], "PWD=", 4) == 1) {
            mini_s->env[i] = malloc(sizeof(char) *
            (my_strlen("PWD=") + my_strlen(buffer) + 1));
            mini_s->env[i] = my_strcat("PWD=", buffer);
        }
    mini_s->compt = 1;
}

int find_my_env(mini_t *mini_s, char *env_line)
{
    int i = 0;

    for (; mini_s->env[i] != NULL; i++)
        if (my_strcmp(mini_s->env[i], env_line, 2)) {
            mini_s->env[i] = my_strcat(mini_s->env[i], ":./");
            return (i);
        }
    return (-1);
}

char **remove_my_env(char **old_env, int line)
{
    char **new_env;
    int i = 0;

    if (line == -1)
        return (old_env);
    new_env = malloc(sizeof(char *) * (my_strstrlen(old_env) + 1));
    for (; i != line; i++) {
        new_env[i] = malloc(sizeof(char) * (my_strlen(old_env[i]) + 1));
        new_env[i] = copy_my_env_line(new_env[i], old_env[i]);
    }
    for (; old_env[i + 1] != NULL; i++) {
        new_env[i] = malloc(sizeof(char) * (my_strlen(old_env[i + 1]) + 1));
        new_env[i] = copy_my_env_line(new_env[i], old_env[i + 1]);
    }
    new_env[i] = NULL;
    return (new_env);
}

char **add_in_my_env(char **old_env, char *add_env)
{
    char **new_env;
    int i = 0;
    int y = 0;
    int z = 0;

    new_env = malloc(sizeof(char *) * (my_strstrlen(old_env) + 2));
    for (; old_env[i] != NULL; i++) {
        y = 0;
        new_env[i] = malloc(sizeof(char) * (my_strlen(old_env[i]) + 1));
        for (; old_env[i][y] != '\0'; y++)
            new_env[i][y] = old_env[i][y];
        new_env[i][y] = '\0';
    }
    new_env[i] = malloc(sizeof(char) * (my_strlen(add_env) + 1));
    for (; add_env[z] != '\0'; z++)
        new_env[i][z] = add_env[z];
    new_env[i][z] = '\0';
    new_env[i + 1] = NULL;
    return (new_env);
}