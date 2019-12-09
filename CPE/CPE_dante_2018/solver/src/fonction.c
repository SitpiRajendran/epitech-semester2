/*
** EPITECH PROJECT, 2019
** CPE Dante
** File description:
** fonction
*/

#include "solver.h"

void mem_arr(t_map *map)
{
    map->chara = malloc(sizeof(char *) * (map->x_max + 1));
    map->num = malloc(sizeof(int *) * (map->x_max + 1));

    for (int a = 0; a != map->x_max; a++) {
        map->num[a] = malloc(sizeof(int) * (map->y_max + 1));
        map->chara[a] = malloc(sizeof(char) * (map->y_max + 1));
    }
}

void strtoarr(char *str, t_map *map)
{
    int n = 0;
    int j = 0;

    mem_arr(map);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != '\n') {
            map->chara[n][j] = str[i];
            (str[i] == 'X') ? (map->num[n][j++] = 0) : (map->num[n][j++] = 1);
        } else {
            map->chara[n][j] = '\0';
            map->num[n++][j] = 9;
            j = 0;
        }
    }
    map->num[n][j] = 9;
    map->chara[n++][j] = '\0';
    map->chara[n] = NULL;
    map->num[n] = NULL;
}

int get_line(char *str)
{
    int i = 0;

    for (; str[i] != '\n' && str[i] != '\0'; i++);
    return i;
}

int get_colonn(char *str)
{
    int a = 0;

    for (int i = 0; str[i] != '\0'; i++)
        (str[i] == '\n') ? a++ : (a = a);
    return a + 1;
}

void print_map(t_map map)
{
    for (int a = 0; a != map.x_max; a++) {
        write(1, map.chara[a], map.y_max);
        (map.chara[a + 1] == NULL) ? (a = a) : write(1, "\n", 1);
    }
}