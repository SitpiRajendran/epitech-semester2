/*
11;rgb:0000/0000/0000** EPITECH PROJECT, 2019
** duo stumper
** File description:
** place player avatar
*/

#include "my.h"

char **place_avatar(char **board, coor *co, char **infos, int player)
{
    co->x = my_getnbr(infos[1]);

    while (board[co->x][co->y] != '.' && co->x >= 0)
        co->x--;
    board[co->x][co->y] = infos[player][0];
    return board;
}
