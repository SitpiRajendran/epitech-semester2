/*
** EPITECH PROJECT, 2019
** PSU Navy
** File description:
** main.c
*/

#include "my.h"

int main (int ac, char **av)
{
    if (ac < 2 || ac > 3) {
        error("Not enougth or too many arguments.\n");
        return (84);
    }
    if (ac == 2 && my_strcmp(av[1], "-h") != 0) {
        if (orstr(av[1]) == NULL)
            return (84);
        player_one(av[1]);
    }
    if (ac == 2 && my_strcmp(av[1], "-h") == 0)
        help();
    if (ac == 3) {
        if (orstr(av[2]) == NULL)
            return (84);
        if (player_two(av[1], av[2]) == 84)
            return (84);
    }
    return (0);
}
