/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** fighting function
*/

#include "rpg.h"

void fight_draw(sfEvent eve, t_game *gm, sfRenderWindow *window)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, gm->fight_bg->sprite, NULL);
    sfRenderWindow_drawSprite(window, gm->miner->sprt, NULL);
    sfRenderWindow_drawSprite(window, gm->chr.sprt, NULL);
    if (eve.type == sfEvtKeyPressed && eve.key.code == sfKeySpace)
        sfRenderWindow_drawSprite(window, gm->explode->sprite, NULL);
    sfRenderWindow_drawRectangleShape(window, gm->chr.life, NULL);
    sfRenderWindow_drawRectangleShape(window, gm->miner->life, NULL);
    sfRenderWindow_display(window);
}

void fight(sfRenderWindow *window, t_game *gm)
{
    sfEvent event;
    bool enemy_dead = false;
    bool is_fight = true;

    if (gm->verif[(-1) * (gm->chr.y / 10)][(-1) * (gm->chr.x / 10)] != '3'
        || gm->invent.is_pick != 0)
        return;
    gm->fight_clock = sfClock_create();
    set_fight_assets(gm);
    fight_draw(event, gm, window);
    dialog_ongame(window, "./rsr/mine_text.png",
    "Utilise Espace pour attacker", gm);
    while (is_fight == true)
        if (life_management(window, event, &enemy_dead, gm) == false
        || enemy_dead == true)
            is_fight = false;
    if (enemy_dead == true)
        win(gm, window);
    else
        lose(gm, window);
}