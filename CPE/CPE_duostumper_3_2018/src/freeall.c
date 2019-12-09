/*
** EPITECH PROJECT, 2019
** duo stumper
** File description:
** free all
*/

#include "my.h"

void freeall(numbers *num)
{
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
}
