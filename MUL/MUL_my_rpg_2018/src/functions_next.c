/*
** EPITECH PROJECT, 2018
** Kaminari | MyLibC - My String Compare
** File description:
** A function that compare two strings
*/

#include "rpg.h"

int my_strcmp(const char *s1, const char *s2)
{
    size_t i = 0;
    size_t j = 0;

    for (; s1[i] == s2[j]; i += 1, j += 1)
        if (s1[i] == '\0')
            return (s1[i] - s2[j]);
    return (s1[j] - s2[j]);
}
