/*
** EPITECH PROJECT, 2019
** MUL defender
** File description:
** draw
*/

#include "defender.h"

void draw_enemies(sfRenderWindow *window, enemies_t *ene[20])
{
    for (int i = 0; i != 20; i++)
        sfRenderWindow_drawSprite(window, ene[i]->sprte, NULL);
    sfRenderWindow_display(window);
}

void draw_game(sfRenderWindow *window, backg *map, game_but *buts)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, map->s_back, NULL);
    sfRenderWindow_drawText(window, buts->shoot.text, NULL);
    sfRenderWindow_drawText(window, buts->bomb.text, NULL);
    sfRenderWindow_drawText(window, buts->boat.text, NULL);
    sfRenderWindow_drawText(window, buts->twitter.text, NULL);
    sfRenderWindow_drawText(window, buts->gold.text, NULL);
    sfRenderWindow_drawText(window, buts->score.text, NULL);
    sfRenderWindow_drawText(window, buts->pause.text, NULL);
}

void draw_menu(sfRenderWindow *window, backg *menu, menu_button *mbutt)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, menu->s_back, NULL);
    sfRenderWindow_drawSprite(window, menu->s_how, NULL);
    sfRenderWindow_drawText(window, mbutt->play.text, NULL);
    sfRenderWindow_drawText(window, mbutt->how.text, NULL);
    sfRenderWindow_drawText(window, mbutt->quit.text, NULL);
    sfRenderWindow_drawText(window, mbutt->howq.text, NULL);
    sfRenderWindow_display(window);
}
