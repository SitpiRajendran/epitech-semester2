/*
** EPITECH PROJECT, 2019
** CPE_lemin_2018
** File description:
** lem_in
*/

#include "my.h"

int lem_in(void)
{
    char **tab = NULL;
    map *map = init_map();
    tab = get_map(tab);
    if (tab[0] == NULL)
        return (84);
    if (check_map(tab, map) == 84) {
        for (int i = 0; tab[i] != NULL; i++)
            free(tab[i]);
        free_map(map);
        return (84);
    }
    parser_main(tab);
    for (int i = 0; tab[i] != NULL; i++)
        free(tab[i]);
    free_map(map);
    return (0);
}
