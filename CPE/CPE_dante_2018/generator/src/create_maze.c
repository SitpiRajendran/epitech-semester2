/*
** EPITECH PROJECT, 2019
** create_maze.c
** File description:
** create_maze.c
*/

#include "generator.h"

char **create_maze(int x, int y)
{
    char **maze = NULL;

    maze = malloc_array(x + 1, y + 1);
    for (int row = 0; row < y; row++)
        for (int col = 0; col < x; col++) {
            maze[row][col] = 'X';
            maze[row][col + 1] = '\0';
        }
    maze[y] = NULL;
    return (maze);
}
