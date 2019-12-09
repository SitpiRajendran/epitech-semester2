/*
** EPITECH PROJECT, 2019
** CPE_dante
** File description:
** Main
*/

#include "tictactoe.h"

int main(int ac, char **av)
{
    if (ac > 7 || ac % 2 != 1)
        return error("Argument Error : Number of Arguments invalid\n");
    return init_game(av);
}
