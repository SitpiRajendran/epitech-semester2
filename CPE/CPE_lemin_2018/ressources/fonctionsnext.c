/*
** EPITECH PROJECT, 2019
** PSU Navy
** File description:
** fonction next
*/

#include "my.h"

int my_strline(char *str)
{
    int y = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '\n')
            y++;
    return y;
}

int my_getnbr(char *str)
{
    int st = 0;
    int x = 0;

    if (str[0] == '\0')
        return (0);
    for (; str[x] != '\0'; x++) {
        if (str[x] >= '0' && str[x] <= '9')
            st = st * 10 + (str[x] - '0');
        else if (str[x] < '0' || str[x] > '9')
            return (st);
    }
    return (st);
}

char **strtoarr(char *str, int len)
{
    int n = 0;
    int j = 0;
    int a = 0;
    char **tab = malloc(sizeof(char *) * len);

    for (int i = 0; i != len; i++)
        tab[i] = malloc(sizeof(char) * len);
    for (int i = a; str[i] != '\0'; i++) {
        if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n') {
            tab[n][j] = str[i];
            j++;
        }
        else if (str[i - 1] != ' ' && str[i - 1] != '\t') {
            tab[n][j++] = '\0';
            n++;
            j = 0;
        }
    }
    tab[n] = NULL;
    return (tab);
}