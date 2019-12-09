/*
** EPITECH PROJECT, 2019
** CPE duostumper2
** File description:
** my h
*/

#ifndef MY_H_
#define MY_H_

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct coordo_s
{
    int x;
    int y;
} coor;

void my_putchar(char c);

int my_putstr(char const *str);

int my_strcmp(char const *s1, char const *s2);

int my_getnbr(char *str);

char **arguments(char **infos, int ac, char **av);

char **place_avatar(char **board, coor *co, char **infos, int player);

int check_victory(char **board, int x, int y, char **infos);

int check_victory_diagonals(char **board, int x, int y, char **infos);

char **init_map(int x, int y);

void print_map(char **board, int x, int y);
#endif
