/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** put space between separator
*/

#include "my.h"

char *check_separator(char *buffer, int size, int i)
{
    char *buffer2 = malloc(sizeof(char) * size);

    if ((buffer[i] == '|' && buffer[i + 1] == '|') ||
        (buffer[i] == '&' && buffer[i + 1] == '&')) {
        buffer2 = check_double_separator(buffer2, buffer, i);
        return (buffer2);
    }
    if (buffer[i - 1] != ' ' && buffer[i - 1] != '|' &&
        buffer[i - 1] != '&' && buffer[i + 1] != ' ') {
        buffer2 = copy_start_buffer(buffer2, buffer, i);
        buffer2[i] = ' ';
        buffer2[i + 1] = buffer[i];
        buffer2[i + 2] = ' ';
        buffer2 = copy_my_buffer(buffer2, buffer, i + 3, i + 1);
        return (buffer2);
    }
    buffer = check_separator_sec(buffer2, buffer, i);
    return (buffer);
}

char *check_separator_sec(char *buffer2, char *buffer, int i)
{
    if (buffer[i - 1] != ' ' && buffer[i - 1] != '|' &&
        buffer[i - 1] != '&' && buffer[i + 1] == ' ') {
        buffer2 = copy_start_buffer(buffer2, buffer, i);
        buffer2[i] = ' ';
        buffer2 = copy_my_buffer(buffer2, buffer, i + 1, i);
        return (buffer2);
    }
    if (buffer[i - 1] == ' ' && buffer[i + 1] != ' ') {
        buffer2 = copy_start_buffer(buffer2, buffer, i);
        buffer2[i] = buffer[i];
        buffer2[i + 1] = ' ';
        buffer2 = copy_my_buffer(buffer2, buffer, i + 2, i + 1);
        return (buffer2);
    }
    return (buffer);
}

char *check_double_separator(char *buff2, char *buff, int i)
{
    if (buff[i - 1] != ' ' && buff[i + 2] != ' ') {
        buff2 = copy_start_buffer(buff2, buff, i);
        buff2[i] = ' ';
        buff2[i + 1] = buff[i];
        buff2[i + 2] = buff[i];
        buff2[i + 3] = ' ';
        buff2 = copy_my_buffer(buff2, buff, i + 4, i + 2);
        return (buff2);
    }
    buff = check_double_separator_sec(buff2, buff, i);
    return (buff);
}

char *check_double_separator_sec(char *buff2, char *buff, int i)
{
    if (buff[i - 1] != ' ' && buff[i + 2] == ' ') {
        buff2 = copy_start_buffer(buff2, buff, i);
        buff2[i] = ' ';
        buff2 = copy_my_buffer(buff2, buff, i + 1, i);
        return (buff2);
    }
    if (buff[i - 1] == ' ' && buff[i + 2] != ' ') {
        buff2 = copy_start_buffer(buff2, buff, i);
        buff2[i] = buff[i];
        buff2[i + 1] = buff[i];
        buff2[i + 2] = ' ';
        buff2 = copy_my_buffer(buff2, buff, i + 3, i + 2);
        return (buff2);
    }
    return (buff);
}