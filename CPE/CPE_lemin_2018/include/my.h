/*
** EPITECH PROJECT, 2019
** my
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_
#define UNUSED(x) (void)(x)

#include <stdio.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

typedef struct parsed_t
{
    int ants;
    char *start;
    char **end;
    char **rooms;
    char **links;
} parsed;

typedef struct map_t
{
    int nb_of_room;
    int nb_tunnel;
    char **room_name;
    char **room_pos;
    char **before_tun;
    char **after_tun;
} map;

/* fonction.c */
void my_putchar(char c);
void my_putstr(char *str);
int my_put_nbr(int nb);
int my_strcmp(char const *s1, char const *s2);
int my_strlen(char *str);

/* mem_alloc_2d_array.c */
char **mem_alloc_2d_array(int nb_rows, int nb_cols);

/* fonctionsnext.c */
int my_strline(char *str);
int my_getnbr(char *str);
char **strtoarr(char *str, int len);

/* get_map.c */
char **get_map(char **map);

/* lem_in.c */
int lem_in(void);

/* parser.c */
int count_space(char *str);
int search_line(char **line, char *str);
void parser_main(char **tabs);
int get_ants(char *str);

/* count_room.c */
int count_room(char **str, map *map);

/* check_map.c */
int check_map(char **str, map *map);

/* check_room.c */
map *init_map(void);
int check_room(char **str, map *map);
int room_array(char **str, map *map);

/* chech_position.c */
int put_in_position_array(char *str, map *map);
int check_position(map *map);

/* rooms_occurences.c */
int rooms_occurences(char *str, char **tab, map *map);

/* free_map.c */
void free_map(map *map);

/* check_tunnels.c */
int check_tunnel(char **str, map *map);

/* count_tunnel.c */
int count_tunnel(char **str, map *map);

#endif /* !MY_H_ */
