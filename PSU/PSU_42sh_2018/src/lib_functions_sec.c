/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** my other lib functions
*/

#include "my.h"

char *my_strcat(char *buff, char *str)
{
    char *path = malloc(sizeof(char) *
    (my_strlen(buff) + my_strlen(str) + 1));
    int i = 0;

    for (; buff[i] != '\0'; i++)
        path[i] = buff[i];
    for (int y = 0; str[y] != '\0'; y++) {
        path[i] = str[y];
        i++;
    }
    path[i] = '\0';
    return (path);
}

char *my_strncpy(char *buff, char *str, int i, int n)
{
    for (; str[n] != '\0'; i++) {
        buff[i] = str[n];
        n++;
    }
    buff[i] = '\0';
    return (buff);
}

int my_strcmp(char *buff, char *str, int mode)
{
    int i = 0;

    for (; str[i] != '\0'; i++)
        if (buff[i] != str[i])
            return (0);
    if (mode == 1)
        if (buff[i] != '\0' && buff[i] != ' ')
            return (0);
    if (mode == 2)
        if (buff[i] != '=')
            return (0);
    if (mode == 3)
        if (buff[i] != '\0' && buff[i] != ' ' && buff[i] != '\n')
            return (0);
    return (1);
}

int my_strncmp(char *buff, char *str, int size)
{
    for (int i = 0; i != size; i++)
        if (buff[i] != str[i])
            return (0);
    return (1);
}

int my_strlen(char *buffer)
{
    int i = 0;

    for (; buffer[i] != '\0'; i++);
    return (i);
}