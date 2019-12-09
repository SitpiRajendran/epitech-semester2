/*
** EPITECH PROJECT, 2019
** duostumper6
** File description:
** malloc and verif
*/

#include "crocus.h"

char **malloc_verif(void)
{
    char **tab = malloc(sizeof(char *) * 7);

    if (tab == NULL)
        exit(84);

    return tab;
}
