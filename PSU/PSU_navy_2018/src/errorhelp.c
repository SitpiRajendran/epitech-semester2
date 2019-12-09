/*
** EPITECH PROJECT, 2019
** PSU Navy
** File description:
** error-help
*/

#include "my.h"

void error(char *str)
{
    write(2, str, my_strlen(str));
}

void help(void)
{
    my_putstr("USAGE\n\t./navy [first_player_pid] navy_positions\n");
    my_putstr("DESCRIPTION\n\tfirst_player_pid: only for the 2nd player. ");
    my_putstr("pid of the first player.\n\tnavy_positions: file");
    my_putstr("representing the positions of the ships.\n");
}
