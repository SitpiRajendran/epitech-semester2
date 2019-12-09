/*
** EPITECH PROJECT, 2019
** MUL_my_defender
** File description:
** menu
*/
#include "defender.h"

int launch_game(sfRenderWindow *window, int choice, sfEvent event)
{
    backg map;
    game_but buts;
    int score = 0;
    tower *towers = malloc(sizeof(tower));
    enemies_t *enemy[20];
    sfClock *clo = sfClock_create();

    init_game(&map, &buts, towers, enemy);
    towers->loop = sfMusic_createFromFile("./rsr/music.ogg");
    sfMusic_setLoop(towers->loop, sfTrue);
    sfMusic_play(towers->loop);
    while (sfRenderWindow_isOpen(window) && choice != 10 && choice != 0) {
        draw_game(window, &map, &buts);
        while (sfRenderWindow_pollEvent(window, &event))
            choice = analyse_game(event, &buts, window, towers);
        score = score_count(buts.score.text, score);
        enemies(clo, enemy, window);
    }
    sfMusic_destroy(towers->loop);
    sfMusic_destroy(buts.music);
    return (choice);
}

int launch_menu(sfRenderWindow *window, int choice, sfEvent event)
{
    backg menu;
    menu_button mbutt;
    init_menu(&menu, &mbutt);

    while (sfRenderWindow_isOpen(window) && choice == 0) {
        draw_menu(window, &menu, &mbutt);
        while (sfRenderWindow_pollEvent(window, &event)) {
            choice = analyse_menu(event, &mbutt, window, &menu);
        }
    }
    sfMusic_destroy(mbutt.music);
    return (choice);
}

int launch(void)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window;
    sfEvent event;
    int choice = 0;

    window = sfRenderWindow_create(mode, "Tow", sfFullscreen | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 30);

    while (sfRenderWindow_isOpen(window) && choice != 10) {
        if (choice == 0)
            choice = launch_menu(window, choice, event);
        if (choice == 2)
            choice = launch_game(window, choice, event);
    }
    sfRenderWindow_destroy(window);
    return (0);
}
