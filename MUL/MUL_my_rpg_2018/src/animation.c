/*
** EPITECH PROJECT, 2019
** MUL RPG
** File description:
** Animation
*/

#include "rpg.h"

void init_text(int x, int y, char *str, sfRenderWindow *win)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("./rsr/menu.ttf");
    sfText_setFont(text, font);
    sfText_setScale(text, (sfVector2f){1, 1});
    sfText_setString(text, str);
    sfText_setColor(text, sfBlack);
    sfText_setPosition(text, (sfVector2f){x, y});
    sfRenderWindow_drawText(win, text, NULL);
}

int click_onkeyboard(sfRenderWindow *win, sfEvent event)
{
    while (sfRenderWindow_pollEvent(win, &event))
        if (event.type == sfEvtKeyPressed)
            return 0;
    return 1;
}

void dialog(sfRenderWindow *win, char *path, char *text)
{
    sfEvent eve;
    sfSprite *sprt = sfSprite_create();
    sfTexture *tex = sfTexture_createFromFile(path, NULL);

    sfSprite_setTexture(sprt, tex, sfFalse);
    sfSprite_setScale(sprt, (sfVector2f){0.6, 0.6});
    sfSprite_setPosition(sprt, (sfVector2f){500, 360});
    sfRenderWindow_drawSprite(win, sprt, NULL);
    init_text(650, 760, text, win);
    while (sfRenderWindow_pollEvent(win, &eve));
    sfRenderWindow_display(win);

    while (1)
        if (click_onkeyboard(win, eve) == 0)
            break;
    sfSprite_destroy(sprt);
}

void anim(t_game *game, sfRenderWindow *win)
{
    game->anim = 1;
    sfView *zoom = sfView_createFromRect((sfFloatRect){0, 100, 1920, 1080});

    sfRenderWindow_setKeyRepeatEnabled(win, sfFalse);
    sfView_zoom(zoom, 2.21);
    for (int i = 0; i != 120; i++) {
        sfRenderWindow_setView(win, zoom);
        draw_game(win, game);
        sfView_zoom(zoom, 0.99);
    }
    dialog(win, "./rsr/prince_text.png", "Cousine, j'ai besoin d'aide !");
    dialog(win, "./rsr/prince_text.png",
    "Un caillou est tombe et m'empeche\nd'aller dans le sud du village");
    dialog(win, "./rsr/prince_text.png",
    "Le chevalier devrait pouvoir\nt'aider !");
    for (int i = 0; i != 50; i++) {
        sfRenderWindow_setView(win, zoom);
        draw_game(win, game);
        sfView_zoom(zoom, 1.01);
    }
}