/*
** EPITECH PROJECT, 2019
** CPE duo stumper
** File description:
** simple ls
*/

#include "my.h"

int tree_rec_a(char *path)
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
        if (name[0] == '.' && (name[1] == '\0' || (name[1] == '.' && name[2] == '\0')));
        else {
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

void is_dir_a(int type, char *npath, char *path, int aze)
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
        tree_rec_a(path);
    }
}

int tree_a(char *path)
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
        if (name[0] == '.' && (name[1] == '\0' ||
                               (name[1] == '.' && name[2] == '\0')));
        else if (box != NULL)
            is_dir(type, name, path, 1);
        else
            is_dir(type, name, path, 2);
        }
    closedir(dir);
    return (0);
}
