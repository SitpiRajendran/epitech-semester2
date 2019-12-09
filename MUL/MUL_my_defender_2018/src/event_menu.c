/*
65;5403;1c** EPITECH PROJECT, 2019
** MUL_defender
** File description:
** events
*/

#include "defender.h"

void mouse_hover_menu(menu_button *mbutt, sfRenderWindow *window)
{
    int x = sfMouse_getPositionRenderWindow(window).x;
    int y = sfMouse_getPositionRenderWindow(window).y;

    if (x > 890 && x < 1023 && y > 910 && y < 1000)
        sfText_setColor(mbutt->play.text, sfRed);
    else
        sfText_setColor(mbutt->play.text, sfWhite);
    if (x > 450 && x < 590 && y > 910 && y < 1000)
        sfText_setColor(mbutt->how.text, sfRed);
    else
        sfText_setColor(mbutt->how.text, sfWhite);
    if (x > 1300 && x < 1440 && y > 910 && y < 1000)
        sfText_setColor(mbutt->quit.text, sfRed);
    else
        sfText_setColor(mbutt->quit.text, sfWhite);
    if (x > 800 && x < 1200 && y > 750 && y < 900)
        sfText_setColor(mbutt->howq.text, sfRed);
    else
        sfText_setColor(mbutt->howq.text, sfWhite);
}

void print_how(menu_button *mbu, backg *sp, int x, int y)
{
    static int hows = 0;

    if (x > 450 && x < 590 && y > 910 && y < 1000 && hows == 0) {
        sfText_setPosition(mbu->howq.text, (sfVector2f){900, 775});
        sfText_setColor(mbu->how.text, sfBlack);
        sfSprite_setPosition(sp->s_how, (sfVector2f){0, 0});
        hows = 5;
    }
    if (x > 450 && x < 590 && y > 910 && y < 1000 && hows == 1) {
        sfText_setColor(mbu->how.text, sfBlack);
        sfSprite_setPosition(sp->s_how, (sfVector2f){1920, 825});
        sfText_setPosition(mbu->howq.text, (sfVector2f){1920, 750});
        hows = 0;
    }
    if (x > 800 && x < 1200 && y > 750 && y < 900) {
        sfText_setPosition(mbu->howq.text, (sfVector2f){1920, 825});
        sfSprite_setPosition(sp->s_how, (sfVector2f){1920, 0});
        hows = 0;
    }
    if (hows == 5)
        hows = 1;
}

int analyse_menu(sfEvent eve, menu_button *mbu, sfRenderWindow *win, backg *sp)
{
    int x = eve.mouseButton.x;
    int y = eve.mouseButton.y;

    if (eve.type == sfEvtMouseButtonPressed) {
        sfMusic_play(mbu->music);
        if (x > 890 && x < 1023 && y > 910 && y < 1000)
            return 2;
        print_how(mbu, sp, x, y);
        if (x > 1300 && x < 1440 && y > 910 && y < 1000)
            sfRenderWindow_close(win);
    }
    mouse_hover_menu(mbu, win);
    if (eve.type == sfEvtKeyPressed && eve.key.code == sfKeyEscape)
        sfRenderWindow_close(win);
    return 0;
}
