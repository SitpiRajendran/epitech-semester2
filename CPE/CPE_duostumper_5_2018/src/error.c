/*
** EPITECH PROJECT, 2019
** DuoStumper
** File description:
** TicTacToe
*/

#include "tictactoe.h"

int error(char *str)
{
    write (2, str, strlen(str));
    return 84;
}
