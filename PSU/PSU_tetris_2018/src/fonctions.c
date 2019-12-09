/*
** EPITECH PROJECT, 2019
** PSU Tetris
** File description:
** fonctions
*/

#include "tetris.h"

int my_strcmp(char const *s1, char const *s2)
{
    for (int i = 0; s1[i] != '\0' && s2[i] != '\0'; i++) {
        if (s1[i] < s2[i])
            return (s1[i] - s2[i]);
        if (s1[i] > s2[i])
            return (s1[i] - s2[i]);
    }
    return 0;
}

int my_strlen(char const *str)
{
    int i = 0;

    if (str != NULL)
        for (; str[i] != '\0'; i++);
    return i;
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

void my_put_nbr(int nb)
{
    char c;
    if (nb < 0) {
        write(1, "-", 1);
        nb = nb * (- 1);
    } else if (nb > 9)
        my_put_nbr(nb / 10);
    c = nb % 10 + 48;
    write(1, &c, 1);
}

char *my_strcat(char *dest, char const *scr)
{
    int f = 0;
    char *nw = malloc(sizeof(char *) *(my_strlen(dest) + my_strlen(scr) +1));
    int i = 0;

    if (scr == NULL)
        return (NULL);
    for (; dest[i] != '\0'; i++)
        nw[i] = dest[i];
    nw[i] = '\0';
    for (; nw[f] != '\0'; f = f + 1);
    for (i = 0; scr[i] != '\0'; i++) {
        if (scr[i] != '\n') {
            nw[f] = scr[i];
            f++;
        }
    }
    nw[f] = '\0';
    return (nw);
}
