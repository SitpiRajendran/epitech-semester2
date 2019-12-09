/*
** EPITECH PROJECT, 2019
** PSU Tetris
** File description:
** init keys
*/

#include "tetris.h"

void init_struct(t_params *params)
{
    params->level = 1;
    params->left = KEY_LEFT;
    params->right = KEY_RIGHT;
    params->turn = KEY_UP;
    params->drop = KEY_DOWN;
    params->quit = 'q';
    params->pause = ' ';
    params->next = 1;
    params->rows = 20;
    params->cols = 10;
    params->debug = 0;
    params->error = 0;
}