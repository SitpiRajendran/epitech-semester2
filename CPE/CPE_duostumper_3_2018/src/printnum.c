/*
1;5202;0c** EPITECH PROJECT, 2019
** duostumper
** File description:
** printnum.c
*/

#include "my.h"

void printnum_zero(char c, int line)
{
    numbers template;

    init_line(&template);
    for (int i = 0; template.zero[line][i] != '\0'; i++) {
        if (template.zero[line][i] == ' ')
            write (1, " ", 1);
        else
            write (1, &c, 1);
    }
    freeall(&template);
}

void printnum_one(char c, int line)
{
    numbers template;

    init_line(&template);
    for (int i = 0; template.one[line][i] != '\0'; i++) {
        if (template.one[line][i] == ' ')
            write (1, " ", 1);
        else
            write (1, &c, 1);
    }
    freeall(&template);
}

void printnum_two(char c, int line)
{
    numbers template;

    init_line(&template);
    for (int i = 0; template.two[line][i] != '\0'; i++) {
        if (template.two[line][i] == ' ')
            write (1, " ", 1);
        else
            write (1, &c, 1);
    }
    freeall(&template);
}

void printnum_three(char c, int line)
{
    numbers template;

    init_line(&template);
    for (int i = 0; template.three[line][i] != '\0'; i++) {
        if (template.three[line][i] == ' ')
            write (1, " ", 1);
        else
            write (1, &c, 1);
    }
    freeall(&template);
}

void printnum_four(char c, int line)
{
    numbers template;

    init_line(&template);
    for (int i = 0; template.four[line][i] != '\0'; i++) {
        if (template.four[line][i] == ' ')
            write (1, " ", 1);
        else
            write (1, &c, 1);
    }
    freeall(&template);
}
