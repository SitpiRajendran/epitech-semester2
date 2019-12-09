/*
** EPITECH PROJECT, 2019
** CPE Dante
** File description:
** solver.c
*/

#include "solver.h"

int solver(char *av)
{
    t_map map = get_map(av);

    if (map.error == 1)
        return error("File Error");
    else if (map.chara[map.x_max - 1][map.y_max - 1] == 'X'
        || map.chara[0][0] == 'X')
        return no_solution("no solution found");

    algo_d(&map, 0, 0);
    if (map.chara[0][0] == '*')
        return no_solution("no solution found");

    print_map(map);
    return 0;
}

int algo_d(t_map *map, int x, int y)
{
    if (x == (map->x_max - 1) && y == (map->y_max - 1)) {
        map->chara[x][y] = 'o';
        return 1;
    } else if (map->num[x][y] == 0 || map->num[x][y] == 2)
        return 0;

    map->num[x][y] = 2;

    if (x != map->x_max - 1 && algo_d(map, x + 1, y) == 1)
        map->chara[x][y] = 'o';
    (y != 0 && algo_l(map, x, y - 1) == 1) ? (map->chara[x][y] = 'o') : (x = x);

    if (y != map->y_max - 1 && algo_r(map, x, y + 1) == 1)
        map->chara[x][y] = 'o';
    (x != 0 && algo_u(map, x - 1, y) == 1) ? (map->chara[x][y] = 'o') : (x = x);

    if (map->chara[x][y] == 'o')
        return 1;
    return 0;
}

int algo_r(t_map *map, int x, int y)
{
    if (x == (map->x_max - 1) && y == (map->y_max - 1)) {
        map->chara[x][y] = 'o';
        return 1;
    } else if (map->num[x][y] == 0 || map->num[x][y] == 2)
        return 0;

    map->num[x][y] = 2;

    if (y != map->y_max - 1 && algo_r(map, x, y + 1) == 1)
        map->chara[x][y] = 'o';
    if (x != map->x_max - 1 && algo_d(map, x + 1, y) == 1)
        map->chara[x][y] = 'o';

    (x != 0 && algo_u(map, x - 1, y) == 1) ? (map->chara[x][y] = 'o') : (x = x);
    (y != 0 && algo_l(map, x, y - 1) == 1) ? (map->chara[x][y] = 'o') : (x = x);

    if (map->chara[x][y] == 'o')
        return 1;
    return 0;
}

int algo_u(t_map *map, int x, int y)
{
    if (x == (map->x_max - 1) && y == (map->y_max - 1)) {
        map->chara[x][y] = 'o';
        return 1;
    } else if (map->num[x][y] == 0 || map->num[x][y] == 2)
        return 0;

    map->num[x][y] = 2;

    (x != 0 && algo_u(map, x - 1, y) == 1) ? (map->chara[x][y] = 'o') : (x = x);
    if (y != map->y_max - 1 && algo_r(map, x, y + 1) == 1)
        map->chara[x][y] = 'o';

    (y != 0 && algo_l(map, x, y - 1) == 1) ? (map->chara[x][y] = 'o') : (x = x);
    if (x != map->x_max - 1 && algo_d(map, x + 1, y) == 1)
        map->chara[x][y] = 'o';

    if (map->chara[x][y] == 'o')
        return 1;
    return 0;
}

int algo_l(t_map *map, int x, int y)
{
    if (x == (map->x_max - 1) && y == (map->y_max - 1)) {
        map->chara[x][y] = 'o';
        return 1;
    } else if (map->num[x][y] == 0 || map->num[x][y] == 2)
        return 0;

    map->num[x][y] = 2;

    (y != 0 && algo_l(map, x, y - 1) == 1) ? (map->chara[x][y] = 'o') : (x = x);
    (x != 0 && algo_u(map, x - 1, y) == 1) ? (map->chara[x][y] = 'o') : (x = x);

    if (x != map->x_max - 1 && algo_d(map, x + 1, y) == 1)
        map->chara[x][y] = 'o';
    if (y != map->y_max - 1 && algo_r(map, x, y + 1) == 1)
        map->chara[x][y] = 'o';

    if (map->chara[x][y] == 'o')
        return 1;
    return 0;
}