/*
** EPITECH PROJECT, 2019
** PSU_Navy
** File description:
** my.h
*/

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

typedef struct map_coordonates_t
{
    char *map;
    int x1;
    int y1;
    int x2;
    int y2;
} map_coord;

#ifndef MY_H_
	#define MY_H_

void my_putstr(char *str);

int my_strlen(char *str);

int my_strcmp(char const *s1, char const *s2);

int my_put_nbr(int nb);

void my_putchar(char c);

int my_getnbr(char *str);

void error(char *str);

void help(void);

char *orstr(char *filepath);

char **init_map(void);

char **first_add_map(char *str, char **map);

char **map_add(map_coord co, char **map);

void print_map(char **map);

int verif_boat_nb(char *map);

char *get_one_line(char *map, int x);

int get_posx_one(char *str);

int get_posy_one(char *str);

int get_posx_two(char *str);

int get_posy_two(char *str);

int player_one(char *path);

int player_two(char *strpid, char *path);

char *get_next_line(int fd);

void game(char **my_map, char **enemy_map, char *input, int pid);

int verif_coordinates(map_coord co);

int get_x(char *str);

int get_y(char *str);

char touch(char **map, int x, int y);

int win(char **map);

#endif /* !MY_H_ */

