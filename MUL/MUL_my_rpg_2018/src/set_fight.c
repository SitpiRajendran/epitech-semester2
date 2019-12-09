/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** fighting function
*/

#include "rpg.h"

void set_miner(t_chara *miner)
{
    sfVector2f scale = {2, 2};
    sfVector2f pos = {1300, 850};

    miner->txt = sfTexture_createFromFile("./rsr/miner.png", NULL);
    miner->sprt = sfSprite_create();
    miner->rect.width = 114.6;
    miner->rect.height = 112;
    miner->rect.top = 0;
    miner->rect.left = 114.6;
    sfSprite_setTexture(miner->sprt, miner->txt, sfTrue);
    sfSprite_setTextureRect(miner->sprt, miner->rect);
    sfSprite_setScale(miner->sprt, scale);
    sfSprite_setPosition(miner->sprt, pos);
}

void set_princess(t_chara princess)
{
    sfVector2f scale = {9, 9};
    sfVector2f pos = {200, 800};

    princess.rect.width = 36;
    princess.rect.height = 27;
    princess.rect.top = 27;
    princess.rect.left = 36;
    sfSprite_setScale(princess.sprt, scale);
    sfSprite_setTextureRect(princess.sprt, princess.rect);
    sfSprite_setPosition(princess.sprt, pos);
}

void set_bg(object_t *fight_bg)
{
    sfVector2f scale = {1.15, 1.15};
    sfVector2f pos = {-90, 0};

    fight_bg->txtur = sfTexture_createFromFile("./rsr/fight_bg.jpg", NULL);
    fight_bg->sprite = sfSprite_create();
    sfSprite_setScale(fight_bg->sprite, scale);
    sfSprite_setTexture(fight_bg->sprite, fight_bg->txtur, sfTrue);
    sfSprite_setPosition(fight_bg->sprite, pos);

}

void set_explosion(object_t *explode)
{
    sfVector2f pos = {1180, 750};
    sfVector2f scale = {0.5, 0.5};

    explode->txtur = sfTexture_createFromFile("./rsr/explosion.png", NULL);
    explode->sprite = sfSprite_create();
    sfSprite_setTexture(explode->sprite, explode->txtur, sfTrue);
    sfSprite_setPosition(explode->sprite, pos);
    sfSprite_setScale(explode->sprite, scale);
}

void set_fight_assets(t_game *gm)
{
    gm->miner = malloc(sizeof(t_chara));
    gm->fight_bg = malloc(sizeof(object_t));
    gm->explode = malloc(sizeof(object_t));
    gm->chr.life = sfRectangleShape_create();
    gm->miner->life = sfRectangleShape_create();

    set_explosion(gm->explode);
    set_miner(gm->miner);
    set_bg(gm->fight_bg);
    set_princess(gm->chr);
    set_life_bar(gm);
}