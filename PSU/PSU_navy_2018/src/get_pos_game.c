/*
** EPITECH PROJECT, 2019
** PSU_navy
** File description:
** positions in-game
*/

int get_x(char *str)
{
    return (str[0] - '@');
}

int get_y(char *str)
{
    return (str[1] - '1');
}