/*
** EPITECH PROJECT, 2019
** defender
** File description:
** defender.h
*/

#ifndef MY_H_
#define MY_H_

#include <stdlib.h>
#include <stdio.h>
#include <SFML/Window.h>
#include <SFML/Config.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stddef.h>

typedef struct pos
{
    int x;
    int y;
} pos_t;

typedef struct backg_t
{
    sfTexture *back;
    sfSprite *s_back;
    sfTexture *how;
    sfSprite *s_how;
} backg;

typedef struct button_t
{
    sfFont *font;
    sfText *text;
    sfTexture *normal;
    sfSprite *s_button;
} button;

typedef struct menu_button_t
{
    button play;
    button quit;
    button how;
    button howq;
    sfMusic *music;
} menu_button;

typedef struct game_button_t
{
    button shoot;
    button bomb;
    button boat;
    button twitter;
    button gold;
    button score;
    button pause;
    sfMusic *music;
} game_but;

typedef struct tower_t
{
    sfTexture *shooter_txtr;
    sfSprite *shooter_sprite;
    sfTexture *bomber_txtr;
    sfSprite *bomber_sprite;
    sfTexture *mine_txtr;
    sfSprite *mine_sprite;
    sfTexture *boat_txtr;
    sfSprite *boat_sprite;
    sfTexture *twitter_txtr;
    sfSprite *twitter_sprite;
    sfMusic *loop;
} tower;

typedef struct enemies_s {
    sfSprite *sprte;
    sfTexture *txtr;
    sfIntRect rect;
    int x;
    int ran;
} enemies_t;

int launch(void);

int launch_menu(sfRenderWindow *window, int choice, sfEvent event);
void init_menu(backg *menu, menu_button *mbutt);
void init_text_menu(button *buton, int x, int y, char *str);
void draw_menu(sfRenderWindow *window, backg *menu, menu_button *mbutt);
int analyse_menu(sfEvent eve, menu_button *mbu, sfRenderWindow *win, backg *sp);
void print_how(menu_button *mbu, backg *sp, int x, int y);
void mouse_hover_menu(menu_button *mbutt, sfRenderWindow *window);

int launch_game(sfRenderWindow *window, int choice, sfEvent event);
void init_game(backg *map, game_but *buts, tower *towers, enemies_t *ene[20]);
void init_text(button *buton, int x, int y, char *str);
void enemy_setting(enemies_t *ene[20]);
void draw_game(sfRenderWindow *window, backg *map, game_but *buts);
//int analyse_game(sfEvent eve, game_but *mbu, sfRenderWindow *win,
//tower *towers);
int game_events(sfEvent eve, sfRenderWindow *win, tower *towers);
int analyse_game(sfEvent eve, game_but *mbu, sfRenderWindow *wi, tower *towers);
int print_pause(sfEvent eve, sfRenderWindow *win, sfMusic *music);
int mouse_hover_game(game_but *buts, sfRenderWindow *window, tower *towers);
int score_count(sfText *text, int score);
void anal_music(sfEvent *eve, sfMusic *mus, sfRenderWindow *win, sfText *text);
void enemies(sfClock *cl, enemies_t *ene[20], sfRenderWindow *win);
void draw_enemies(sfRenderWindow *window, enemies_t *ene[20]);


#endif /* !MY_H_ */