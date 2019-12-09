/*
** EPITECH PROJECT, 2019
** CPE_duostumper2
** File description:
** arguments handle
*/

#include "my.h"

char **verification(char **infos)
{
    if ((my_getnbr(infos[0]) * my_getnbr(infos[1])) < 20)
        return NULL;
    if (my_getnbr(infos[0]) > 80 || (my_getnbr(infos[0]) < 1))
        return NULL;
    if (my_getnbr(infos[1]) > 16 || (my_getnbr(infos[1]) < 1))
        return NULL;
    if (infos[4][0] == infos[3][0] || infos[4][0] == infos[2][0])
        return NULL;
    return infos;
}

char **fill_infos(char **infos)
{
    if (infos[0][0] == '\0')
        infos[0] = "7";
    if (infos[1][0] == '\0')
        infos[1] = "6";
    if (infos[2][0] == '\0')
        infos[2] = "X";
    if (infos[3][0] == '\0')
        infos[3] = "O";
    if (infos[4][0] == '\0')
        infos[4] = "#";
    return (infos);
}

char **arguments(char **infos, int ac, char **av)
{
    for (int i = 0; i != 5; i++)
        infos[i] = malloc(sizeof(char) * 12);
    for (int i = 1; i != ac; i = i + 2) {
        if (av[i][0] != '-')
            return NULL;
        if (av[i][1] == 'w')
            infos[0] = av[i + 1];
        if (av[i][1] == 'h')
            infos[1] = av[i + 1];
        if (my_strcmp(av[i], "-p1") == 0)
            infos[2][0] = av[i + 1][0];
        if (my_strcmp(av[i], "-p2") == 0)
            infos[3][0] = av[i + 1][0];
        if (av[i][1] == 'a')
            infos[4][0] = av[i + 1][0];
    }
    infos = fill_infos(infos);
    return (verification(infos));
}
