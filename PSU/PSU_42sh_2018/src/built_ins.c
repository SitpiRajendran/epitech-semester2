/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** manage options
*/

#include "my.h"

void check_my_buffer(mini_t *mini_s, char *buffer)
{
    b_list_t *stock = NULL;

    mini_s->root = NULL;
    if (buffer[0] == '\0')
        return;
    buffer = modif_my_buffer(buffer);
    if (create_my_list(mini_s, buffer) == 84)
        return;
    stock = mini_s->root;
    for (; stock != NULL; stock = stock->next) {
        stock = check_command_pipe(mini_s, stock);
        stock = check_command_redirection(mini_s, stock);
        stock = check_command_separator(mini_s, stock);
        if (stock == NULL)
            return;
        if (check_command_operator(stock->command) != 1)
            compare_my_functions(mini_s, stock->command);
    }
    free_linked_twist(mini_s, stock);
}

b_list_t *check_command_pipe(mini_t *mini_s, b_list_t *stock)
{
    int end = 0;

    end = check_list_end(stock);
    if (end >= 3) {
        if (my_strcmp(stock->next->command, "|", 1) == 1) {
            handle_pipe(stock->command, stock->next->next->command, mini_s);
            stock = stock->next->next->next;
        }
    }
    return (stock);
}

b_list_t *check_command_redirection(mini_t *mini_s, b_list_t *stock)
{
    int end = 0;

    end = check_list_end(stock);
    if (my_redirections(mini_s, stock, end) == 1) {
        if (end >= 3)
            stock = stock->next->next->next;
    }
    return (stock);
}

b_list_t *check_command_separator(mini_t *mini_s, b_list_t *stock)
{
    int end = 0;

    end = check_list_end(stock);
    if (end <= 2)
        return (stock);
    if (my_strcmp(stock->next->command, "&&", 1) == 1) {
        and_separator(mini_s, stock);
        if (end >= 3)
            stock = stock->next->next->next;
        return (stock);
    }
    if (my_strcmp(stock->next->command, "||", 1) == 1) {
        or_separator(mini_s, stock);
        if (end >= 3)
            stock = stock->next->next->next;
        return (stock);
    }
    return (stock);
}

int check_command_operator(char *command)
{
    if (my_strcmp(command, ";", 1) || my_strcmp(command, "|", 1)
    || my_strcmp(command, "||", 1) || my_strcmp(command, "&&", 1)
    || my_strcmp(command, "<", 1) || my_strcmp(command, "<<", 1)
    || my_strcmp(command, ">", 1) || my_strcmp(command, ">>", 1))
        return (1);
    return (0);
}