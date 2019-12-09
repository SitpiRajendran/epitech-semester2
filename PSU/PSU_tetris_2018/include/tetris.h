/*
** EPITECH PROJECT, 2019
** PSU Tetris
** File description:
** H
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
#include <dirent.h>
#include <inttypes.h>
#include <ncurses.h>
#include <termios.h>

typedef struct s_params {
    int level;
    int left;
    int right;
    int turn;
    int drop;
    int quit;
    int pause;
    int next;
    int rows;
    int cols;
    int debug;
    int error;
} t_params;

typedef struct s_elem
{
    char *name;
    int row;
    int cols;
    int color;
    char *obj;
    struct s_elem *next;
} elem_t;

int error(char *);
int write_zero(char *);

int my_strcmp(char const *, char const *);
int my_strlen(char const *str);
int my_getnbr(char *str);
void my_put_nbr(int nb);
char *my_strcat(char *dest, char const *scr);

int help(char *str);

void init_struct(t_params *params);

char *get_name(char *type);
int get_opt(char *type, char *name);
void two_hyphen(char *type, t_params *prm);
int one_hyphen(char , char *, t_params *);
void get_args(t_params *, char **, int);

void get_map(t_params *params, char *type);

int launch(char **av, int ac);

int debug(t_params *params, elem_t *start);

int get_online(char *str, int space);
char *get_name_m(char *str);
char *get_obj(char *str);
void verif_tetriminos(elem_t *new);

void addfirst(elem_t **start, char *name, char *str);

elem_t *init_minos(t_params *params);

int read_now(struct termios *cara);

void gamelaunch(t_params *game);
#endif
