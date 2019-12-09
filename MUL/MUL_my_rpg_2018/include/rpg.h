/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** rpg.h
*/

#ifndef RPG_H_
    #define RPG_H_

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include <stdbool.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <SFML/Window.h>
#include <SFML/Config.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>

#define EMAIN 84

typedef struct object_s {
    sfSprite *sprite;
    sfTexture *txtur;
} object_t;

typedef struct s_button {
    sfFont *font;
    sfText *text;
    sfSprite *sprt;
    int x;
    int y;
} t_button;

typedef struct pause_t {
    sfTexture *text;
    sfSprite *sprt;
    t_button return_to_game;
    t_button save_game;
    t_button params;
    t_button quit;
} pause_t;

typedef struct s_menu {
    sfTexture *text;
    sfSprite *sprt;
    t_button help;
    t_button new_game;
    t_button load_game;
    t_button params;
    t_button quit;
    sfMusic *music;
} t_menu;

typedef struct s_rain {
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
} t_rain;

typedef struct s_chara {
    int x;
    int y;
    sfTexture *txt;
    sfSprite *sprt;
    sfIntRect rect;
    sfRectangleShape *life;
    sfVector2f bar_size;
    int xp;
    int items;
} t_chara;

typedef struct s_invent
{
    object_t bak;
    object_t sword;
    int is_sword;
    object_t fish;
    int is_fish;
    object_t pick;
    int is_pick;
} t_invent;

typedef struct s_game {
    float music;
    int frame;
    char **verif;
    sfTexture *map_txt;
    sfSprite *map;
    object_t rock;
    t_chara chr;
    t_chara *miner;
    object_t *fight_bg;
    object_t *explode;
    sfClock *fight_clock;
    sfClock *clock;
    int anim;
    t_rain rain;
    t_invent invent;
} t_game;


bool error_management(int argc, const char *const argv[], const char *envp[]);

int my_strcmp(const char *s1, const char *s2);
char **strtotab(char *str);
int my_strlen(char const *str);
char *my_itoa(int nbr);

void set_view(sfRenderWindow *win);
sfText *init_number_menu(int x, int y, char *str);
void init_text_menu(t_button *buton, int x, int y, char *str);
void init_menu(t_menu *menu);
void init_set(t_menu *menu);

void dialog(sfRenderWindow *win, char *path, char *text);
int launch_set(sfRenderWindow *window, int input, sfEvent event, t_game *);
int launch_game(sfRenderWindow *win, int input, sfEvent event, t_game *game);
int launch_menu(sfRenderWindow *window, int input, sfEvent event);
int launch (void);

int analyse_menu(sfEvent eve, sfRenderWindow *win, t_menu *sp);
void draw_menu(sfRenderWindow *window, t_menu *menu);

void change_vol(t_game *game);
void change_frm(t_game *game, sfRenderWindow *win);
void mouse_hover_set(t_menu *mbutt, sfRenderWindow *window);

void init_game_set(t_menu *menu);
int launch_game_set(sfRenderWindow *win, int input, sfEvent eve, t_game *game);
int analyse_game_set(sfEvent eve, sfRenderWindow *win, t_menu *sp, t_game *gm);
void draw_set(sfRenderWindow *window, t_menu *menu, t_game *gm);
int analyse_set(sfEvent eve, sfRenderWindow *win, t_menu *sp, t_game *gm);

void init_game(t_game *game);

void go_down(t_game *game);
void go_up(t_game *game);
void go_left(t_game *game);
void go_right(t_game *game);

int analyse_game(sfEvent eve, sfRenderWindow *win, t_game *gm);
void draw_game(sfRenderWindow *window, t_game *gm);

int pause_game(sfEvent eve, sfRenderWindow *win);

void rain_effect(t_game *gm, sfRenderWindow *win);
void anim(t_game *game, sfRenderWindow *win);
int click_onkeyboard(sfRenderWindow *win, sfEvent event);
void talking(t_game *game, sfRenderWindow *win);
void dialog_ongame(sfRenderWindow *win, char *path, char *text, t_game *game);

char *attack_count(t_game *gm);
void fight(sfRenderWindow *window, t_game *gm);
bool life_management(sfRenderWindow *window, sfEvent eve,
                    bool *enemy_dead, t_game *gm);
void fight_draw(sfEvent eve, t_game *gm, sfRenderWindow *window);
void set_fight_assets(t_game *gm);
void set_life_bar(t_game *gm);
void reset_princess(t_game *gm);
void win(t_game *gm, sfRenderWindow *win);
void lose(t_game *gm, sfRenderWindow *win);

#endif /* !RPG_H_*/
