/*
** EPITECH PROJECT, 2019
** psu minishel
** File description:
** cd command
*/

#include "minishell.h"

char **envput(char **env, char *oldpwd)
{
    char pwd[500];

    env = put_in_env(env, "OLDPWD", oldpwd);
    env = put_in_env(env, "PWD", getcwd(pwd, sizeof(pwd)));

    return (env);
}

char **cd_minus(char *old, char **env)
{
    if (chdir(old) == -1) {
        write(1, old, my_strlen(old));
        write(1, ": No such file or directory.\n", 29);
    } else
        env = envput(env, get_in_env(env, "PWD"));
    return (env);
}

char **cdcommand(char **env, char **tab)
{
    static char *old = "";

    if (tab[1] == NULL) {
        if (chdir(get_in_env(env, "HOME")) != -1)
            env = envput(env, (old = get_in_env(env, "PWD")));
    } else if (tab[1][0] == '-') {
        env = cd_minus(old, env);
        old = get_in_env(env, "PWD");
    } else {
        if (chdir(tab[1]) == -1) {
            write(1, tab[1], my_strlen(tab[1]));
            write(1, ": Not a directory.\n", 19);
        } else
            env = envput(env, (old = get_in_env(env, "PWD")));
    }
    return (env);
}