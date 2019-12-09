/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** all modif buffer functions
*/

#include "my.h"

char *modif_my_buffer(char *buffer)
{
    buffer = replace_tab_by_space(buffer);
    buffer = remove_my_space(buffer);
    buffer = put_space_between_operator(buffer);
    buffer = remove_my_space(buffer);
    return (buffer);
}

char *put_space_between_operator(char *buffer)
{
    int size = my_strlen(buffer) + 1;
    int i = 1;

    for (int x = 0; buffer[x] != '\0'; x++)
        if (buffer[x] == ';' || buffer[x] == '|' ||
            buffer[x] == '<' || buffer[x] == '>' ||
            buffer[x] == '&')
            size = size + 2;
    for (; buffer[i] != '\0'; i++) {
        if (buffer[i] == ';')
            buffer = check_operator_side(buffer, size, i);
        if (buffer[i] == '|' || buffer[i] == '&')
            buffer = check_separator(buffer, size, i);
        if (buffer[i] == '>' || buffer[i] == '<')
            buffer = check_redirection(buffer, size, i);
    }
    return (buffer);
}

char *check_operator_side(char *buff, int size, int i)
{
    char *buffer2 = malloc(sizeof(char) * size);

    if (buffer2 == NULL)
        return (NULL);
    if (buff[i - 1] != ' ' && buff[i + 1] != ' ') {
        buffer2 = copy_start_buffer(buffer2, buff, i);
        buffer2[i] = ' ';
        buffer2[i + 1] = buff[i];
        buffer2[i + 2] = ' ';
        buffer2 = copy_my_buffer(buffer2, buff, i + 3, i + 1);
        return (buffer2);
    }
    if (buff[i - 1] != ' ' && buff[i + 1] == ' ') {
        buffer2 = copy_start_buffer(buffer2, buff, i);
        buffer2[i] = ' ';
        buffer2 = copy_my_buffer(buffer2, buff, i + 1, i);
        return (buffer2);
    }
    return (check_operator_side_sec(buffer2, buff, i));
}

char *check_operator_side_sec(char *buf2, char *buf, int i)
{
    if (buf[i - 1] == ' ' && buf[i + 1] != ' ') {
        buf2 = copy_start_buffer(buf2, buf, i);
        buf2[i] = buf[i];
        buf2[i + 1] = ' ';
        buf2 = copy_my_buffer(buf2, buf, i + 2, i + 1);
        return (buf2);
    }
    return (buf);
}

char *copy_my_buffer(char *buff1, char *str, int i, int n)
{
    for (; str[n] != '\0'; n++) {
        buff1[i] = str[n];
        i++;
    }
    buff1[i] = '\0';
    return (buff1);
}