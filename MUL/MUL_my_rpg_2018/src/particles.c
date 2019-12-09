/*
** EPITECH PROJECT, 2019
** MUL RPG
** File description:
** particules
*/

#include "rpg.h"

void rain_effect(t_game *gm, sfRenderWindow *win)
{
    static int set = 0;

    if (set == 0) {
        gm->rain.sprite = sfSprite_create();
        gm->rain.texture = sfTexture_createFromFile("./rsr/wind.png", NULL);
        gm->rain.rect.width = 1200;
        gm->rain.rect.height = 720;
        gm->rain.rect.top = 0;
        gm->rain.rect.left = 0;
        sfSprite_setTexture(gm->rain.sprite, gm->rain.texture, sfFalse);
        sfSprite_setScale(gm->rain.sprite, (sfVector2f){2, 2});
        sfSprite_setPosition(gm->rain.sprite, (sfVector2f){-100, -100});
        set = 1;
    }
    if (((-1) * (gm->chr.y / 10)) > 115) {
        gm->rain.rect.left += 1200;
        if (gm->rain.rect.left == 9600)
            gm->rain.rect.left = 0;
        sfSprite_setTextureRect(gm->rain.sprite, gm->rain.rect);
        sfRenderWindow_drawSprite(win, gm->rain.sprite, NULL);
    }
}