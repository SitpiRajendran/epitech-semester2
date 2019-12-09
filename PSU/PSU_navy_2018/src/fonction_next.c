/*
** EPITECH PROJECT, 2019
** PSU Navy
** File description:
** fonction next
*/

#include "my.h"

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

int my_strlen(char *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    return (i);
}
