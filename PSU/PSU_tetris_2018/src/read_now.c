/*
** EPITECH PROJECT, 2019
** PSU Tetris
** File description:
** Read Now
*/

#include "tetris.h"

int read_now(struct termios *cara)
{
    char buffer[1];

    cara->c_lflag &= ~ICANON;
    cara->c_cc[VMIN] = 1;
    cara->c_cc[VTIME] = 0;
    if (tcsetattr(0, 0, cara) == -1)
        return 1;
    read(0, buffer, 1);
    return 0;
}