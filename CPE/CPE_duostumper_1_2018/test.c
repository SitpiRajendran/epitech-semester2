/*
** EPITECH PROJECT, 2019
** CPE duo stumper
** File description:
** simple ls
*/

#include "my.h"

char *my_strcat(char *dest, char const *scr)
{
    int f = 0;
    char *new = malloc(sizeof(char*) * (my_strlen(dest) + my_strlen(scr) + 1));
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

int tree_rec(char *path)
{
    static int tabs = 1;
    DIR *dir = opendir(path);
    struct dirent *box;
    struct stat sb;
    char *name;
    int type;

    tabs += 1;
    box = box_dirent(path, dir);
    while (box != NULL) {
        stat(box->d_name, &sb);
        name = box->d_name;
        type = box->d_type;
        box = readdir(dir);
        if (name[0] != '.') {
            for (int i = 1; i != tabs; i++)
                my_putstr("   ");
            if (box != NULL)
                is_dir(type, name, path, 1);
            else
                is_dir(type, name, path, 2);
        }
    }
    tabs -= 1;
    closedir(dir);
    return (0);
}

void is_dir(int type, char *npath, char *path, int aze)
{
    if (aze == 1)
        my_putstr("|-- ");
    if (aze == 2)
        my_putstr("`-- ");
    my_putstr(npath);
    my_putchar('\n');
    path = my_strcat(path, "/");
    if (type == 4) {
        path = my_strcat(path, npath);
        tree_rec(path);
    }
}

struct dirent *box_dirent(char *path, DIR *dir)
{
    struct stat sb;
    struct dirent *box;

    stat(path, &sb);
    if (S_ISDIR(sb.st_mode) != 1) {
        my_putstr(path);
        my_putchar('\n');
        return (NULL);
    } else if (dir == NULL) {
        write (2, "No such file", 13);
        return (NULL);
    }
    box = readdir(dir);
    if (box == NULL) {
        write (2, "Don't have rights", 18);
        return (NULL);
    }
    return (box);
}

int simple_tree(char *path)
{
    DIR *dir = opendir(path);
    struct dirent *box;
    struct stat sb;
    char *name;
    int type;

    box = box_dirent(path, dir);
    my_putstr(path);
    my_putstr("\n");
    while (box != NULL) {
        stat(box->d_name, &sb);
        name = box->d_name;
        type = box->d_type;
        box = readdir(dir);
        if (name[0] != '.') {
            if (box != NULL)
                is_dir(type, name, path, 1);
            else
                is_dir(type, name, path, 2);
        }
    }
    closedir(dir);
    return (0);
}
