/*
** EPITECH PROJECT, 2019
** CPE Duostumper 5
** File description:
** get arguments
*/

#include "tictactoe.h"

int my_getnbr(char *str)
{
    int st = 0;
    int x = 0;

    if (str[0] == '\0')
        return (0);
    for (; str[x] != '\0'; x++) {
        if (str[x] >= '0' && str[x] <= '9')
            st = st * 10 + (str[x] - '0');
        else if (str[x] < '0' || str[x] > '9')
            return (-2);
    }
    return (st);
}

char get_chara(char *av, t_infos *game)
{
    if (strlen(av) != 1) {
        game->error = true;
        return 'X';
    }
    return av[0];
}

int get_args(char **av, t_infos *game)
{
    game->one = 'X';
    game->two = 'O';
    game->size = 3;

    for (int i = 1; av[i] != NULL; i++) {
        if (strcmp(av[i], "-p1") == 0) {
            game->one = get_chara(av[++i], game);
            continue;
        } else if (strcmp(av[i], "-p2") == 0) {
            game->two = get_chara(av[++i], game);
            continue;
        }
        if (strcmp(av[i], "-s") == 0)
            game->size = my_getnbr(av[++i]);
        else
            game->error = true;
    }
    if (game->error == true || game->size < 0 || game->one == game->two)
        return error("Arguments error");
    return 0;
}
