/*
** EPITECH PROJECT, 2019
** check_tunnels.c
** File description:
** check_tunnels.c
*/

#include "my.h"

int check_linked_room(map *map, int line)
{
    int check = 0;

    for (int i = 0; i < map->nb_of_room; i++) {
        if (my_strcmp(map->room_name[i], map->before_tun[line]) == 0)
            check++;
        if (my_strcmp(map->room_name[i], map->after_tun[line]) == 0)
            check++;
    }
    if (check >= 2)
        return (1);
    else
        return (0);
}

int put_in_tunnel_array(char *str, map *map)
{
    static int line = 0;
    int a = 0;

    while (str[a] != '-' && str[a] != ' ') {
        map->before_tun[line][a] = str[a];
        a++;
    }
    map->before_tun[line][a] = '\0';
    a++;
    for (int i = 0; str[a] != '\0' && str[a] != '\n' && str[a] != ' '; i++) {
        map->after_tun[line][i] = str[a];
        map->after_tun[line][i + 1] = '\0';
        a++;
    }
    if (check_linked_room(map, line) == 0) {
        write(2, "Link between room that don't exist\n", 35);
        return (84);
    }
    line++;
    return (0);
}

int tunnel_exist(char **str)
{
    for (int y = 0; str[y] != NULL; y++)
        for (int x = 0; str[y][x] != '\0'; x++)
            if (str[y][x] == '-')
                return (0);
    write(2, "Error: need link between room\n", 30);
    return (84);
}

int tunnel_array(char **str, map *map)
{
    int nb_of_tunnel = count_tunnel(str, map);

    map->before_tun = mem_alloc_2d_array(nb_of_tunnel, 1000);
    map->after_tun = mem_alloc_2d_array(nb_of_tunnel, 1000);
    for (int y = 0; str[y] != NULL; y++) {
        for (int x = 0; str[y][x] != '\0' && str[y][x] != '#'; x++)
            if (str[y][x] == '-')
                if (put_in_tunnel_array(str[y], map) == 84)
                    return (84);
    }
    return (0);
}

int check_tunnel(char **str, map *map)
{
    if (tunnel_exist(str) == 84)
        return (84);
    if (tunnel_array(str, map) == 84)
        return (84);
    return (0);
}
