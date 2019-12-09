/*
** EPITECH PROJECT, 2019
** PSU Tetris
** File description:
** Launch
*/

#include "tetris.h"

int launch(char **av, int ac)
{
    t_params params;
    elem_t *start = NULL;

    init_struct(&params);
    get_args(&params, av, ac);
    if (params.error == 1)
        return error("Arguments Error\n");
    start = init_minos(&params);
    if (params.error == 1 || start == NULL)
        return error("Tetriminos Error\n");
    if (params.debug == 1)
        debug(&params, start);
    gamelaunch(&params);
    return 0;
}