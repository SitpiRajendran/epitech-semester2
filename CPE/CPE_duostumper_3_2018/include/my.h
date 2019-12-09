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

typedef struct numbers_t
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
} numbers;

void my_putchar(char c);
int my_putstr(char const *str);
int my_strcmp(char const *s1, char const *s2);
int my_getnbr(char *str);
int my_strisnum(char *str);

int error(char *str);

void init_line(numbers *num);

char get_letter(char *str, int nbr);

void dispatch_0_4(char base_nbr, int line, char *text);

void print_while(char *str, char *text);

void freeall(numbers *num);

int my_atoi(char c);

void printnum_zero(char c, int line);
void printnum_one(char c, int line);
void printnum_two(char c, int line);
void printnum_three(char c, int line);
void printnum_four(char c, int line);
void printnum_five(char c, int line);
void printnum_six(char c, int line);
void printnum_seven(char c, int line);
void printnum_eight(char c, int line);
void printnum_nine(char c, int line);
#endif
