/*
** EPITECH PROJECT, 2019
** CPE duostumper6
** File description:
** error.c
*/

#include "crocus.h"

int error(char *str)
{
    write (2, str, strlen(str));
    return 84;
}
