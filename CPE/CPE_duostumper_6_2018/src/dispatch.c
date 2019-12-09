/*
** EPITECH PROJECT, 2019
** duo stumper
** File description:
** dispatch number
*/

#include "crocus.h"

void dispatch_5_9(char base_nbr, int line, char c)
{
    switch (base_nbr) {
    case '5':
        printnum_five(c, line);
        break;
    case '6':
        printnum_six(c, line);
        break;
    case '7':
        printnum_seven(c, line);
        break;
    case '8':
        printnum_eight(c, line);
        break;
    case '9':
        printnum_nine(c, line);
        break;
    }
}

void dispatch_0_4(char base_nbr, int line, char *text)
{
    char c = get_letter(text, my_atoi(base_nbr));

    switch (base_nbr) {
    case '0':
        printnum_zero(c, line);
        break;
    case '1':
        printnum_one(c, line);
        break;
    case '2':
        printnum_two(c, line);
        break;
    case '3':
        printnum_three(c, line);
        break;
    case '4':
        printnum_four(c, line);
        break;
    }
    dispatch_5_9(base_nbr, line, c);
}
