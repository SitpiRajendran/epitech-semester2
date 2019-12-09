/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** second part modif buffer
*/

#include "my.h"

char *check_redirection(char *buffer, int size, int i)
{
    char *buffer2 = malloc(sizeof(char) * size);

    if ((buffer[i] == '<' && buffer[i + 1] == '<') ||
        (buffer[i] == '>' && buffer[i + 1] == '>')) {
        buffer2 = check_double_redirection(buffer2, buffer, i);
        return (buffer2);
    }
    if (buffer[i - 1] != ' ' && buffer[i - 1] != '<' &&
        buffer[i - 1] != '>' && buffer[i + 1] != ' ') {
        buffer2 = copy_start_buffer(buffer2, buffer, i);
        buffer2[i] = ' ';
        buffer2[i + 1] = buffer[i];
        buffer2[i + 2] = ' ';
        buffer2 = copy_my_buffer(buffer2, buffer, i + 3, i + 1);
        return (buffer2);
    }
    buffer = check_redirection_sec(buffer2, buffer, i);
    return (buffer);
}

char *check_redirection_sec(char *buffer2, char *buffer, int i)
{
    if (buffer[i - 1] != ' ' && buffer[i - 1] != '<' &&
        buffer[i - 1] != '>' && buffer[i + 1] == ' ') {
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

char *check_double_redirection(char *buff2, char *buff, int i)
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
    buff = check_double_redirection_sec(buff2, buff, i);
    return (buff);
}

char *check_double_redirection_sec(char *buff2, char *buff, int i)
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

char *copy_start_buffer(char *buff1, char *buff2, int i)
{
    for (int y = 0; y != i && buff2[y] != '\0'; y++)
        buff1[y] = buff2[y];
    return (buff1);
}