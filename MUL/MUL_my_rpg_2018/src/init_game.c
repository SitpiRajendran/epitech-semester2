/*
** EPITECH PROJECT, 2019
** MUL rpg
** File description:
** init game
*/

#include "rpg.h"

char *init(char *filepath)
{
    struct stat sb;
    int fd;
    int ret;
    int size;
    char *str;

    if (stat(filepath, &sb) == -1)
        return "error";
    size = sb.st_size;
    str = malloc(size + 1);
    fd = open(filepath, O_RDONLY);
    if (str == NULL || fd == -1)
        return "error";
    ret = read(fd, str, size);
    if (ret != size  || str[0] == '\0')
        return "error";
    str[size] = '\0';
    close(fd);
    return (str);
}

void init_chara(t_game *gm)
{
    gm->chr.txt = sfTexture_createFromFile("./rsr/princess.png", NULL);
    gm->chr.sprt = sfSprite_create();
    gm->chr.rect.width = 36;
    gm->chr.rect.height = 27;
    gm->chr.rect.top = 0;
    gm->chr.rect.left = 36;
    gm->chr.x = -720;
    gm->chr.y = -400;
    gm->chr.xp = 10;
    gm->chr.items = 0;
    sfSprite_setTexture(gm->chr.sprt, gm->chr.txt, sfTrue);
    sfSprite_setTextureRect(gm->chr.sprt, gm->chr.rect);
    sfSprite_setScale(gm->chr.sprt, (sfVector2f){3, 3});
    sfSprite_setPosition(gm->chr.sprt, (sfVector2f){960, 540});
}

void init_invent(t_game *gm)
{
    gm->invent.bak.sprite = sfSprite_create();
    gm->invent.bak.txtur = sfTexture_createFromFile("./rsr/invent.jpg", NULL);
    gm->invent.pick.sprite = sfSprite_create();
    gm->invent.pick.txtur = sfTexture_createFromFile("./rsr/pickaxe.png", NULL);
    gm->invent.sword.sprite = sfSprite_create();
    gm->invent.sword.txtur = sfTexture_createFromFile("./rsr/sword.png", NULL);
    gm->invent.fish.sprite = sfSprite_create();
    gm->invent.fish.txtur = sfTexture_createFromFile("./rsr/fishing.png", NULL);
    sfSprite_setTexture(gm->invent.bak.sprite, gm->invent.bak.txtur, sfFalse);
    sfSprite_setScale(gm->invent.bak.sprite, (sfVector2f){1.1, 1.1});
    sfSprite_setPosition(gm->invent.bak.sprite, (sfVector2f){1780, 40});
    sfSprite_setTexture(gm->invent.sword.sprite,
    gm->invent.sword.txtur, sfFalse);
    sfSprite_setPosition(gm->invent.sword.sprite, (sfVector2f){1840, 100});
    sfSprite_setTexture(gm->invent.pick.sprite,
    gm->invent.pick.txtur, sfFalse);
    sfSprite_setPosition(gm->invent.pick.sprite, (sfVector2f){1840, 500});
    sfSprite_setTexture(gm->invent.fish.sprite,
    gm->invent.fish.txtur, sfFalse);
    sfSprite_setPosition(gm->invent.fish.sprite, (sfVector2f){1840, 310});
}

void init_game(t_game *game)
{
    init_chara(game);

    game->verif = strtotab(init("./rsr/allow"));
    game->map_txt = sfTexture_createFromFile("./rsr/map.jpg", NULL);
    game->map = sfSprite_create();
    game->clock = sfClock_create();
    game->rock.sprite = sfSprite_create();
    game->rock.txtur = sfTexture_createFromFile("./rsr/rock.png", NULL);
    game->invent.is_fish = 0;
    game->invent.is_sword = 0;
    game->invent.is_pick = 0;

    init_invent(game);
    sfSprite_setTexture(game->rock.sprite, game->rock.txtur, sfFalse);
    sfSprite_setTexture(game->map, game->map_txt, sfFalse);
    sfSprite_setScale(game->map, (sfVector2f){0.9, 0.9});
    sfSprite_setPosition(game->map, (sfVector2f){game->chr.x, game->chr.y});
}
