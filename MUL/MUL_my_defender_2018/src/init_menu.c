/*
** EPITECH PROJECT, 2019
** MUL_defender
** File description:
** init menu
*/

#include "defender.h"

void init_text_menu(button *buton, int x, int y, char *str)
{
    buton->text = sfText_create();
    buton->font = sfFont_createFromFile("./rsr/font.ttf");
    sfText_setFont(buton->text, buton->font);
    sfText_setScale(buton->text, (sfVector2f){3, 3});
    sfText_setString(buton->text, str);
    sfText_setPosition(buton->text, (sfVector2f){x, y});
}


void init_menu(backg *menu, menu_button *mbutt)
{
    menu->back = sfTexture_createFromFile("./rsr/menu_backg.jpg", NULL);
    menu->s_back = sfSprite_create();
    sfSprite_setTexture(menu->s_back, menu->back, sfFalse);

    menu->how = sfTexture_createFromFile("./rsr/how.jpg", NULL);
    menu->s_how = sfSprite_create();
    sfSprite_setTexture(menu->s_how, menu->how, sfFalse);
    sfSprite_setPosition(menu->s_how, (sfVector2f){1920, 0});

    mbutt->music = sfMusic_createFromFile("./rsr/click.ogg");
    init_text_menu(&mbutt->how, 450, 900, "HELP");
    init_text_menu(&mbutt->play, 890, 900, "PLAY");
    init_text_menu(&mbutt->quit, 1300, 900, "QUIT");
    init_text_menu(&mbutt->howq, 1920, 750, "DONE");
}