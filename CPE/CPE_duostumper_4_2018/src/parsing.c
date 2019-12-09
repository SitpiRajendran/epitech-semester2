/*
** EPITECH PROJECT, 2019
** POKEMON
** File description:
** pokemon
*/

#include "pokemon.h"

char **strtoarr(char *str, int len)
{
    int n = 0;
    int j = 0;
    int i = 0;
    char **tab = malloc(sizeof(char *) * len);

    for (int a = 0; a != len; a++)
        if (tab == NULL || (tab[a] = malloc(sizeof(char) * len)) == NULL)
            exit (84);
    for (; str[i] == ' ' || str[i] == '\t'; i++);
    for (; str[i] != '\0'; i++) {
        if (str[i] != '\n')
            tab[n][j++] = str[i];
        else {
            tab[n++][j] = '\0';
            j = 0;
        }
    }
    tab[n] = NULL;
    return (tab);
}

int get_info(char *str, int i, char *print)
{
    int j = 0;
    char * buffer = malloc(sizeof(char) * 35);

    if (buffer == NULL)
        exit(84);
    for (; str[i] != '\0' && str[i] != '\n' && str[i] != ';'; j++, i++) {
        buffer[j] = str[i];
    }
    buffer[j] = '\0';
    if (strcmp(print, "NOP") != 0)
        printf("%s%s", print, buffer);

    return (i + 1);
}

char *get_name(char *str, int i)
{
    int j = 0;
    char *buffer = malloc(sizeof(char) * 35);

    for (; str[i] != '\0' && str[i] != ';'; j++, i++)
        buffer[j] = str[i];
    buffer[j] = '\0';

    return buffer;
}

t_pokinfo add_pokemon(char *str, t_pokinfo info)
{
    int i = 0;

    info.name = get_name(str, 0);
    i = get_info(str, i , "NOP");
    info.att = atoi(get_name(str, i));
    i = get_info(str, i , "NOP");
    info.def = atoi(get_name(str, i));
    i = get_info(str, i , "NOP");
    info.spd = atoi(get_name(str, i));
    i = get_info(str, i , "NOP");
    info.lif = atoi(get_name(str, i));
    return info;
}

void parsing_info(char *str, t_pokemons *poks, char **av)
{
    char **tab = strtoarr(str, strlen(str));
    int j = 0;

    for (int i = 0; tab[i] != NULL; i++) {
        j = 0;
        if (tab[i][0] == '#')
            i++;
        j = get_info(tab[i], j, "Pokemon ");
        str = get_name(tab[i], 0);
        if (strcmp(my_strlowcase(str), my_strlowcase(av[1])) == 0)
            poks->one = add_pokemon(tab[i], poks->one);
        else if (strcmp(my_strlowcase(str), my_strlowcase(av[2])) == 0)
            poks->two = add_pokemon(tab[i], poks->two);
        j = get_info(tab[i], j, " has ");
        j = get_info(tab[i], j, " attack, ");
        j = get_info(tab[i], j, " defense, ");
        j = get_info(tab[i], j, " speed and ");
        j = get_info(tab[i], j, " health\n");
    }
}
