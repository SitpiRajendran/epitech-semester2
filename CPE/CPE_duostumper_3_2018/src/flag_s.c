/*
** EPITECH PROJECT, 2019
** duo stumper
** File description:
** handle s flag
*/

#include "my.h"

char get_letter(char *str, int nbr)
{
    int len = strlen(str);

    nbr = nbr % len;
    return (str[nbr]);
}
