/*
** EPITECH PROJECT, 2019
** count_tunnel.c
** File description:
** count_tunnel.c
*/

#include "my.h"

int count_tunnel(char **str, map *map)
{
    int count = 0;

    for (int y = 0; str[y] != NULL; y++)
        for (int x = 0; str[y][x] != '\0' && str[y][x] != '#'; x++)
            if (str[y][x] == '-')
                count++;
    map->nb_tunnel = count;
    return (count);
}
