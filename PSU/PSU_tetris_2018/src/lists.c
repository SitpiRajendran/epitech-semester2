/*
** EPITECH PROJECT, 2019
** PSU Tetris
** File description:
** lists
*/

#include "tetris.h"

void swap(elem_t *first, elem_t *second)
{
    char *name = first->name;
    int row = first->row;
    int cols = first->cols;
    int color = first->color;
    char *obj = first->obj;

    first->name = second->name;
    first->row = second->row;
    first->cols = second->cols;
    first->color = second->color;
    first->obj = second->obj;

    second->name = name;
    second->row = row;
    second->cols = cols;
    second->color = color;
    second->obj = obj;
}

void sort(elem_t *start)
{
    int is_swap = 0;
    elem_t *first;
    elem_t *last = NULL;

    if (start == NULL)
        return;
    do {
        is_swap = 0;
        first = start;
        while (first->next != last) {
            if (my_strcmp(first->name, first->next->name) > 0) {
                swap(first, first->next);
                is_swap = 1;
            }
            first = first->next;
        }
        last = first;
    }
    while (is_swap);
}

char *init(char *filepath)
{
    struct stat sb;
    int fd;
    int ret;
    int size;
    char *str;

    if (stat(filepath, &sb) == -1)
        return "error";
    size = sb.st_size;
    str = malloc(size + 1);
    fd = open(filepath, O_RDONLY);
    if (str == NULL || fd == -1)
        return "error";
    ret = read(fd, str, size);
    if (ret != size  || str[0] == '\0')
        return "error";
    str[size] = '\0';
    close(fd);
    return (str);
}

void addfirst(elem_t **start, char *name, char *str)
{
    elem_t *new = (elem_t *)malloc(sizeof(elem_t));

    if (new == NULL)
        return;
    new->name = name;
    new->row = get_online(str, 0);
    new->cols = get_online(str, 1);
    new->color = get_online(str, 2);
    if (new->cols <= 0 || new->row <= 0 || new->color < 0)
        new->cols = -2;
    new->obj = get_obj(str);
    verif_tetriminos(new);
    new->next = *start;
    *start = new;
}

elem_t *init_minos(t_params *params)
{
    struct dirent *box;
    DIR *dir = opendir("tetriminos");
    char *str;
    elem_t *start = NULL;

    if (dir == NULL) {
        params->error = 1;
        return start;
    }
    while ((box = readdir(dir)) != NULL)
        if (box->d_name[0] != '.') {
            str = init(my_strcat("tetriminos/", box->d_name));
            addfirst(&start, get_name_m(box->d_name), str);
        }
    sort(start);
    return (start);
}