/*
** EPITECH PROJECT, 2019
** CPE dante
** File description:
** error.c
*/

#include "pokemon.h"

int error(char *str)
{
    write (2, str, strlen(str));
    return 84;
}

int no_solution(char * str)
{
    write (1, str, strlen(str));
    return 0;
}
