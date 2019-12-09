/*
** EPITECH PROJECT, 2019
** CPE duostumper3
** File description:
** error.c
*/

#include "generator.h"

int error(char *str)
{
    write (2, str, strlen(str));
    return (84);
}
