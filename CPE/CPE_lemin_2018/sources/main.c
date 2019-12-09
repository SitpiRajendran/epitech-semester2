/*
** EPITECH PROJECT, 2019
** CPE_lemin_2018
** File description:
** main
*/

#include "my.h"

int main(int ac, char **av)
{
    for (int a = 0; av[a] != NULL; a++)
    if (ac != 1)
        return (84);
    if (lem_in() == 84)
        return (84);
    return (0);
}