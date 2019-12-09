/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** analyse all my arguments
*/

#include "my.h"

int create_my_terminal(mini_t *mini_s, char **env)
{
    char *buffstock;
    size_t lenght = 0;
    int size = 0;

    copy_my_env(mini_s, env);
    while (1) {
        buffstock = NULL;
        my_putstr("$> ", 1);
        if ((size = getline(&buffstock, &lenght, stdin)) == -1) {
            my_putstr("exit\n", 1);
            return (0);
        }
        buffstock[size - 1] = '\0';
        put_in_history(buffstock, mini_s);
        check_my_buffer(mini_s, buffstock);
        if (mini_s->exit_status == 1)
            return (0);
    }
    return (0);
}

int copy_my_env(mini_t *mini_s, char **env)
{
    int size = 0;
    int i = 0;
    int y = 0;

    for (; env[size] != NULL; size++);
    mini_s->env = malloc(sizeof(char *) * (size + 1));
    for (; env[i] != NULL; i++) {
        y = 0;
        mini_s->env[i] = malloc(sizeof(char) * (my_strlen(env[i]) + 1));
        for (; env[i][y] != '\0'; y++)
            mini_s->env[i][y] = env[i][y];
        mini_s->env[i][y] = '\0';
    }
    mini_s->env[i] = NULL;
    return 0;
}

char *replace_tab_by_space(char *buffer)
{
    for (int i = 0; buffer[i] != '\0'; i++)
        if (buffer[i] == '\t')
            buffer[i] = ' ';
    return (buffer);
}

char *remove_my_space(char *buffer)
{
    char *buffstock = malloc(sizeof(char) * (my_strlen(buffer) + 1));
    int i = 0;
    int n = 0;

    for (; buffer[i] != '\0';) {
        for (; buffer[i] == ' ' && buffer[i] != '\0'; i++);
        for (; buffer[i] != ' ' && buffer[i] != '\0'; i++) {
            buffstock[n] = buffer[i];
            n++;
        }
        for (; buffer[i] == ' ' && buffer[i] != '\0'; i++);
        if (buffer[i] != '\0') {
            buffstock[n] = ' ';
            n++;
        }
    }
    buffstock[n] = '\0';
    free(buffer);
    return (buffstock);
}

int check_exit_value(mini_t *mini_s, char *buffer)
{
    int value = 0;

    value = my_getnbr(mini_s, buffer);
    if (mini_s->error == 1)
        return (1);
    if (value > 0)
        value = value % 256;
    else if (value < 0) {
        if (value < -256)
            value = value % -256;
        value = 256 + value;
    }
    mini_s->exit_value = value;
    return (0);
}
