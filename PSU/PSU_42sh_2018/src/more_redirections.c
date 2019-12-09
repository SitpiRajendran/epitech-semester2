/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** more redirections
*/

#include "my.h"

int read_from_keyboard_redirection(mini_t *mini_s, b_list_t *stck)
{
    ssize_t line_len = 0;
    char *line = "0";
    size_t len = 0;
    char tempname[11] = "tempXXXXXX";
    int fd = mkstemp(tempname);

    if (fd == -1)
        return (1);
    for (int i = 0; my_strcmp(line, stck->next->next->command, 3) != 1; i++) {
        my_putstr("? ", 1);
        if (i != 0)
            write(fd, line, line_len);
        line_len = getline(&line, &len, stdin);
    }
    close(fd);
    fd = open(tempname, O_RDONLY);
    dup2(fd, STDIN_FILENO);
    compare_my_functions(mini_s, stck->command);
    dup2(STDOUT_FILENO, STDIN_FILENO);
    remove(tempname);
}

int and_separator(mini_t *mini_s, b_list_t *stck)
{
    compare_my_functions(mini_s, stck->command);
    if (mini_s->v_return == 0) {
        compare_my_functions(mini_s, stck->next->next->command);
    } else
        return (84);
}

int or_separator(mini_t *mini_s, b_list_t *stck)
{
    compare_my_functions(mini_s, stck->command);
    if (mini_s->v_return != 0) {
        compare_my_functions(mini_s, stck->next->next->command);
    } else
        return (84);
}