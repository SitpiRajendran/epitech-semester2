/*
** EPITECH PROJECT, 2019
** CPE duostumper
** File description:
** tictactoe H
*/

#ifndef MY_H_
#define MY_H_

#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <inttypes.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

typedef struct s_infos {
    char one;
    char two;
    int size;
    bool error;
} t_infos;


int error(char *);

int my_getnbr(char *);

int get_args(char **, t_infos *);
int get_pos_y(char *);
int get_pos_x(char *);

int init_game(char **);

char **init_tab(int);
void print_tab(char **, int);

int game(t_infos *);
int win(char **, t_infos *);

#endif
