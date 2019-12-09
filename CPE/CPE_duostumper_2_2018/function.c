/*
11;rgb:0000/0000/0000** EPITECH PROJECT, 2019
** DuoStumper Function
** File description:
** function
*/

#include "my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i = i + 1;
    }
    return (0);
}

int my_strcmp(char const *s1, char const *s2)
{
    for (int i = 0; s1[i] != '\0' || s2[i] != '\0'; i++)
        if (s1[i] != s2[i])
            return (1);
    return (0);
}

int my_getnbr(char *str)
{
    int st = 0;
    int x = 0;

    if (str[0] == '\0')
        return (0);
    for (; str[x] != '\0'; x++) {
        if (str[x] >= '0' && str[x] <= '9') {
            st = st * 10 + (str[x] - '0');
        } else if (str[x] < '0' || str[x] > '9')
            return (st);
    }
    return (st);
}
