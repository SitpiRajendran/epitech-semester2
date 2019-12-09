/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** my other lib functions
*/

#include "my.h"

char *my_revstr(char *str)
{
    int i = 0;
    int len = my_strlen(str);
    char c;

    while (i < len / 2) {
        c = *(str + i);
        *(str + i) = *(str + len - i -1);
        *(str + len - i -1) = c;
        i++;
    }
    return (str);
}

char *my_itoc(int nbr)
{
    int neg = 0;
    int i = 0;
    char *str = malloc(sizeof(char) * 10);

    if (nbr < 0) {
        neg = 1;
        nbr *= -1;
    }
    while (nbr > 9) {
        str[i] = (nbr % 10) + 48;
        nbr = (nbr - (nbr % 10)) / 10;
        i++;
    }
    str[i++] = nbr + 48;
    if (neg == 1)
        str[i++] = '-';
    str[i] = '\0';
    str = my_revstr(str);
    return (str);
}