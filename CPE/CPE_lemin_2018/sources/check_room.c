/*
** EPITECH PROJECT, 2019
** check_rooms.c
** File description:
** check_rooms.c
*/

#include "my.h"

int room_exist(char **str)
{
    int space = 0;

    for (int y = 0; str[y] != NULL; y++)
        for (int x = 0; str[y][x] != '\0'; x++) {
            if (str[y][x] == ' ')
                space++;
            if (space == 2)
                return (0);
        }
    write(2, "Error: need room\n", 17);
    return (84);
}

void put_in_room_array(char *str, map *map)
{
    static int line = 0;
    int i = 0;

    while (str[i] != ' ') {
        map->room_name[line][i] = str[i];
        i++;
    }
    map->room_name[line][i] = '\0';
    line++;
}

int check_stend(char **str)
{
    int i = 0;
    int e = 0;

    for (int y = 0; str[y] != NULL; y++) {
        if (my_strcmp(str[y], "##start\n") == 0)
            i++;
        if (my_strcmp(str[y], "##end\n") == 0)
            e++;
    }
    if (i != 1 || e != 1) {
        write(2, "Error not start or end", 23);
        return (84);
    }
    return 0;
}

int room_array(char **str, map *map)
{
    int nb_of_room = count_room(str, map);
    int nb_space = 0;

    map->room_name = mem_alloc_2d_array(nb_of_room, 1000);
    map->room_pos = mem_alloc_2d_array(nb_of_room, 1000);
    for (int y = 0; str[y] != NULL; y++) {
        for (int x = 0; str[y][x] != '\0' && str[y][x] != '#'; x++)
            if (str[y][x] == ' ')
                nb_space++;
        if (nb_space >= 2) {
            put_in_room_array(str[y], map);
            if (put_in_position_array(str[y], map) == 84)
                return (84);
        }
        nb_space = 0;
    }
    return (check_stend(str));
}

int check_room(char **str, map *map)
{
    if (room_exist(str) == 84)
        return (84);
    if (room_array(str, map) == 84)
        return (84);
    for (int i = 0; i < map->nb_of_room; i++) {
        if (rooms_occurences(map->room_name[i], map->room_name, map) == 1) {
            write(2, "Error: several room have the same name\n", 40);
            return (84);
        }
    }
    return (0);
}
