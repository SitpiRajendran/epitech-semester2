/*
** EPITECH PROJECT, 2019
** check_way.c
** File description:
** check_way.c
*/

#include "generator.h"

int check_way(maze *maze)
{
    if (maze->maze[maze->pos_y - 1][maze->pos_x] == ' ') {
        maze->pos_y -= 1;
        return (1);
    }
    if (maze->maze[maze->pos_y + 1][maze->pos_x] == ' ') {
        maze->pos_y += 1;
        return (1);
    }
    if (maze->maze[maze->pos_y][maze->pos_x + 1] == ' ') {
        maze->pos_x += 1;
        return (1);
    }
    if (maze->maze[maze->pos_y][maze->pos_x - 1] == ' ') {
        maze->pos_x -= 1;
        return (1);
    }
    return (0);
}
