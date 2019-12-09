/*
** EPITECH PROJECT, 2019
** CPE duostumper6
** File description:
** printwhile.c
*/

#include "crocus.h"

int print_while(char *str, char *text)
{
    if (str == NULL)
        return (84);
    for (int line = 0; line != 5; line++) {
        for (int i = 0; str[i] != '\0'; i++) {
            dispatch_0_4(str[i], line, text);
            (str[i + 1] != '\0') ? write(1, " ", 1) : (i = i);
        }
        write(1, "\n", 1);
    }
    return (0);
}
