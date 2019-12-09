/*
** EPITECH PROJECT, 2019
** PSU Tetris
** File description:
** args
*/

#include "tetris.h"

char *get_name(char *type)
{
    char *name = malloc(sizeof(char) * (my_strlen(type) - 2));
    int i = 2;

    if (name == NULL)
        return "MallocFailed";
    for (; type[i] != '=' && type[i] != '\0'; i++)
        name[i - 2] = type[i];
    name[i - 2] = '\0';
    return name;
}

int get_opt(char *type, char *name)
{
    int opt = -3;

    if (my_strcmp(name, "map-size") != 0 &&
        my_strcmp(name, "without-next") != 0 && my_strcmp(name, "debug") != 0)
        opt = type[my_strlen(name) + 3];

    return opt;
}

void two_hyphen(char *type, t_params *prm)
{
    char *name = get_name(type);
    int opt = get_opt(type, name);
    int nop = 0;

    (my_strcmp(name, "level") == 0) ? (prm->level = opt) : (nop += 1);
    (my_strcmp(name, "key-left") == 0) ? (prm->left = opt) : (nop += 1);
    (my_strcmp(name, "key-right") == 0) ? (prm->right = opt) : (nop += 1);
    (my_strcmp(name, "key-turn") == 0) ? (prm->turn = opt) : (nop += 1);
    (my_strcmp(name, "key-drop") == 0) ? (prm->drop = opt) : (nop += 1);
    (my_strcmp(name, "key-quit") == 0) ? (prm->quit = opt) : (nop += 1);
    (my_strcmp(name, "key-pause") == 0) ? (prm->pause = opt) : (nop += 1);
    (my_strcmp(name, "without-next") == 0) ? (prm->next = 0) : (nop += 1);
    (my_strcmp(name, "debug") == 0) ? (prm->debug = 1) : (nop += 1);
    (my_strcmp(name, "help") == 0) ? (nop = nop) : (nop += 1);
    if (my_strcmp(name, "map-size") == 0)
        get_map(prm, type);

    if ((nop == 10 && opt != -3) || opt == 0)
        prm->error = 1;
}

int one_hyphen(char type, char *arg, t_params *params)
{
    int nop = 0;

    if (arg != NULL && arg[0] != '-') {
        (type == 'L') ? (params->level = arg[0]) : (nop += 1);
        (type == 'l') ? (params->left = arg[0]) : (nop += 1);
        (type == 'r') ? (params->right = arg[0]) : (nop += 1);
        (type == 't') ? (params->turn = arg[0]) : (nop += 1);
        (type == 'd') ? (params->drop = arg[0]) : (nop += 1);
        (type == 'q') ? (params->quit = arg[0]) : (nop += 1);
        (type == 'p') ? (params->pause = arg[0]) : (nop += 1);
        if (nop == 7)
            params->error = 1;
        return 1;
    } else {
        (type == 'w') ? (params->next = 0) : (nop += 1);
        (type == 'D') ? (params->debug = 1) : (nop += 1);
        if (nop == 2)
            params->error = 1;
        return 0;
    }
}

void get_args(t_params *params, char **av, int ac)
{
    for (int i = 1; i < ac; i++) {
        if (av[i][0] == '-' && av[i][1] == '-')
            two_hyphen(av[i], params);
        else if (av[i][0] == '-') {
            i += one_hyphen(av[i][1], av[i + 1], params);
        } else
            params->error = 1;
    }
}