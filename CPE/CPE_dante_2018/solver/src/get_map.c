/*
** EPITECH PROJECT, 2019
** CPE Dante
** File description:
** get map
*/

#include "solver.h"

t_map get_map(char *av)
{
    t_map map;
    char *string = init(av);
    map.x_max = get_colonn(string);
    map.y_max = get_line(string);
    map.error = 0;

    if (strcmp(string, "error") == 0) {
        map.error = 1;
        return map;
    }
    strtoarr(string, &map);
    return map;
}

char *init(char *filepath)
{
    struct stat sb;
    int fd;
    int ret;
    int size;
    char *str;

    if (stat(filepath, &sb) == -1)
        return "error";
    size = sb.st_size;
    str = malloc(size + 1);
    fd = open(filepath, O_RDONLY);
    if (str == NULL || fd == -1)
        return "error";
    ret = read(fd, str, size);
    if (ret != size  || str[0] == '\0')
        return "error";
    str[size] = '\0';
    close(fd);
    return (str);
}