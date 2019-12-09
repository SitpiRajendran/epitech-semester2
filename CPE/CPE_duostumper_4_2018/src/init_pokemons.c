/*
** EPITECH PROJECT, 2019
** DuoStumper
** File description:
** init pokemons
*/

#include "pokemon.h"

char *my_strcat(char *dest, char const *scr)
{
    int f = 0;
    char *new = malloc(sizeof(dest) * 50);
    int i = 0;

    if (scr == NULL)
        return (NULL);
    for (; dest[i] != '\0'; i++)
        new[i] = dest[i];
    new[i] = '\0';
    for (; new[f] != '\0'; f = f + 1);
    for (i = 0; scr[i] != '\0'; i++) {
        if (scr[i] != '\n') {
            new[f] = scr[i];
            f++;
        }
    }
    new[f] = '\0';
    return (new);
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

t_pokemons init_pokemons(char **av)
{
    struct dirent *box;
    DIR *dir = opendir("pokecfg");
    char *str;
    t_pokemons poks;

    poks.error = 0;
    if (dir == NULL)
        return poks;
    while ((box = readdir(dir)) != NULL && poks.error == 0)
        if (box->d_name[0] != '.') {
            str = init(my_strcat("pokecfg/", box->d_name));
            parsing_info(str, &poks, av);
        }
    return (poks);
}
