/*
** EPITECH PROJECT, 2019
** CPE duostumper1
** File description:
** my h
*/

#ifndef MY_H_
#define MY_H_

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <inttypes.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

typedef struct options_b
{
    int a;
    int d;
    int L;
    int f;
} option_t;

/*side functions*/
void my_putchar(char c);
int my_putstr(char const *str);
int my_putstr_error(char const *str);
int my_strlen(char const *str);
char *my_strcat(char *dest, char const *src);

/*basic tree*/
option_t option_checker(char *str, option_t option_s);
void calls(option_t option_s, char *path);
int options(char *option, char *path);
void is_dir(int type, char *npath, char *path, int aze);
void is_dir_f(int type, char *npath, char *path, int aze);
void is_dir_a(int type, char *npath, char *path, int aze);
void is_dir_d(int type, char *npath, char *path, int aze);
int simple_tree(char *path);
struct dirent *box_dirent(char *path, DIR *dir);
int tree_f(char *path);
int tree_a(char *path);
int tree_d(char *path);
#endif
