/*
** EPITECH PROJECT, 2019
** PSU Navy
** File description:
** verif map
*/

#include "my.h"

int verif_boat_nb(char *map)
{
    if (map[0] != '2' || map[8] != '3' || map[16] != '4' || map[24] != '5') {
        error("Boat length error!");
        return (84);
    }
    if (map[7] != '\n' || map[15] != '\n' || map[23] != '\n') {
        error("Lines error");
        return (84);
    }
    return (0);
}

int verif_coordinates(map_coord co)
{
    if ((co.x1 < 0 || co.x1 > 7) || (co.x2 < 0 || co.x2 > 7)) {
        error("Not valid coordinates");
        return (84);
    }
    if ((co.y1 < 0 || co.y1 > 7) || (co.y2 < 0 || co.y2 > 7)) {
        error("Not valid coordinates");
        return (84);
    }
    if (co.x1 != co.x2 && co.y1 != co.y2) {
        error("Coordinates problems\n");
        return (84);
    }
    if (co.x1 == co.x2 && (co.y2 - co.y1 + 1) != my_getnbr(&co.map[0])) {
        error("Wrong boat size\n");
        return (84);
    }
    if (co.y1 == co.y2 && (co.x2 - co.x1 + 1) != my_getnbr(&co.map[0])) {
        error("Wrong boat size\n");
        return (84);
    }
    return (0);
}

char *get_one_line(char *map, int x)
{
    char *string = malloc(sizeof(char) * 8);
    int nb;
    int y;

    for (int i = 0; i != x; i++)
        for (y = 0; map[(nb = y + (8 * i))] != '\n' && map[nb] != '\0'; y++)
            string[y] = map[nb];
    return (string);
}
