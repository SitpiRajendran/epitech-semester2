/*
** EPITECH PROJECT, 2019
** CPE Duostumper
** File description:
** option
*/

#include "my.h"

option_t init_option(option_t option_s)
{
    option_s.a = 0;
    option_s.d = 0;
    option_s.L = 0;
    option_s.f = 0;
    return (option_s);
}

option_t option_checker(char *str, option_t option_s)
{
    for (int i = 0; str[i] != '\0'; i++) {
        (str[i] == 'a') ? (option_s.a = 1) : (option_s.a = option_s.a);
        (str[i] == 'd') ? (option_s.d = 1) : (option_s.d = option_s.d);
        (str[i] == 'L') ? (option_s.L = 1) : (option_s.L = option_s.L);
        (str[i] == 'f') ? (option_s.f = 1) : (option_s.f = option_s.f);
    }
    return (option_s);
}

void calls(option_t option_s, char *path)
{
    if (option_s.f == 1)
        tree_f(path);
    if (option_s.a == 1)
        tree_a(path);
    if (option_s.d == 1)
        tree_d(path);
}

int options(char *option, char *path)
{
    option_t option_s;
    char *temp;

    if (option[0] != '-') {
        temp = option;
        option = path;
        path = temp;
    }
    option_s = init_option(option_s);
    if (path[0] == '-') {
        option_s = option_checker(path, option_s);
        path = ".";
    }
    option_s = option_checker(option, option_s);
    calls(option_s, path);
    return (0);
}
