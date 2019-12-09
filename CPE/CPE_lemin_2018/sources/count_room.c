/*
** EPITECH PROJECT, 2019
** count_room.c
** File description:
** count_room.c
*/

#include "my.h"

int count_room(char **str, map *map)
{
    int nb_of_room = 0;
    int nb_space = 0;

    for (int y = 0; str[y] != NULL; y++) {
        for (int x = 0; str[y][x] != '#' && str[y][x] != '\0'; x++) {
            if (str[y][x] == ' ' && str[y][x - 1] != ' ' &&
                str[y][x + 1] != ' ')
                nb_space++;
            if (nb_space == 2) {
                nb_of_room++;
                nb_space = 0;
            }
        }
    }
    map->nb_of_room = nb_of_room;
    return (nb_of_room);
}
