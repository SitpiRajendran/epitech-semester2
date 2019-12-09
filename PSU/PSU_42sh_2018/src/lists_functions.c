/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** my linked twist functions
*/

#include "my.h"

b_list_t *add_element_after(b_list_t *list, char *str)
{
    b_list_t *add_element = malloc(sizeof(*add_element));
    b_list_t *stock = list;

    add_element->command = str;
    add_element->next = NULL;
    if (list == NULL)
        return (add_element);
    else {
        while (stock->next != NULL)
            stock = stock->next;
        stock->next = add_element;
        return (list);
    }
}

void display_my_list(b_list_t *list)
{
    b_list_t *stock = list;

    while (stock != NULL) {
        my_putstr(stock->command, 1);
        stock = stock->next;
    }
    my_putstr("\n", 1);
}

void free_linked_twist(mini_t *mini_s, b_list_t *liste)
{
    b_list_t *tmp = liste;
    b_list_t *tmpnxt = liste;

    while (tmp != NULL) {
        tmpnxt = tmp->next;
        free(tmp->command);
        free(tmp);
        tmp = tmpnxt;
    }
    free_buffer(mini_s->command);
    free_tab_buffer(mini_s->arg);
    mini_s->command = NULL;
    mini_s->arg = NULL;
}
