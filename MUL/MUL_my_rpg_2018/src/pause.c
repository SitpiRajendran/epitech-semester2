/*
** EPITECH PROJECT, 2019
** MUL RPG
** File description:
** Pause
*/

#include "rpg.h"

static void mouse_hover_menu(pause_t *pause, sfRenderWindow *window)
{
    int x = sfMouse_getPositionRenderWindow(window).x;
    int y = sfMouse_getPositionRenderWindow(window).y;

    if (x > 850 && x < 1110 && y > 550 && y < 610)
        sfText_setColor(pause->return_to_game.text, sfWhite);
    else
        sfText_setColor(pause->return_to_game.text, sfBlack);
    if (x > 840 && x < 1120 && y > 650 && y < 710)
        sfText_setColor(pause->save_game.text, sfWhite);
    else
        sfText_setColor(pause->save_game.text, sfBlack);
    if (x > 850 && x < 1100 && y > 750 && y < 810)
        sfText_setColor(pause->params.text, sfWhite);
    else
        sfText_setColor(pause->params.text, sfBlack);
    if (x > 840 && x < 1120 && y > 850 && y < 910)
        sfText_setColor(pause->quit.text, sfWhite);
    else
        sfText_setColor(pause->quit.text, sfBlack);
}

static int analyse_pause(sfEvent eve, sfRenderWindow *win, pause_t *pause)
{
    int x = eve.mouseButton.x;
    int y = eve.mouseButton.y;

    if (eve.type == sfEvtMouseButtonPressed) {
        if (x > 850 && x < 1110 && y > 550 && y < 610)
            return 1;
        if (x > 850 && x < 1100 && y > 650 && y < 710)
            return 0;
        if (x > 850 && x < 1100 && y > 750 && y < 810)
            return 2;
        if (x > 840 && x < 1120 && y > 850 && y < 910)
            sfRenderWindow_close(win);
        if (eve.key.code == sfKeyEscape)
            return 1;
    }
    mouse_hover_menu(pause, win);
    return 4;
}

static void draw_pause(sfRenderWindow *window, pause_t *pause)
{
    sfRenderWindow_clear(window, sfWhite);
    sfRenderWindow_drawSprite(window, pause->sprt, NULL);
    sfRenderWindow_drawText(window, pause->return_to_game.text, NULL);
    sfRenderWindow_drawText(window, pause->save_game.text, NULL);
    sfRenderWindow_drawText(window, pause->params.text, NULL);
    sfRenderWindow_drawText(window, pause->quit.text, NULL);
    sfRenderWindow_display(window);
}

static void init_pause(pause_t *pause)
{
    pause->text = sfTexture_createFromFile("./rsr/pause.jpg", NULL);
    pause->sprt = sfSprite_create();
    sfSprite_setTexture(pause->sprt, pause->text, sfFalse);
    sfSprite_setScale(pause->sprt, (sfVector2f){1.1, 1.1});
    sfSprite_setPosition(pause->sprt, (sfVector2f){-100, 40});
    init_text_menu(&pause->return_to_game, 800, 650, "Return to Game");
    init_text_menu(&pause->save_game, 840, 750, "Return Menu");
    init_text_menu(&pause->params, 850, 850, "Settings");
    init_text_menu(&pause->quit, 840, 950, "Quit Game");
}

int pause_game(sfEvent eve, sfRenderWindow *win)
{
    int i = 4;
    pause_t pause;

    set_view(win);
    init_pause(&pause);
    while (sfRenderWindow_isOpen(win) && i == 4) {
        draw_pause(win, &pause);
        while (sfRenderWindow_pollEvent(win, &eve))
            i = analyse_pause(eve, win, &pause);
    }
    return i;
}
