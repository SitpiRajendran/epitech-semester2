/*
** EPITECH PROJECT, 2019
** duostumper6
** File description:
** printnum.c
*/

#include "crocus.h"

int printnum_five(char c, int line)
{
    numbers_t template;

    if (c == 0)
        return 84;
    init_line(&template);
    for (int i = 0; template.five[line][i] != '\0'; i++) {
        if (template.five[line][i] == ' ')
            write (1, " ", 1);
        else
            write (1, &c, 1);
    }
    freeall(&template);
    return 0;
}

int printnum_six(char c, int line)
{
    numbers_t template;

    if (c == 0)
        return 84;
    init_line(&template);
    for (int i = 0; template.six[line][i] != '\0'; i++) {
        if (template.six[line][i] == ' ')
            write (1, " ", 1);
        else
            write (1, &c, 1);
    }
    freeall(&template);
    return 0;
}

int printnum_seven(char c, int line)
{
    numbers_t template;

    if (c == 0)
        return 84;
    init_line(&template);
    for (int i = 0; template.seven[line][i] != '\0'; i++) {
        if (template.seven[line][i] == ' ')
            write (1, " ", 1);
        else
            write (1, &c, 1);
    }
    freeall(&template);
    return 0;
}

int printnum_eight(char c, int line)
{
    numbers_t template;

    if (c == 0)
        return 84;
    init_line(&template);
    for (int i = 0; template.eight[line][i] != '\0'; i++) {
        if (template.eight[line][i] == ' ')
            write (1, " ", 1);
        else
            write (1, &c, 1);
    }
    freeall(&template);
    return 0;
}

int printnum_nine(char c, int line)
{
    numbers_t template;

    if (c == 0)
        return 84;
    init_line(&template);
    for (int i = 0; template.nine[line][i] != '\0'; i++) {
        if (template.nine[line][i] == ' ')
            write (1, " ", 1);
        else
            write (1, &c, 1);
    }
    freeall(&template);
    return 0;
}
