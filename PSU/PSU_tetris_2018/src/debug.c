/*
** EPITECH PROJECT, 2019
** PSU Tetris
** File description:
** debug
*/

#include "tetris.h"

int count_list(elem_t *start)
{
    elem_t *tmp = start;
    int i = 0;

    for (; tmp != NULL; i++)
        tmp = tmp->next;

    return i;
}

void display_debug(elem_t *tmp)
{
    write(1, "Size ", 5);
    my_put_nbr(tmp->row);
    write(1, "*", 1);
    my_put_nbr(tmp->cols);
    write(1, " :  Color ", 10);
    my_put_nbr(tmp->color);
    write(1, " :\n", 3);
    write(1, tmp->obj, my_strlen(tmp->obj));
}

void debug_tetriminos(elem_t *start)
{
    struct termios cara;
    elem_t *tmp = start;

    write(1, "\nTetriminos :  ", 15);
    my_put_nbr(count_list(start));
    while (tmp != NULL) {
        write(1, "\nTetriminos :  Name ", 20);
        write(1, tmp->name, my_strlen(tmp->name));
        write (1, " :  ", 4);
        if (tmp->cols == -2) {
            write(1, "Error", 5);
            tmp = tmp->next;
            continue;
        }
        display_debug(tmp);
        tmp = tmp->next;
    }
    write(1, "\nPress any key to start Tetris\n", 31);
    tcgetattr(0, &cara);
    read_now(&cara);
}

void put_keys(int key, char *str)
{
    char c = key;

    write(1, "\nKey ", 5);
    write(1, str, my_strlen(str));
    write(1, " :  ", 4);
    if (key == 258)
        write(1, "^EOA", 4);
    if (key == 259)
        write(1, "^EOB", 4);
    if (key == 260)
        write(1, "^EOD", 4);
    if (key == 261)
        write(1, "^EOC", 4);
    if (key < 127 && key > 32)
        write(1, &c, 1);
    if (c == ' ')
        write (1, "(space)", 7);
}

int debug(t_params *params, elem_t *start)
{
    char *string;

    write(1, "*** DEBUG MODE ***", 18);
    put_keys(params->left, "Left");
    put_keys(params->right, "Right");
    put_keys(params->turn, "Turn");
    put_keys(params->drop, "Drop");
    put_keys(params->quit, "Quit");
    put_keys(params->pause, "Pause");
    write(1, "\nNext :  ", 9);
    (params->next == 1) ? (string = "Yes") : (string = "No");
    write(1, string, my_strlen(string));
    write(1, "\nLevel :  ", 10);
    my_put_nbr(params->level);
    write(1, "\nSize :  ", 9);
    my_put_nbr(params->rows);
    write(1, "*", 1);
    my_put_nbr(params->cols);
    debug_tetriminos(start);
    return 0;
}