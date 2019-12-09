/*
** EPITECH PROJECT, 2019
** CPE_lemin_2018
** File description:
** get_map
*/

#include "my.h"

char **get_map(char **map)
{
    char *str = NULL;
    size_t size;
    int x = 0;
    int a = 0;

    map = malloc(sizeof(char *) * 10000);
    while ((getline(&str, &size, stdin)) != -1 && x < 10000) {
        map[x] = malloc(sizeof(char) * my_strlen(str) + 1);
        for (; str[a] != '\0'; a++)
            map[x][a] = str[a];
        map[x][a] = '\0';
        a = 0;
        x++;
    }
    map[x] = NULL;
    return (map);
}
