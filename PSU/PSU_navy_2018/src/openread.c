/*
** EPITECH PROJECT, 2019
** PSU Navy
** File description:
** open read
*/

#include "my.h"

char *orstr(char *filepath)
{
    struct stat sb;
    int fd;
    int ret;
    char *str;

    if (stat(filepath, &sb) == -1) {
        error("file error\n");
        return (NULL);
    }
    str = malloc(sb.st_size);
    if ((fd = open(filepath, O_RDONLY)) == -1)
        return (NULL);
    if ((ret = read(fd, str, sb.st_size)) != sb.st_size) {
        error("read error\n");
        return (NULL);
    }
    str[sb.st_size - 1] = '\0';
    close(fd);
    return (str);
}
