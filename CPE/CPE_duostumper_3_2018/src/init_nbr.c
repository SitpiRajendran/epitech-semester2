/*
** EPITECH PROJECT, 2019
** duo stumper 3
** File description:
** initialize number line
*/

#include "my.h"

void init_line_2(numbers *num)
{
    num->zero[0] = " 000 ";
    num->one[0] = " 000 ";
    num->two[0] = " 000 ";
    num->three[0] = "0000 ";
    num->four[0] = "  00 ";
    num->five[0] = "00000";
    num->six[0] = " 000 ";
    num->seven[0] = "00000";
    num->eight[0] = " 000 ";
    num->nine[0] = " 000 ";
    num->zero[1] = "0   0";
    num->one[1] = "0 00 ";
    num->two[1] = "0   0";
    num->three[1] = "    0";
    num->four[1] = " 0 0 ";
    num->five[1] = "0    ";
    num->six[1] = "0    ";
    num->seven[1] = "    0";
    num->eight[1] = "0   0";
    num->nine[1] = "0   0";
}

void init_line_3(numbers *num)
{
    num->zero[2] = "0   0";
    num->one[2] = "  00 ";
    num->two[2] = "   0 ";
    num->three[2] = " 000 ";
    num->four[2] = "0  0 ";
    num->five[2] = "0000 ";
    num->six[2] = "0000 ";
    num->seven[2] = "   0 ";
    num->eight[2] = " 000 ";
    num->nine[2] = " 0000";
}

void init_line_4(numbers *num)
{
    num->zero[3] = "0   0";
    num->one[3] = "  00 ";
    num->two[3] = " 0   ";
    num->three[3] = "    0";
    num->four[3] = "00000";
    num->five[3] = "    0";
    num->six[3] = "0   0";
    num->seven[3] = "  0  ";
    num->eight[3] = "0   0";
    num->nine[3] = "    0";
}

void init_line_5(numbers *num)
{
    num->zero[4] = " 000 ";
    num->one[4] = " 0000";
    num->two[4] = "00000";
    num->three[4] = "0000 ";
    num->four[4] = "   0 ";
    num->five[4] = "0000 ";
    num->six[4] = " 000 ";
    num->seven[4] = " 0   ";
    num->eight[4] = " 000 ";
    num->nine[4] = " 000 ";
}

void init_line(numbers *num)
{
    num->zero = malloc(sizeof(char *) * 7);
    num->one = malloc(sizeof(char *) * 7);
    num->two = malloc(sizeof(char *) * 7);
    num->three = malloc(sizeof(char *) * 7);
    num->four = malloc(sizeof(char *) * 7);
    num->five = malloc(sizeof(char *) * 7);
    num->six = malloc(sizeof(char *) * 7);
    num->seven = malloc(sizeof(char *) * 7);
    num->eight = malloc(sizeof(char *) * 7);
    num->nine = malloc(sizeof(char *) * 7);
    init_line_2(num);
    init_line_3(num);
    init_line_4(num);
    init_line_5(num);
}
