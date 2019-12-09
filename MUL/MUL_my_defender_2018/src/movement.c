/*
** EPITECH PROJECT, 2019
** MUL_defender
** File description:
** movement
*/
#include "defender.h"

void enemy_setting(enemies_t *ene[20])
{
    for (int i = 0; i != 20; i++) {
        ene[i] = malloc(sizeof(enemies_t));
        ene[i]->txtr = sfTexture_createFromFile("./rsr/me.png", NULL);
        ene[i]->sprte = sfSprite_create();
        ene[i]->rect.height = 160;
        ene[i]->rect.top = 0;
        ene[i]->rect.left = -10;
        ene[i]->rect.width = 100;
        ene[i]->x = 1920 + (400 * i);
        ene[i]->ran = rand() % 10;
        sfSprite_setTexture(ene[i]->sprte, ene[i]->txtr, sfTrue);
        sfSprite_setPosition(ene[i]->sprte, (sfVector2f){ene[i]->x, 670});
        sfSprite_setTextureRect(ene[i]->sprte, ene[i]->rect);
    }
}

sfIntRect move_rect(sfIntRect rect, int offset, int max_val)
{
    rect.left = rect.left + offset;
    if (rect.left > max_val)
        rect.left = -10;
    return rect;
}

void animate_enemies(sfClock *cl, enemies_t *enemy)
{
    int secs = (int) (sfTime_asSeconds(sfClock_getElapsedTime(cl)) * 100000.0);

    if (secs > 1)
        enemy->rect = move_rect(enemy->rect, 168, 2432);
    sfSprite_setTextureRect(enemy->sprte, enemy->rect);
}

void enemies(sfClock *cl, enemies_t *ene[20], sfRenderWindow *win)
{
    for (int i = 0; i != 21; i++) {
        animate_enemies(cl, ene[i]);
        ene[i]->x -= ene[i]->ran;
        if (ene[i]->x < 60)
            ene[i]->x = -500;
        sfSprite_setPosition(ene[i]->sprte, (sfVector2f){ene[i]->x, 670});
    }
    sfClock_restart(cl);
    draw_enemies(win, ene);
}
