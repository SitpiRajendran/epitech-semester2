/*
** EPITECH PROJECT, 2019
** PSU_Tetris
** File description:
** Main
*/

#include "tetris.h"

int main(int ac, char **av, char const **env)
{
    if (env[0] == NULL)
        return error("There is no Environment");
    if (ac == 2 && my_strcmp(av[1], "--help") == 0)
        return help(av[0]);

    return launch(av, ac);
}
