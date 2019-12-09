/*
** EPITECH PROJECT, 2019
** PSU my_ls
** File description:
** Main
*/

#include "my.h"

int main (int ac, char **av)
{
    if (ac == 1)
        simple_tree(".");

    if (ac == 2) {
        if (av[1][0] != '-')
            simple_tree(av[1]);
        else
            options(av[1], ".");
    }
    if (ac == 3)
        options(av[1], av[2]);
    return (0);
}
