/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** manage redirections
*/

#include "my.h"

void file_redirections(mini_t *mini_s, b_list_t *stock)
{
    int fd = creat(stock->next->next->command, S_IRUSR | S_IWUSR |
        S_IRGRP | S_IWGRP | S_IROTH);

    if (fd == -1)
        return;
    dup2(fd, STDOUT_FILENO);
    compare_my_functions(mini_s, stock->command);
    dup2(STDIN_FILENO, STDOUT_FILENO);
}

void enf_of_file_redirections(mini_t *mini_s, b_list_t *stock)
{
    int fd = open(stock->next->next->command, O_APPEND | O_WRONLY);

    if (fd == -1)
        fd = creat(stock->next->next->command, S_IRUSR | S_IWUSR |
        S_IRGRP | S_IWGRP | S_IROTH);

    dup2(fd, STDOUT_FILENO);
    compare_my_functions(mini_s, stock->command);
    dup2(STDIN_FILENO, STDOUT_FILENO);
}

void reverse_file_redirections(mini_t *mini_s, b_list_t *stock)
{
    int fd = open(stock->next->next->command, O_RDONLY);

    if (fd == -1)
        dprintf(2, "%s: No such file or directory.\n",
        stock->next->next->command);
    else {
        dup2(fd, STDIN_FILENO);
        compare_my_functions(mini_s, stock->command);
        dup2(STDOUT_FILENO, STDIN_FILENO);
    }
}

int my_redirections(mini_t *mini_s, b_list_t *stock, int end)
{
    if (end <= 2)
        return (0);
    if (my_strcmp(stock->next->command, ">", 1) == 1) {
        file_redirections(mini_s, stock);
        return (1);
    }
    if (my_strcmp(stock->next->command, ">>", 1) == 1) {
        enf_of_file_redirections(mini_s, stock);
        return (1);
    }
    if (my_strcmp(stock->next->command, "<", 1) == 1) {
        reverse_file_redirections(mini_s, stock);
        return (1);
    }
    if (my_strcmp(stock->next->command, "<<", 1) == 1) {
        read_from_keyboard_redirection(mini_s, stock);
        return (1);
    }
    return (0);
}