/*
** EPITECH PROJECT, 2019
** CPE duo stumper
** File description:
** simple ls
*/

#include "my.h"

int tree_rec_d(char *path)
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
        if (name[0] != '.' && type == 4) {
            for (int i = 1; i != tabs; i++)
                my_putstr("   ");
            if (box != NULL)
                is_dir_d(type, name, path, 1);
            else
                is_dir_d(type, name, path, 2);
        }
    }
    tabs -= 1;
    closedir(dir);
    return (0);
}

void is_dir_d(int type, char *npath, char *path, int aze)
{
    if (type == 4) {
        if (aze == 1)
            my_putstr("|-- ");
        if (aze == 2)
            my_putstr("`-- ");
        my_putstr(npath);
        my_putchar('\n');
        path = my_strcat(path, "/");
        path = my_strcat(path, npath);
        tree_rec_d(path);
    }
}

int tree_d(char *path)
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
        if (name[0] != '.' && box != NULL)
            is_dir_d(type, name, path, 1);
        else if (name[0] != '.')
            is_dir_d(type, name, path, 2);
    }
    closedir(dir);
    return (0);
}
