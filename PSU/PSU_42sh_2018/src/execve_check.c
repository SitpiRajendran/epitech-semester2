/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** all fork functions
*/

#include "my.h"

void display_exec_error(mini_t *mini_s)
{
    switch (errno) {
    case ENOEXEC:
        my_putstr(mini_s->command, 2);
        my_putstr(": Exec format error. Wrong Architecture.\n", 2);
        break;
    case EACCES:
        my_putstr(mini_s->command, 2);
        my_putstr(": Permission denied.\n", 2);
        break;
    default:
        my_putstr(mini_s->command, 2);
        my_putstr(": Permission denied.\n", 2);
        break;
    }
}