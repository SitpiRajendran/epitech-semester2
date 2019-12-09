/*
** EPITECH PROJECT, 2019
** MUL_defender
** File description:
** init menu
*/

#include "defender.h"

void tower_setting(tower *towers)
{
    sfIntRect shooter = {0, 0, 100, 200};
    sfIntRect boat = {0, 0, 100, 200};

    towers->shooter_txtr = sfTexture_createFromFile("./rsr/shooter_waiting.png",
                                                    &shooter);
    towers->shooter_sprite = sfSprite_create();
    sfSprite_setTexture(towers->shooter_sprite, towers->shooter_txtr, sfFalse);

    towers->boat_txtr = sfTexture_createFromFile("./rsr/boat.png", &boat);
    towers->boat_sprite = sfSprite_create();
    sfSprite_setTexture(towers->boat_sprite, towers->boat_txtr, sfFalse);
}

void tower_setting_next(tower *towers)
{
    sfIntRect mine = {80, 30, 150, 180};
    sfIntRect twitter = {0, 0, 200, 320};

    towers->mine_txtr = sfTexture_createFromFile("./rsr/gold.png", &mine);
    towers->mine_sprite = sfSprite_create();
    sfSprite_setTexture(towers->mine_sprite, towers->mine_txtr, sfFalse);

    towers->twitter_txtr = sfTexture_createFromFile("./rsr/twitt_building.png",
                                                    &twitter);
    towers->twitter_sprite = sfSprite_create();
    sfSprite_setTexture(towers->twitter_sprite, towers->twitter_txtr,
                        sfFalse);
}

void init_text(button *buton, int x, int y, char *str)
{
    buton->text = sfText_create();
    buton->font = sfFont_createFromFile("./rsr/font.ttf");
    sfText_setFont(buton->text, buton->font);
    sfText_setScale(buton->text, (sfVector2f){1.3, 1.3});
    sfText_setString(buton->text, str);
    sfText_setPosition(buton->text, (sfVector2f){x, y});
}

void init_game(backg *map, game_but *buts, tower *towers, enemies_t *ene[20])
{
    map->back = sfTexture_createFromFile("./rsr/map.jpg", NULL);
    map->s_back = sfSprite_create();
    sfSprite_setTexture(map->s_back, map->back, sfFalse);
    buts->music = sfMusic_createFromFile("./rsr/click.ogg");
    init_text(&buts->shoot, 285, 57, "50$ - Shooter");
    init_text(&buts->bomb, 715, 57, "10000$ - Bomb Thrower");
    init_text(&buts->twitter, 520, 120, "500$ - Slowing Tweets");
    init_text(&buts->gold, 960, 120, "1000$ - Gold Mine");
    init_text(&buts->boat, 1285, 57, "25000$ - Boat");
    init_text(&buts->score, 1790, 80, "0$");
    init_text(&buts->pause, 1792, 964, "Pause");

    tower_setting(towers);
    tower_setting_next(towers);
    enemy_setting(ene);
}
