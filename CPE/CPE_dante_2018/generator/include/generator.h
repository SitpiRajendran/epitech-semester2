/*
** EPITECH PROJECT, 2019
** CPE duostumper2
** File description:
** generator H
*/

#ifndef MY_H_
#define MY_H_

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

typedef struct maze_t
{
    char **maze;
    int nb_rows;
    int nb_cols;
    int left;
    int right;
    int top;
    int down;
    int pos_x;
    int pos_y;
} maze;

int error(char *str);
char **malloc_array(int nb_rows, int nb_cols);
char **create_maze(int x, int y);
int generator(maze *maze, int perfect);
void print_array(char **tab);
int check_direction(maze *maze);
int move_back(maze *maze);
void make_cluster(maze *maze, int row, int col);
void move(maze *maze);
int check_way(maze *maze);

#endif
