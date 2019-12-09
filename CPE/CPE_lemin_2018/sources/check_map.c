/*
** EPITECH PROJECT, 2019
** check_map.c
** File description:
** check_map.c
*/

#include "my.h"

int get_ants(char *str)
{
    int nb = my_getnbr(str);

    if (nb < 1 || count_space(str) != 0)
        return 0;
    return nb;
}

map *init_map(void)
{
    map *map = malloc(sizeof(struct map_t));

    map->nb_of_room = 0;
    map->nb_tunnel = 0;
    map->room_name = NULL;
    map->room_pos = NULL;
    map->before_tun = NULL;
    map->after_tun = NULL;
    return (map);
}

int check_stnd(char **str)
{
    int i = search_line(str, "##start\n");
    int e = 0;

    for (int j = 0; str[i][j] != '\0'; j++)
        str[i][j] == ' ' ? e++ : (e = e);
    if (e != 2)
        return 84;

    i = search_line(str, "##end\n");
    e = 0;
    for (int j = 0; str[i][j] != '\0'; j++)
        str[i][j] == ' ' ? e++ : (e = e);
    if (e != 2)
        return 84;
    return 0;
}

int check_map(char **str, map *map)
{
    if (get_ants(str[0]) == 0)
        return 84;
    if (check_room(str, map) == 84)
        return (84);
    if (check_position(map) == 84)
        return (84);
    if (check_tunnel(str, map) == 84)
        return (84);
    return (0);
}
