/*
** EPITECH PROJECT, 2019
** duo stumper
** File description:
** free all
*/

#include "crocus.h"

int freeall(numbers_t *num)
{
    if (num == NULL)
        return (84);
    free(num->zero);
    free(num->one);
    free(num->two);
    free(num->three);
    free(num->four);
    free(num->five);
    free(num->six);
    free(num->seven);
    free(num->eight);
    free(num->nine);
    return (0);
}
