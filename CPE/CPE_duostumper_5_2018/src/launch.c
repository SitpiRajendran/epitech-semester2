/*
** EPITECH PROJECT, 2019
** DuoStumper 5
** File description:
** launch game
*/

#include "tictactoe.h"

int init_game(char **av)
{
    int error;
    t_infos game_infos;

    error = get_args(av, &game_infos);
    if (error == 84)
        return 84;
    game(&game_infos);
}
