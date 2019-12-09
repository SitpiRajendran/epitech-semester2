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
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

typedef struct s_map {
    char **chara;
    int **num;
    int x_max;
    int y_max;
    int error;
} t_map;

int error(char *str);
int no_solution(char * str);

int solver(char *av);
int algo_u(t_map *map, int x, int y);
int algo_d(t_map *map, int x, int y);
int algo_l(t_map *map, int x, int y);
int algo_r(t_map *map, int x, int y);

t_map get_map(char *av);
char *init(char *filepath);

void mem_arr(t_map *map);
int get_line(char *str);
int get_colonn(char *str);
void strtoarr(char *str, t_map *map);

void print_map(t_map map);

#endif
