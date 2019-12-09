/*
** EPITECH PROJECT, 2019
** free_map.c
** File description:
** free_map.c
*/

#include "my.h"

void free_map(map *map)
{
    for (int i = 0; i < map->nb_of_room; i++)
        free(map->room_name[i]);
    for (int i = 0; i < map->nb_of_room; i++)
        free(map->room_pos[i]);
}
