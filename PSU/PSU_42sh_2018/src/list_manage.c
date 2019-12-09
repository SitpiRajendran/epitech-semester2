/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** graph list
*/

#include "my.h"

int create_my_list(mini_t *mini_s, char *buffer)
{
    if (command_error_management(mini_s, buffer) == 84)
        return (84);
    mini_s->y = 0;
    while (buffer[mini_s->y] != '\0') {
        put_command_in_list(mini_s, buffer);
        put_operator_in_list(mini_s, buffer);
    }
    free(buffer);
    return (0);
}

void put_command_in_list(mini_t *m, char *buffer)
{
    char *command = NULL;
    int compt = 0;

    command = malloc(sizeof(char) * (my_strlen(buffer) + 1));
    for (; buffer[m->y] != '\0' &&
    check_buffer_operator(m, buffer) != 1; m->y++) {
        command[compt] = buffer[m->y];
        compt++;
    }
    command[compt] = '\0';
    command = remove_my_space(command);
    if (command[0] != '\0')
        m->root = add_element_after(m->root, command);
}

void put_operator_in_list(mini_t *m, char *buffer)
{
    char *operator = NULL;
    int compt = 0;

    operator = malloc(sizeof(char) * (my_strlen(buffer) + 1));
    for (; buffer[m->y] != '\0' && buffer[m->y] != ' '; m->y++) {
        operator[compt] = buffer[m->y];
        compt++;
    }
    if (buffer[m->y] != '\0') {
        operator[compt] = '\0';
        m->y++;
        m->root = add_element_after(m->root, operator);
    }
}

int check_list_end(b_list_t *stock)
{
    int lenght = 0;
    for (; stock != NULL; stock = stock->next)
        lenght++;
    return (lenght);
}

int check_buffer_operator(mini_t *mini_s, char *buffer)
{
    if (buffer[mini_s->y] == ';' || buffer[mini_s->y] == '|' ||
        buffer[mini_s->y] == '>' || buffer[mini_s->y] == '<' ||
        buffer[mini_s->y] == '&')
        return (1);
    return (0);
}