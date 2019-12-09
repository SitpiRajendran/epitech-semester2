/*
** EPITECH PROJECT, 2019
** check_around.c
** File description:
** check_around.c
*/

#include "generator.h"

void check_direction2(maze *maze)
{
    if ((maze->pos_y - 2) > 0)
        if (maze->maze[maze->pos_y - 2][maze->pos_x] == 'X' &&
            maze->maze[maze->pos_y - 1][maze->pos_x] == 'X' &&
            maze->maze[maze->pos_y - 1][maze->pos_x - 1] == 'X')
            if (maze->maze[maze->pos_y - 1][maze->pos_x + 1] == 'X' &&
                maze->maze[maze->pos_y - 2][maze->pos_x + 1] == 'X' &&
                maze->maze[maze->pos_y - 2][maze->pos_x - 1] == 'X')
                maze->top = 1;
    if ((maze->pos_y + 2) < maze->nb_rows - 1)
        if (maze->maze[maze->pos_y + 2][maze->pos_x] == 'X' &&
            maze->maze[maze->pos_y + 2][maze->pos_x - 1] == 'X' &&
            maze->maze[maze->pos_y + 2][maze->pos_x + 1] == 'X')
            if (maze->maze[maze->pos_y + 1][maze->pos_x - 1] == 'X' &&
                maze->maze[maze->pos_y + 1][maze->pos_x + 1] == 'X' &&
                maze->maze[maze->pos_y + 1][maze->pos_x] == 'X')
                maze->down = 1;
}

int check_direction3(maze *maze)
{
    if ((maze->pos_x + 2) < maze->nb_cols - 1)
        if (maze->maze[maze->pos_y][maze->pos_x + 2] == 'X' &&
            maze->maze[maze->pos_y - 1][maze->pos_x + 2] == 'X' &&
            maze->maze[maze->pos_y + 1][maze->pos_x + 2] == 'X')
            if (maze->maze[maze->pos_y - 1][maze->pos_x + 1] == 'X' &&
                maze->maze[maze->pos_y + 1][maze->pos_x + 1] == 'X' &&
                maze->maze[maze->pos_y][maze->pos_x + 1] == 'X')
                maze->right = 1;
    if ((maze->pos_x - 2) > 0)
        if (maze->maze[maze->pos_y][maze->pos_x - 2] == 'X' &&
            maze->maze[maze->pos_y - 1][maze->pos_x - 2] == 'X' &&
            maze->maze[maze->pos_y + 1][maze->pos_x - 2] == 'X')
            if (maze->maze[maze->pos_y + 1][maze->pos_x - 1] == 'X' &&
                maze->maze[maze->pos_y - 1][maze->pos_x - 1] == 'X' &&
                maze->maze[maze->pos_y][maze->pos_x - 1] == 'X')
                maze->left = 1;
}

int check_direction(maze *maze)
{
    maze->right = 0;
    maze->left = 0;
    maze->top = 0;
    maze->down = 0;
    check_direction3(maze);
    check_direction2(maze);
    if (maze->right == 0 && maze->left == 0 &&
        maze->top == 0 && maze->down == 0)
        return (0);
    else
        return (1);
}
