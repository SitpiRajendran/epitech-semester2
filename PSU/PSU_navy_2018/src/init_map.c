/*
** EPITECH PROJECT, 2019
** PSU Navy
** File description:
** init map
*/

#include "my.h"

char **init_map(void)
{
    char **map = malloc(sizeof(char *) * 9);

    for (int i = 0; i != 9; i++) {
        map[i] = malloc(sizeof(char) * 8);
        for (int j = 0; j != 8; j++)
            map[i][j] = '.';
    }
    return (map);
}

char **first_add_map(char *str, char **map)
{
    map_coord co;

    if (verif_boat_nb(str) != 0)
        return (NULL);
    for (int i = 0; i != 4; i++) {
        co.map = get_one_line(str, i + 1);
        co.x1 = get_posx_one(co.map) - 1;
        co.y1 = get_posy_one(co.map) - 1;
        co.x2 = get_posx_two(co.map) - 1;
        co.y2 = get_posy_two(co.map) - 1;
        if (verif_coordinates(co) != 0)
            return (NULL);
        if (map[co.y1][co.x1] == '.')
            map[co.y1][co.x1] = co.map[0];
        map = map_add(co, map);
    }
    return (map);
}

char **map_add(map_coord co, char **map)
{
    while (((co.x2 - co.x1) > 0) && co.y2 == co.y1) {
        co.x1 += 1;
        map[co.y1][co.x1] = co.map[0];
    }
    while (((co.y2 - co.y1) > 0) && co.x2 == co.x1) {
        co.y1 += 1;
        map[co.y1][co.x1] = co.map[0];
    }
    return (map);
}

void print_map(char **map)
{
    my_putstr(" |A B C D E F G H\n-+---------------\n");
    for (int i = 0; i != 8; i++) {
        my_put_nbr(i + 1);
        write(1, "|", 1);
        for (int j = 0; j != 8; j++) {
            write(1, &map[i][j], 1);
            (j != 7) ? write(1, " ", 1) : (j = j);
        }
        write(1, "\n", 1);
    }
    write(1, "\n", 1);
}
