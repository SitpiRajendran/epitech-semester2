/*
** EPITECH PROJECT, 2019
** duostumper
** File description:
** printnum.c
*/

#include "my.h"

void printnum_five(char c, int line)
{
    numbers template;

    init_line(&template);
    for (int i = 0; template.five[line][i] != '\0'; i++) {
        if (template.five[line][i] == ' ')
            write (1, " ", 1);
        else
            write (1, &c, 1);
    }
    freeall(&template);
}

void printnum_six(char c, int line)
{
    numbers template;

    init_line(&template);
    for (int i = 0; template.six[line][i] != '\0'; i++) {
        if (template.six[line][i] == ' ')
            write (1, " ", 1);
        else
            write (1, &c, 1);
    }
    freeall(&template);
}

void printnum_seven(char c, int line)
{
    numbers template;

    init_line(&template);
    for (int i = 0; template.seven[line][i] != '\0'; i++) {
        if (template.seven[line][i] == ' ')
            write (1, " ", 1);
        else
            write (1, &c, 1);
    }
    freeall(&template);
}

void printnum_eight(char c, int line)
{
    numbers template;

    init_line(&template);
    for (int i = 0; template.eight[line][i] != '\0'; i++) {
        if (template.eight[line][i] == ' ')
            write (1, " ", 1);
        else
            write (1, &c, 1);
    }
    freeall(&template);
}

void printnum_nine(char c, int line)
{
    numbers template;

    init_line(&template);
    for (int i = 0; template.nine[line][i] != '\0'; i++) {
        if (template.nine[line][i] == ' ')
            write (1, " ", 1);
        else
            write (1, &c, 1);
    }
    freeall(&template);
}
