/*
** EPITECH PROJECT, 2019
** check_position.c
** File description:
** check_position.c
*/

#include "my.h"

int put_in_position_array(char *str, map *map)
{
    static int line = 0;
    int space = 0;
    int a = 0;

    for (int i = 0; str[i] != '\0' && str[i] != '\n' && str[i] != '#' ; i++) {
        if (space == 1) {
            if ((str[i] < '0' && str[i] != ' ') || str[i] > '9') {
                write(2, "Error invalid caracterers", 26);
                return (84);
            }
            map->room_pos[line][a] = str[i];
            a++;
        }
        if (str[i] == ' ')
            space = 1;
    }
    map->room_pos[line][a] = '\0';
    line++;
    return (0);
}

int check_position(map *map)
{
    for (int i = 0; i < map->nb_of_room; i++)
        if (rooms_occurences(map->room_pos[i], map->room_pos, map) == 1) {
            write(2, "Error position", 15);
            return (84);
        }
    return (0);
}
