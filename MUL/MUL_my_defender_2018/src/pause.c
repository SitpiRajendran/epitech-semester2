/*
** EPITECH PROJECT, 2019
** MUL Defender
** File description:
** Pause Menu
*/

#include "defender.h"

void init_pause(backg *menu, menu_button *mbutt)
{
    menu->back = sfTexture_createFromFile("./rsr/pause.jpg", NULL);
    menu->s_back = sfSprite_create();
    sfSprite_setTexture(menu->s_back, menu->back, sfFalse);

    mbutt->music = sfMusic_createFromFile("./rsr/click.ogg");
    init_text_menu(&mbutt->how, 450, 900, "RETURN");
    init_text_menu(&mbutt->play, 890, 900, "MENU");
    init_text_menu(&mbutt->quit, 1300, 900, "QUIT");
    init_text_menu(&mbutt->howq, 250, 80, "Music : On");
}

void draw_pause(sfRenderWindow *window, backg *menu, menu_button *mbutt)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, menu->s_back, NULL);
    sfRenderWindow_drawText(window, mbutt->play.text, NULL);
    sfRenderWindow_drawText(window, mbutt->how.text, NULL);
    sfRenderWindow_drawText(window, mbutt->quit.text, NULL);
    sfRenderWindow_drawText(window, mbutt->howq.text, NULL);
    sfRenderWindow_display(window);
}

void mouse_hover_pause(menu_button *buts, sfRenderWindow *window)
{
    int x = sfMouse_getPositionRenderWindow(window).x;
    int y = sfMouse_getPositionRenderWindow(window).y;

    if (x > 450 && x < 680 && y > 910 && y < 1000)
        sfText_setColor(buts->how.text, sfRed);
    else
        sfText_setColor(buts->how.text, sfWhite);

    if (x > 890 && x < 1000 && y > 910 && y < 1000)
        sfText_setColor(buts->play.text, sfRed);
    else
        sfText_setColor(buts->play.text, sfWhite);

    if (x > 1300 && x < 1440 && y > 910 && y < 1000)
        sfText_setColor(buts->quit.text, sfRed);
    else
        sfText_setColor(buts->quit.text, sfWhite);
}

int analyse_pause(sfEvent eve, menu_button *buts, sfRenderWindow *win)
{
    int x = eve.mouseButton.x;
    int y = eve.mouseButton.y;

    if (eve.type == sfEvtMouseButtonPressed) {
        sfMusic_play(buts->music);
        if (x > 450 && x < 680 && y > 910 && y < 1000) {
            sfText_setColor(buts->how.text, sfBlack);
            return 1;
        }
        if (x > 890 && x < 1000 && y > 910 && y < 1000) {
            sfText_setColor(buts->play.text, sfBlack);
            return -1;
        } else if (x > 1300 && x < 1440 && y > 910 && y < 1000) {
            sfText_setColor(buts->quit.text, sfBlack);
            return 9;
        }
    }
    mouse_hover_pause(buts, win);
    if (eve.type == sfEvtKeyPressed && eve.key.code == sfKeyEscape)
        return 1;
    return 0;
}

int print_pause(sfEvent eve, sfRenderWindow *win, sfMusic *music)
{
    int i = 1;
    menu_button buts;
    backg bg;
    init_pause(&bg, &buts);

    while (i == 1) {
        draw_pause(win, &bg, &buts);
        while (sfRenderWindow_pollEvent(win, &eve))
            i = i + analyse_pause(eve, &buts, win);
        anal_music(&eve, music, win, buts.howq.text);
    }
    sfMusic_destroy(buts.music);
    return i;
}