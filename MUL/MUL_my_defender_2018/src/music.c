/*
** EPITECH PROJECT, 2019
** MUL Defender
** File description:
** Music
*/

#include "defender.h"

void anal_music(sfEvent *eve, sfMusic *mus, sfRenderWindow *win, sfText *text)
{
    static int play = 1;
    int x = sfMouse_getPositionRenderWindow(win).x;
    int y = sfMouse_getPositionRenderWindow(win).y;

    if (x > 250 && x < 550 && y > 100 && y < 175)
        sfText_setColor(text, sfRed);
    else
        sfText_setColor(text, sfWhite);
    if (eve->type == sfEvtMouseButtonPressed) {
        if (play == 5)
            play = 0;
        if (x > 250 && x < 550 && y > 100 && y < 175 && play == 1) {
            sfText_setString(text, "Music : OFF");
            sfMusic_stop(mus);
            play = 5;
        } else if (x > 250 && x < 550 && y > 100 && y < 175 && play == 0) {
            sfText_setString(text, "Music : ON");
            sfMusic_play(mus);
            play = 1;
        }
    }
}