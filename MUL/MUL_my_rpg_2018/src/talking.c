/*
** EPITECH PROJECT, 2019
** MUL My RPG
** File description:
** talking
*/

#include "rpg.h"

void init_text_ongame(int x, int y, char *str, sfRenderWindow *win)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("./rsr/menu.ttf");
    sfText_setFont(text, font);
    sfText_setScale(text, (sfVector2f){1.8, 1.8});
    sfText_setString(text, str);
    sfText_setColor(text, sfBlack);
    sfText_setPosition(text, (sfVector2f){x, y});
    sfRenderWindow_drawText(win, text, NULL);
}

void dialog_ongame(sfRenderWindow *win, char *path, char *text, t_game *game)
{
    sfEvent eve;
    sfSprite *sprt = sfSprite_create();
    sfTexture *tex = sfTexture_createFromFile(path, NULL);

    sfSprite_setTexture(sprt, tex, sfFalse);
    sfSprite_setScale(sprt, (sfVector2f){1, 1});
    sfSprite_setPosition(sprt, (sfVector2f){0, 180});
    draw_game(win, game);
    sfRenderWindow_drawSprite(win, sprt, NULL);
    init_text_ongame(250, 850, text, win);
    while (sfRenderWindow_pollEvent(win, &eve));
    sfRenderWindow_display(win);

    while (true)
        if (click_onkeyboard(win, eve) == 0)
            break;
    sfSprite_move(sprt, (sfVector2f){2000, 2000});
    sfRenderWindow_drawSprite(win, sprt, NULL);
}

void knight(t_game *game, sfRenderWindow *win)
{
    int x = (-1)*(game->chr.x/10);
    int y = (-1)*(game->chr.y/10);

    if (y < 33 && y > 27 && x < 113 && x > 110) {
        dialog_ongame(win, "./rsr/men_text.png",
        "Ohhhh ! C'est gentil de venir\nm'aider !\nEn ce moment,"
        "c'est compliqué\nde pecher seul.", game);
        game->invent.is_fish = 1;
        game->chr.xp += 5;
    } else if (y < 77 && y > 74 && x < 104 && x > 98) {
        dialog_ongame(win, "./rsr/knight_text.png",
        "Bonjour Princesse, que voulez-vous ?", game);
        draw_game(win, game);
        dialog_ongame(win, "./rsr/princess_text.png",
        "J'ai besoin d'aide pour liberer le\npassage !", game);
        dialog_ongame(win, "./rsr/knight_text.png", "Je pense que le mineur d"
        "evrais avoir\nles outils necessaires pour\ncasser ce caillou.", game);
        game->chr.xp += 15;
        game->invent.is_sword = 1;
    }
}

void talking(t_game *game, sfRenderWindow *win)
{
    int x = (-1) * (game->chr.x/10);
    int y = (-1) * (game->chr.y/10);

    sfRenderWindow_setKeyRepeatEnabled(win, sfFalse);
    if (y < 39 && y > 35 && x < 73 && x > 69)
        dialog_ongame(win, "./rsr/prince_text.png",
        "Le chevalier devrait pouvoir t'aider", game);
    knight(game, win);
    if (y < 2 && y > -1 && x < 84 && x > 79)
        dialog_ongame(win, "./rsr/tree_text.png",
        "VOUS NE PASSEREZ PAS !!!!", game);
    sfRenderWindow_setKeyRepeatEnabled(win, sfTrue);
}