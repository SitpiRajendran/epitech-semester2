/*
** EPITECH PROJECT, 2019
** DuoStumper
** File description:
** game
*/

#include "tictactoe.h"

char **player_one(t_infos *info, char **tab)
{
    int ret;
    char *str = NULL;
    size_t size = 0;
    int x;
    int y;

    while (1) {
        write (1, "Player 1>", 9);
        if ((ret = getline(&str, &size, stdin)) == -1)
            exit (84);
        x = get_pos_x(str);
        y = get_pos_y(str);
        if (x == -2 || y == -2 || x >= info->size || y >= info->size);
        else if (tab[y][x] == ' ') {
            tab[y][x] = info->one;
            return tab;
        }
    }
    return tab;
}

char **player_two(t_infos *info, char **tab)
{
    int ret;
    char *str = NULL;
    size_t size = 0;
    int x;
    int y;

    while (1) {
        write (1, "Player 2>", 9);
        if ((ret = getline(&str, &size, stdin)) == -1)
            exit (84);
        x = get_pos_x(str);
        y = get_pos_y(str);
        if (x == -2 || y == -2 || x >= info->size || y >= info->size);
        else if (tab[y][x] == ' ') {
            tab[y][x] = info->two;
            return tab;
        }
    }
    return tab;
}

int game(t_infos *info)
{
    char **tab = init_tab(info->size);

    while (win(tab, info) == 0) {
        print_tab(tab, info->size);
        tab = player_one(info, tab);
        if (win(tab, info) == 1)
            break;
        print_tab(tab, info->size);
        tab = player_two(info, tab);
    }
}
