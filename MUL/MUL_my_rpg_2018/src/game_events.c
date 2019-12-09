/*
** EPITECH PROJECT, 2019
** PSU Rpg
** File description:
** Draw Menu
*/

#include "rpg.h"

void new_level(sfRenderWindow *win, t_game *gm)
{
    if (gm->invent.is_pick == 0) {
        sfSprite_setPosition(gm->rock.sprite,
        (sfVector2f){(1640+gm->chr.x), (1500+gm->chr.y)});
        sfRenderWindow_drawSprite(win, gm->rock.sprite, NULL);
    } else {
        gm->verif[89][64] = '1';
        gm->verif[89][65] = '1';
        gm->verif[89][66] = '1';
        gm->verif[89][67] = '1';
        gm->verif[89][68] = '1';
    }
}

int analyse_game(sfEvent eve, sfRenderWindow *win, t_game *gm)
{
    int sec = (int)(sfTime_asSeconds(sfClock_getElapsedTime(gm->clock)) * 1000);

    if (eve.type == sfEvtKeyPressed) {
        if (eve.key.code == sfKeyUp && sec > 33)
            go_up(gm);
        if (eve.key.code == sfKeyDown && sec > 33)
            go_down(gm);
        if (eve.key.code == sfKeyLeft && sec > 33)
            go_left(gm);
        if (eve.key.code == sfKeyRight && sec > 33)
            go_right(gm);
        sfSprite_setTextureRect(gm->chr.sprt, gm->chr.rect);
        sfSprite_setPosition(gm->map, (sfVector2f){gm->chr.x, gm->chr.y});
        if (gm->verif[(-1) * (gm->chr.y / 10)][(-1) * (gm->chr.x / 10)] == '2')
            talking(gm, win);
        fight(win, gm);
        if (eve.key.code == sfKeyEscape)
            return pause_game(eve, win);
    }
    return 1;
}

void draw_inventory(sfRenderWindow *win, t_game *gm)
{
    sfRenderWindow_drawSprite(win, gm->invent.bak.sprite, NULL);
    if (gm->invent.is_sword == 1)
        sfRenderWindow_drawSprite(win, gm->invent.sword.sprite, NULL);
    if (gm->invent.is_fish == 1)
        sfRenderWindow_drawSprite(win, gm->invent.fish.sprite, NULL);
    if (gm->invent.is_pick == 1)
        sfRenderWindow_drawSprite(win, gm->invent.pick.sprite, NULL);
}

void draw_game(sfRenderWindow *window, t_game *gm)
{
    sfText *text2 = init_number_menu(1860, 960, "0");
    sfText *text3 = init_number_menu(1860, 1040, attack_count(gm));
    sfText *text4 = init_number_menu(1860, 1110, my_itoa(gm->chr.xp));

    sfRenderWindow_clear(window, sfColor_fromRGB(76, 196, 246));
    sfRenderWindow_drawSprite(window, gm->map, NULL);
    sfRenderWindow_drawSprite(window, gm->chr.sprt, NULL);
    rain_effect(gm, window);
    if (gm->anim != 1) {
        draw_inventory(window, gm);
        sfRenderWindow_drawText(window, text2, NULL);
        sfRenderWindow_drawText(window, text3, NULL);
        sfRenderWindow_drawText(window, text4, NULL);
        new_level(window, gm);
    }
    sfRenderWindow_display(window);
}
