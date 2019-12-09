/*
11;rgb:0000/0000/000011;rgb:0000/0000/0000** EPITECH PROJECT, 2019
** CPE_duostumper2
** File description:
** Main
*/

#include "my.h"

int full(char **board, char **ind)
{
    int x = 0;
    int y = 0;
    int aa = 0;

    while (board[x] != NULL) {
        x++;
        while (y != my_getnbr(ind[1])) {
            (board[x][y] == '.') ? (aa = 1) : (aa = aa);
            y++;
        }
    }
    return (aa);
}

void game_loop(char **board, char **infos)
{
    char *str = NULL;
    size_t size = 0;
    coor coo;

    while (1) {
        printf("Player %s, where do you want to play: ", infos[2]);
        getline(&str, &size, stdin);
        coo.y = my_getnbr(str) - 1;
        board = place_avatar(board, &coo, infos, 2);
        if (full(board, infos) == 0)
            break;
        print_map(board, my_getnbr(infos[0]), my_getnbr(infos[1]));
        printf("Player %s, where do you want to play: ", infos[3]);
        getline(&str, &size, stdin);
        coo.y = my_getnbr(str) - 1;
        board = place_avatar(board, &coo, infos, 3);
        if (full(board, infos) == 0)
            break;
        print_map(board, my_getnbr(infos[0]), my_getnbr(infos[1]));
    }
    printf("It's a tie, nobody wins.");
}

int main(int ac, char **av)
{
    char **infos = malloc(sizeof(char *) * 5);
    char **map;

    if (ac % 2 != 1) {
        write(2, "Error : Argument error", 22);
        return 84;
    }
    infos = arguments(infos, ac, av);
    if (infos == NULL) {
        write(2, "Error, Argument error (not avalaible)", 37);
        return 84;
    }
    map = init_map(my_getnbr(infos[0]), my_getnbr(infos[1]));
    game_loop(map, infos);
    return 0;
}
