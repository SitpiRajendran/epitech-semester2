/*
** EPITECH PROJECT, 2019
** DuoStumper
** File description:
** Winning condition
*/

#include "tictactoe.h"

int full(char **tab, int size)
{
    int stop = 0;

    for (int i = 0; tab[i] != NULL && stop == 0; i++)
        for (int j = 0; j != size && stop == 0; j++)
            (tab[i][j] == ' ') ? (stop = 1) : (stop = stop);

    if (stop == 1)
        return 0;
    return 1;
}

int horizontal(char **tab, t_infos *info)
{
    int nb_sign = 0;
    int size = info->size;

    for (int i = 0; tab[i] != NULL && nb_sign != info->size; i++) {
        nb_sign = 0;
        for (int j = 0; j < size && nb_sign != info->size && nb_sign != -2; j++)
            (tab[i][j] == info->one) ? (nb_sign += 1) : (nb_sign = -2);
    }

    if (nb_sign == info->size)
        return 1;

    for (int i = 0; tab[i] != NULL && nb_sign != info->size; i++) {
        nb_sign = 0;
        for (int j = 0; j < size && nb_sign != info->size && nb_sign != -2; j++)
            (tab[i][j] == info->two) ? (nb_sign += 1) : (nb_sign = -2);
    }
    if (nb_sign == info->size)
        return 2;
    return 0;
}

int vertical(char **tab, t_infos *info)
{
    int nb_sign = 0;
    int size = info->size;

    for (int j = 0; j != size && nb_sign != info->size; j++) {
        nb_sign = 0;
        for (int i = 0; i != size && nb_sign != info->size; i++)
            (tab[i][j] == info->one) ? (nb_sign += 1) : (nb_sign = -2);
    }

    if (nb_sign == info->size)
        return 1;

    for (int j = 0; j != size && nb_sign != info->size; j++) {
        nb_sign = 0;
        for (int i = 0; i != size && nb_sign != info->size; i++)
            (tab[i][j] == info->two) ? (nb_sign += 1) : (nb_sign = -2);
    }
    if (nb_sign == info->size)
        return 2;
    return 0;
}

int diagonal(char **tab, t_infos *info)
{
    int nb_sign = 0;

    for (int i = 0, j = 0; i != info->size; i++, j++)
        (tab[i][j] == info->one) ? (nb_sign += 1) : (nb_sign = -2);
    if (nb_sign == info->size)
        return 1;
    for (int i = 0, j = info->size - 1; i != info->size; i++, j--)
        (tab[i][j] == info->one) ? (nb_sign += 1) : (nb_sign = -2);
    if (nb_sign == info->size)
        return 1;

    for (int i = 0, j = 0; i != info->size; i++, j++)
        (tab[i][j] == info->two) ? (nb_sign += 1) : (nb_sign = -2);
    if (nb_sign == info->size)
        return 2;
    for (int i = 0, j = info->size - 1; i != info->size; i++, j--)
        (tab[i][j] == info->two) ? (nb_sign += 1) : (nb_sign = -2);
    if (nb_sign == info->size)
        return 2;
    return 0;
}


int win(char **tab, t_infos *infos)
{
    int diago = diagonal(tab, infos);
    int vert = vertical(tab, infos);
    int hori = horizontal(tab, infos);
    int fulled = full(tab, infos->size);

    if (fulled == 1) {
        print_tab(tab, infos->size);
        write(1, "No one win, that's sad\n", 23);
        return 4;
    }
    if (diago == 1 || vert == 1 || hori == 1) {
        print_tab(tab, infos->size);
        write (1, "Player 1 won !\n", 15);
        return 1;
    } else if (diago == 2 || vert == 2 || hori == 2) {
        print_tab(tab, infos->size);
        write (1, "Player 2 won !\n", 15);
        return 2;
    }

    return 0;
}
