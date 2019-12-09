/*
** EPITECH PROJECT, 2019
** MUL rpg
** File description:
** Launch
*/

#include "rpg.h"

int launch_game_set(sfRenderWindow *win, int input, sfEvent eve, t_game *game)
{
    t_menu menu;
    sfRenderWindow_setView(win, sfRenderWindow_getDefaultView(win));
    init_game_set(&menu);

    while (sfRenderWindow_isOpen(win) && input == 2) {
        draw_set(win, &menu, game);
        while (sfRenderWindow_pollEvent(win, &eve))
            input = analyse_game_set(eve, win, &menu, game);
    }
    return input;
}

int launch_set(sfRenderWindow *window, int input, sfEvent event, t_game *game)
{
    t_menu menu;
    sfRenderWindow_setView(window, sfRenderWindow_getDefaultView(window));
    init_set(&menu);

    while (sfRenderWindow_isOpen(window) && input == 3) {
        draw_set(window, &menu, game);
        while (sfRenderWindow_pollEvent(window, &event))
            input = analyse_set(event, window, &menu, game);
    }
    return input;
}

int analyse_launch(sfRenderWindow *win, int input, sfEvent event, t_game *game)
{
    if (input == 0) {
        game->anim = 1;
        input = launch_menu(win, input, event);
    }
    if (input == 1)
        input = launch_game(win, input, event, game);
    if (input == 2)
        input = launch_game_set(win, input, event, game);
    if (input == 3)
        input = launch_set(win, input, event, game);
    if (input == 4)
        input = pause_game(event, win);
    return input;
}

int launch(void)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *win;
    sfEvent event;
    t_game game;
    sfMusic *music = sfMusic_createFromFile("./rsr/menu.ogg");
    game.music = 50.0;
    int input = 0;
    game.anim = 1;

    win = sfRenderWindow_create(mode, "RPG", sfFullscreen | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(win, (game.frame = 30));
    sfMusic_play(music);
    while (sfRenderWindow_isOpen(win) && input != 10) {
        sfMusic_setVolume(music, game.music);
        input = analyse_launch(win, input, event, &game);
    }
    sfMusic_destroy(music);
    sfRenderWindow_destroy(win);
    return EXIT_SUCCESS;
}