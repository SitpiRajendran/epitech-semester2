/*
** EPITECH PROJECT, 2019
** MUL_my_defender
** File description:
** events
*/

#include "defender.h"

void mouse_hover_game_next(game_but *buts, pos_t pos, sfRenderWindow *window,tower *towers)
{
    sfVector2f pos_sprt = {960, 220};

    if (pos.x > 460 && pos.x < 820 && pos.y > 120 && pos.y < 180) {
        sfSprite_setPosition(towers->twitter_sprite, pos_sprt);
        sfRenderWindow_drawSprite(window, towers->twitter_sprite, NULL);
    } else
        sfText_setColor(buts->twitter.text, sfGreen);
    if (pos.x > 1710 && pos.x < 1980 && pos.y > 950 && pos.y < 1050) {
        sfSprite_setPosition(towers->boat_sprite, pos_sprt);
    } else
        sfText_setColor(buts->pause.text, sfGreen);
    if (pos.x > 1150 && pos.x < 1450 && pos.y > 47 && pos.y < 100) {
        sfSprite_setPosition(towers->bomber_sprite, pos_sprt);
    } else
        sfText_setColor(buts->boat.text, sfGreen);
}

int mouse_hover_game(game_but *buts, sfRenderWindow *window, tower *towers)
{
    pos_t pos;
    pos.x = sfMouse_getPositionRenderWindow(window).x;
    pos.y = sfMouse_getPositionRenderWindow(window).y;
    sfVector2f pos_sprt = {1580, 65};

    if (pos.x > 200 && pos.x < 480 && pos.y > 47 && pos.y < 100) {
        sfSprite_setPosition(towers->shooter_sprite, pos_sprt);
        sfRenderWindow_drawSprite(window, towers->shooter_sprite, NULL);
    } else
        sfText_setColor(buts->shoot.text, sfGreen);
    if (pos.x > 650 && pos.x < 1000 && pos.y > 47 && pos.y < 100) {
        sfSprite_setPosition(towers->bomber_sprite, pos_sprt);
    } else
        sfText_setColor(buts->bomb.text, sfGreen);
    if (pos.x > 875 && pos.x < 1200 && pos.y > 120 && pos.y < 180) {
        sfSprite_setPosition(towers->mine_sprite, pos_sprt);
    } else
        sfText_setColor(buts->gold.text, sfGreen);
    mouse_hover_game_next(buts, pos, window, towers);
    return 2;
}

int analyse_game(sfEvent eve, game_but *mbu, sfRenderWindow *win, tower *towers)
{
    int x = eve.mouseButton.x;
    int y = eve.mouseButton.y;

    if (eve.type == sfEvtMouseButtonPressed) {
        sfMusic_play(mbu->music);
        if (x > 200 && x < 480 && y > 47 && y < 100)
            return 11;
        if (x > 650 && x < 1000 && y > 47 && y < 100)
            return 12;
        if (x > 1150 && x < 1450 && y > 47 && y < 100)
            return 13;
        if (x > 460 && x < 820 && y > 120 && y < 180)
            return 14;
        if (x > 875 && x < 1200 && y > 120 && y < 180)
            return 15;
        if (x > 1710 && x < 1980 && y > 950 && y < 1050)
            return (print_pause(eve, win, towers->loop));
    }
    if (eve.type == sfEvtKeyPressed && eve.key.code == sfKeyEscape)
        return (print_pause(eve, win, towers->loop));
    return (mouse_hover_game(mbu, win, towers));
}
