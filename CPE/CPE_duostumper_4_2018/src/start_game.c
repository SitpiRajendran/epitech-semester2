/*
** EPITECH PROJECT, 2019
** DuoStumper
** File description:
** Pokemon
*/

#include "pokemon.h"

char *my_strlowcase(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0') {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;
        }
        i = i + 1;
    }
    return (str);
}

int start_game(char **av)
{
    t_pokemons poks = init_pokemons(av);

    if (poks.one.name == NULL || poks.two.name == NULL)
        return error("Youre pokemon doesn't exist");
    if (poks.one.spd > poks.two.spd)
        launch_game(&poks.one, &poks.two);
    else
        launch_game(&poks.two, &poks.one);
    return 0;
}
