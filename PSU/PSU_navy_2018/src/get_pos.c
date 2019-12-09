/*
** EPITECH PROJECT, 2019
** PSU Navy
** File description:
** getpos
*/

#include "my.h"

int get_posx_one(char *str)
{
    return (str[2] - 64);
}

int get_posy_one(char *str)
{
    return (str[3] - 48);
}

int get_posx_two(char *str)
{
    return (str[5] - 64);
}

int get_posy_two(char *str)
{
    return (str[6] - 48);
}