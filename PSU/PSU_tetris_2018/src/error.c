/*
** EPITECH PROJECT, 2019
** PSU Tetris
** File description:
** error.c
*/

#include "tetris.h"

int error(char *str)
{
    write (2, str, my_strlen(str));
    return 84;
}

int write_zero(char *str)
{
    write (1, str, my_strlen(str));
    return 0;
}
