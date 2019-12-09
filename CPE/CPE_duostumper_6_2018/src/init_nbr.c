/*
65;5601;1c** EPITECH PROJECT, 2019
** duo stumper 4
** File description:
** initialize number line
*/

#include "crocus.h"

void init_line_2(numbers_t *num)
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

int init_line_3(numbers_t *num)
{
    if (num == NULL)
        return 84;
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
    return 0;
}

int init_line_4(numbers_t *num)
{
    if (num == NULL)
        return 84;
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
    return 0;
}

int init_line_5(numbers_t *num)
{
    if (num == NULL)
        return 84;
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
    return 0;
}

int init_line(numbers_t *num)
{
    if (num == NULL)
        return 84;
    num->zero = malloc_verif();
    num->one = malloc_verif();
    num->two = malloc_verif();
    num->three = malloc_verif();
    num->four = malloc_verif();
    num->five = malloc_verif();
    num->six = malloc_verif();
    num->seven = malloc_verif();
    num->eight = malloc_verif();
    num->nine = malloc_verif();
    init_line_2(num);
    init_line_3(num);
    init_line_4(num);
    init_line_5(num);
    return 0;
}
