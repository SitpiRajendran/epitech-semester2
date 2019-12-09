/*
** EPITECH PROJECT, 2019
** PSU Rpg
** File description:
** Draw Menu
*/

#include "rpg.h"

void change_vol(t_game *game)
{
    game->music += 10.0;
    if (game->music >= 101.0)
        game->music = 0.0;
}

void change_frm(t_game *game, sfRenderWindow *win)
{
    game->frame += 10;
    if (game->frame >= 121)
        game->frame = 30;
    sfRenderWindow_setFramerateLimit(win, game->frame);
}

void mouse_hover_set(t_menu *mbutt, sfRenderWindow *window)
{
    int x = sfMouse_getPositionRenderWindow(window).x;
    int y = sfMouse_getPositionRenderWindow(window).y;

    if (x > 500 && x < 800 && y > 600 && y < 660)
        sfText_setColor(mbutt->new_game.text, sfWhite);
    else
        sfText_setColor(mbutt->new_game.text, sfBlack);
    if (x > 950 && x < 1250 && y > 600 && y < 660)
        sfText_setColor(mbutt->load_game.text, sfWhite);
    else
        sfText_setColor(mbutt->load_game.text, sfBlack);
    if (x > 790 && x < 1130 && y > 850 && y < 930)
        sfText_setColor(mbutt->quit.text, sfWhite);
    else
        sfText_setColor(mbutt->quit.text, sfBlack);
}

int analyse_set(sfEvent eve, sfRenderWindow *win, t_menu *sp, t_game *gm)
{
    int x = eve.mouseButton.x;
    int y = eve.mouseButton.y;

    if (eve.type == sfEvtMouseButtonPressed) {
        if (x > 500 && x < 600 && y > 600 && y < 660)
            change_vol(gm);
        if (x > 950 && x < 1250 && y > 600 && y < 660)
            change_frm(gm, win);
        if (x > 790 && x < 1130 && y > 850 && y < 930)
            return 0;
    }
    mouse_hover_set(sp, win);
    if (eve.type == sfEvtKeyPressed && eve.key.code == sfKeyEscape)
        return 0;
    return 3;
}

void draw_set(sfRenderWindow *window, t_menu *menu, t_game *gm)
{
    sfText *music = init_number_menu(680, 595, my_itoa(gm->music));
    sfText *frame = init_number_menu(1250, 595, my_itoa(gm->frame));

    sfRenderWindow_clear(window, sfWhite);
    sfRenderWindow_drawSprite(window, menu->sprt, NULL);
    sfRenderWindow_drawText(window, menu->new_game.text, NULL);
    sfRenderWindow_drawText(window, music, NULL);
    sfRenderWindow_drawText(window, frame, NULL);
    sfRenderWindow_drawText(window, menu->load_game.text, NULL);
    sfRenderWindow_drawText(window, menu->quit.text, NULL);
    sfRenderWindow_display(window);
}