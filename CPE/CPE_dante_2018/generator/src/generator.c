/*
** EPITECH PROJECT, 2019
** generator.c
** File description:
** generator.c
*/

#include "generator.h"

void open_start(maze *maze)
{
    maze->maze[0][0] = '*';
    maze->maze[0][1] = '*';
}

void open_end(maze *maze)
{
    maze->maze[maze->nb_rows - 1][maze->nb_cols - 1] = '*';
    maze->maze[maze->nb_rows - 1][maze->nb_cols - 2] = '*';
    maze->maze[maze->nb_rows - 2][maze->nb_cols - 2] = '*';
    if ((maze->nb_rows % 2) == 0) {
        maze->maze[maze->nb_rows - 3][maze->nb_cols - 2] = '*';
        for (int i = maze->nb_cols - 3; i > 0; i--)
            maze->maze[maze->nb_rows - 1][i] = '*';
    }
    if ((maze->nb_cols % 2) == 0) {
        for (int i = maze->nb_rows - 3; i > 0; i--)
            maze->maze[i][maze->nb_cols - 1] = '*';
    }
    if ((maze->nb_rows % 2) != 0 && (maze->nb_cols % 2) == 0) {
        maze->maze[maze->nb_rows - 1][maze->nb_cols - 2] = 'X';
        maze->maze[maze->nb_rows - 2][maze->nb_cols - 1] = '*';
    }
}

void make_cluster(maze *maze, int row, int col)
{
    maze->pos_x = col;
    maze->pos_y = row;
    while (42) {
        if (check_direction(maze) == 0)
            return;
        move(maze);
    }
}

int generator(maze *maze, int perfect)
{
    char **map = NULL;

    maze->maze = create_maze(maze->nb_cols, maze->nb_rows);
    make_cluster(maze, 1, 1);
    while (move_back(maze) == 1);
    open_start(maze);
    open_end(maze);
    print_array(maze->maze);
    for (int i = 0; maze->maze[i] != NULL; i++)
        free(maze->maze[i]);
    free(maze->maze);
}
