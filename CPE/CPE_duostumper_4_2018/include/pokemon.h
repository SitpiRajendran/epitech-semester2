/*
** EPITECH PROJECT, 2019
** CPE duostumper
** File description:
** pokemon H
*/

#ifndef MY_H_
#define MY_H_

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <inttypes.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

typedef struct s_pokinfo {
    char *name;
    int att;
    int def;
    int spd;
    int lif;
} t_pokinfo;

typedef struct s_pokemons {
    t_pokinfo one;
    t_pokinfo two;
    int error;
} t_pokemons;


int error(char *);

char *my_strlowcase(char *);
int start_game(char **);

t_pokemons init_pokemons(char **);

void parsing_info(char *str, t_pokemons *poks, char **av);

void launch_game(t_pokinfo *one, t_pokinfo *two);
#endif
