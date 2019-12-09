/*
** EPITECH PROJECT, 2019
** move.c
** File description:
** move.c
*/

#include "generator.h"

int move_back(maze *maze)
{
    while (check_direction(maze) == 0) {
        maze->maze[maze->pos_y][maze->pos_x] = '*';
        if (check_way(maze) == 0)
            return (0);
    }
    make_cluster(maze, maze->pos_y, maze->pos_x);
    return (1);
}

int move2(maze *maze, int direction)
{
    if (maze->top == 1 && direction == 1) {
        maze->pos_y -= 1;
        maze->maze[maze->pos_y][maze->pos_x] = ' ';
        maze->pos_y -= 1;
        return (1);
    }
    if (maze->down == 1 && direction == 3) {
        maze->pos_y += 1;
        maze->maze[maze->pos_y][maze->pos_x] = ' ';
        maze->pos_y += 1;
        return (1);
    }
    return (0);
}

void move(maze *maze)
{
    int direction = 0;

    maze->maze[maze->pos_y][maze->pos_x] = ' ';
    while (42) {
        direction = (rand() % 5);
        if (maze->left == 1 && direction == 4) {
            maze->pos_x -= 1;
            maze->maze[maze->pos_y][maze->pos_x] = ' ';
            maze->pos_x -= 1;
            return;
        }
        if (maze->right == 1 && direction == 2) {
            maze->pos_x += 1;
            maze->maze[maze->pos_y][maze->pos_x] = ' ';
            maze->pos_x += 1;
            return;
        }
        if (move2(maze, direction) == 1)
            return;
    }
}
