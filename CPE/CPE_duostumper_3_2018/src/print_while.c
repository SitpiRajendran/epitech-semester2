/*
** EPITECH PROJECT, 2019
** CPE duostumper3
** File description:
** printwhile.c
*/

#include "my.h"

void print_while(char *str, char *text)
{
    for (int line = 0; line != 5; line++) {
        for (int i = 0; str[i] != '\0'; i++) {
            dispatch_0_4(str[i], line, text);
            if (str[i + 1] != '\0')
                write(1, " ", 1);
        }
        write(1, "\n", 1);
    }
}
