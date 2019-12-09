/*
** EPITECH PROJECT, 2019
** CPE_dante
** File description:
** Main
*/

#include "solver.h"

int main(int ac, char **av)
{
    if (ac != 2)
        return error("Argument Error : Number of Argument invalid\n");
    return solver(av[1]);
}