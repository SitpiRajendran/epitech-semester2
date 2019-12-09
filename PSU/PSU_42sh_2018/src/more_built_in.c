/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** manage options
*/

#include "my.h"

void compare_my_functions(mini_t *mini_s, char *buffer)
{
    char *buffstock = NULL;

    count_my_arg(mini_s, buffer);
    stock_my_arg(mini_s, buffer);
    if (my_strcmp(mini_s->arg[0], "history", 1) == 1)
        return print_history(mini_s);
    if (my_strcmp(mini_s->arg[0], "!n", 1) == 1)
        return print_one_history(mini_s);
    if (my_strcmp(mini_s->arg[0], "bin/ls", 1) == 1)
        return my_putstr("bin/ls: Command not found.\n", 1);
    if (my_strcmp(mini_s->arg[0], "exit", 1) == 1)
        return check_exit(mini_s);
    if (my_strcmp(mini_s->arg[0], "cd", 1) == 1)
        return check_cd(mini_s, buffstock);
    if (my_strcmp(mini_s->arg[0], "echo", 1) == 1)
        return check_echo(mini_s);
    if (check_my_env(mini_s) == 1)
        return;
    check_exe(mini_s);
    return;
}

void check_exe(mini_t *mini_s)
{
    if (mini_s->arg[0][0] == '\0')
        return;
    if (find_my_path(mini_s) == 1) {
        my_putstr(mini_s->command, 2);
        my_putstr(": Command not found.\n", 2);
        return;
    }
    create_my_fork(mini_s);
    return;
}

void check_cd(mini_t *mini_s, char *buffstock)
{
    size_t size = 0;

    if (mini_s->arg_nbr > 2) {
        mini_s->v_return = 1;
        return my_putstr("cd: Too many arguments.\n", 2);
    }
    if (manage_my_cd_hyphen(mini_s, getcwd(buffstock, size)) == 1)
        return;
    mini_s->path = getcwd(buffstock, size);
    if (mini_s->arg_nbr == 2 && my_strcmp(mini_s->arg[1], "~", 1) != 1) {
        if (chdir(mini_s->arg[1]) == -1)
            display_cd_error(mini_s->arg[1]);
        change_my_env_path(mini_s, getcwd(buffstock, size));
        return;
    }
    if (chdir(get_my_home_path(mini_s)) == -1) {
        mini_s->v_return = 1;
        return my_putstr("The home path is incorrect or doesn't exist.\n", 2);
    }
    change_my_env_path(mini_s, getcwd(buffstock, size));
}

void check_exit(mini_t *mini_s)
{
    if (mini_s->arg_nbr > 2) {
        mini_s->v_return = 1;
        return my_putstr("exit: Expression Syntax.\n", 2);
    }
    if (mini_s->arg_nbr == 2)
        if (check_exit_value(mini_s, mini_s->arg[1]) == 1) {
            mini_s->v_return = 1;
            return my_putstr("exit: Expression Syntax.\n", 2);
        }
    mini_s->exit_status = 1;
}