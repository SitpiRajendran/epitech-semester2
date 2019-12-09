/*
** EPITECH PROJECT, 2019
** CPE lemin
** File description:
** parser new
*/

#include "my.h"

int search_line(char **line, char *str)
{
    for (int i = 0; line[i] != NULL; i++) {
        if (my_strcmp(line[i], str) == 0)
            return (i + 1);
    }
    return (0);
}

void printligne(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (i > 1 && str[i] == '#') {
            write(1, "\n", 1);
            return;
        }
        write(1, &str[i], 1);
    }
}

int count_space(char *str)
{
    int c = 0;

    for (int j = 0; str[j] != '\0' && str[j] != '#'; j++)
        str[j] == ' ' ? c++ : (c = c);
    return c;
}

void parser_main(char **tabs)
{
    int c = 20;
    int p = 1;

    my_putstr("#number_of_ants\n");
    my_putstr(tabs[0]);
    my_putstr("#rooms\n");
    for (; c > 1; p++) {
        if (tabs[p][0] != '#' || (tabs[p][0] == '#' && tabs[p][1] == '#'))
            printligne(tabs[p]);
        if (tabs[p + 1][0] != '#')
            c = count_space(tabs[p + 1]);
        else
            c = 56;
    }
    my_putstr("#tunnels\n");
    for (; tabs[p] != NULL; p++)
        if (tabs[p][0] != '#')
            printligne(tabs[p]);
    my_putstr("#moves\nP1-2 P2-3\nP1-1 P2-1 P3-2\nP3-1\n");
}