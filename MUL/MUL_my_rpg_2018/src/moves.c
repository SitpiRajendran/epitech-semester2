/*
** EPITECH PROJECT, 2019
** MUL PRG
** File description:
** moves
*/

#include "rpg.h"

void go_down(t_game *game)
{
    game->chr.rect.top = 54;

    if (game->verif[(-1)*(game->chr.y - 9)/10][(-1)*(game->chr.x)/10] == '0')
        return;
    if (game->chr.rect.left < 72)
        game->chr.rect.left += 36;
    else
        game->chr.rect.left = 0;
    game->chr.y -= 8;
    sfClock_restart(game->clock);
}

void go_up(t_game *game)
{
    game->chr.rect.top = 0;

    if (game->chr.y >= -9)
        return;
    if (game->verif[(-1)*(game->chr.y + 9)/10][(-1)*(game->chr.x)/10] == '0')
        return;
    if (game->chr.rect.left < 72)
        game->chr.rect.left += 36;
    else
        game->chr.rect.left = 0;
    game->chr.y += 8;
    sfClock_restart(game->clock);
}

void go_left(t_game *game)
{
    game->chr.rect.top = 81;

    if (game->chr.x >= -9)
        return;
    if (game->verif[(-1)*(game->chr.y)/10][(-1)*(game->chr.x + 9)/10] == '0')
        return;
    if (game->chr.rect.left < 72)
        game->chr.rect.left += 36;
    else
        game->chr.rect.left = 0;
    game->chr.x += 8;
    sfClock_restart(game->clock);
}

void go_right(t_game *game)
{
    game->chr.rect.top = 27;

    if (game->verif[(-1)*(game->chr.y)/10][(-1)*(game->chr.x - 9)/10] == '0')
        return;
    if (game->chr.rect.left < 72)
        game->chr.rect.left += 36;
    else
        game->chr.rect.left = 0;
    game->chr.x -= 8;
    sfClock_restart(game->clock);
}