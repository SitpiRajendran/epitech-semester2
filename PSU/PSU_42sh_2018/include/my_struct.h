/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** Structure of the navy project
*/

#ifndef MY_STRUCT_H_
#define MY_STRUCT_H_

typedef struct b_list
{
    int pos;
    char *command;
    struct b_list *next;
} b_list_t;

typedef struct mini {
    int y;
    int v_return;
    int cd;
    int exe;
    int exit_value;
    pid_t fork_val;
    int arg_nbr;
    int error;
    int set_error;
    int compt;
    int exit_status;
    b_list_t *root;
    char *home_path;
    char *path;
    char *command;
    char **arg;
    char **env;
    char **history;
} mini_t;

#endif
