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
#include <string.h>

typedef struct numbers_s
{
    char **zero;
    char **one;
    char **two;
    char **three;
    char **four;
    char **five;
    char **six;
    char **seven;
    char **eight;
    char **nine;
} numbers_t;

void my_putchar(char c);
int my_putstr(char const *str);
int my_strcmp(char const *s1, char const *s2);
int my_getnbr(char *str);
int my_strisnum(char *str);

int error(char *str);

char **malloc_verif(void);
int init_line(numbers_t *num);
int init_line_3(numbers_t *num);
int init_line_4(numbers_t *num);
int init_line_5(numbers_t *num);

char get_letter(char *str, int nbr);

void dispatch_0_4(char base_nbr, int line, char *text);

int print_while(char *str, char *text);

int freeall(numbers_t *num);

int my_atoi(char c);

int printnum_zero(char c, int line);
int printnum_one(char c, int line);
int printnum_two(char c, int line);
int printnum_three(char c, int line);
int printnum_four(char c, int line);
int printnum_five(char c, int line);
int printnum_six(char c, int line);
int printnum_seven(char c, int line);
int printnum_eight(char c, int line);
int printnum_nine(char c, int line);
#endif
