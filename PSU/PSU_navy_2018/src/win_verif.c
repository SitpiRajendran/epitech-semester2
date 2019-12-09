/*
** EPITECH PROJECT, 2019
** PSU Navy
** File description:
** Winning verif
*/

#include "my.h"

char touch(char **map, int x, int y)
{
    if (map[y][x] != '.') {
        my_putchar(x + 'A' - 1);
        my_put_nbr(y);
        my_putstr(": hit\n");
        return ('x');
    } else {
        my_putchar(x + 'A' - 1);
        my_put_nbr(y);
        my_putstr(": missed\n");
        return ('o');
    }
}

int win(char **map)
{
    char ca;
    int x = 0;
    for (int i = 0; i != 8; i++) {
        for (int j = 0; j != 8; j++) {
            ca = map[i][j];
            (ca > '1' && ca < '6') ? x++ : (x = x);
        }
        if (x == 0)
            return 1;
    }
    return 0;
}
