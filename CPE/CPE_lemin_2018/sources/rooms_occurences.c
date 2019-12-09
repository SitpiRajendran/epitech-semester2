/*
** EPITECH PROJECT, 2019
** CPE_lemin_2018
** File description:
** rooms_occurences
*/

#include "my.h"

int rooms_occurences(char *str, char **tab, map *map)
{
    int count_occurences = 0;

    for (int i = 0; i < map->nb_of_room; i++) {
        if (my_strcmp(tab[i], str) == 0)
            count_occurences++;
    }
    if (count_occurences > 1)
        return (1);
    return (0);
}
