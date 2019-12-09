/*
** EPITECH PROJECT, 2019
** CPE_dante
** File description:
** Main
*/

#include "pokemon.h"

int main(int ac, char **av)
{
    if (ac != 3)
        return error("Argument Error : Number of Argument invalid\n");
    return start_game(av);
}
