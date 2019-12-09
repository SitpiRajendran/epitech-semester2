/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** my.h of the minishell2 project
*/

#ifndef MY_H_
#define MY_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <wait.h>
#include <signal.h>
#include "my_struct.h"

int create_my_terminal(mini_t *, char **);
int initialise_my_struct(mini_t *, char **);
char *my_strcat(char *, char *);
void check_my_buffer(mini_t *, char *);
void check_exit(mini_t *);
void check_cd(mini_t *, char *);
void check_exe(mini_t *);
b_list_t *check_command_pipe(mini_t *, b_list_t *);
b_list_t *check_command_redirection(mini_t *, b_list_t *);
b_list_t *check_command_separator(mini_t *, b_list_t *);
int change_dollar_sec(mini_t *, char *, int);
int check_list_end(b_list_t *);
void compare_my_functions(mini_t *, char *);
int create_my_list(mini_t *, char *);
void display_my_list(b_list_t *);
int check_buffer_operator(mini_t *, char *);
int check_command_operator(char *);
int handle_pipe(char *, char *, mini_t *);
int handle_pipe_sec(int *, mini_t *);
void put_operator_in_list(mini_t *, char *);
b_list_t *add_element_after(b_list_t *, char *);
int check_my_env(mini_t *);
void check_setenv(mini_t *);
void check_unsetenv(mini_t *);
int check_exit_value(mini_t *, char *);
char *remove_my_space(char *);
char **remove_my_env(char **, int);
int check_setenv_second_arg(mini_t *, char *);
char *copy_my_env_line(char *, char *);
void count_my_arg(mini_t *, char *);
void stock_my_arg(mini_t *, char *);
void error_status(int);
void put_command_in_list(mini_t *, char *);
int command_error_management(mini_t *, char *);
int first_operator_error(mini_t *, char *, int);
int second_operator_error(mini_t *, char *, int);
char *put_space_between_operator(char *);
char *check_operator_side(char *, int, int);
char *check_operator_side_sec(char *, char *, int);
char *check_redirection(char *, int, int);
char *check_redirection_sec(char *, char *, int);
char *check_double_redirection(char *, char *, int);
char *check_double_redirection_sec(char *, char *, int);
char *check_separator(char *, int, int);
char *check_separator_sec(char *, char *, int);
char *check_double_separator(char *, char *, int);
char *check_double_separator_sec(char *, char *, int);
char *get_my_home_path(mini_t *);
char *modif_my_buffer(char *);
char *replace_tab_by_space(char *);
char *copy_start_buffer(char *, char *, int);
char *copy_my_buffer(char *, char *, int, int);
char **add_in_my_env(char **, char *);
char *change_my_buffer(char *, char *, int);
void display_cd_error(char *);
int my_arg_len(char *, int);
int my_strcmp(char *, char *, int);
int my_strncmp(char *, char *, int);
char *my_strncpy(char *, char *, int, int);
int create_my_fork(mini_t *);
int find_my_env(mini_t *, char *);
int find_my_path(mini_t *);
int find_my_bin_path(mini_t *, int);
char *fill_my_adress(mini_t *, char *, int, int);
int my_strstrlen(char **);
void change_my_env_path(mini_t *, char *);
int scan_my_setenv_buffer(mini_t *);
int aplhanumeric_verification(char);
int manage_my_cd_hyphen(mini_t *, char *);
void display_my_perror(char *);
int copy_my_env(mini_t *, char **);
void display_my_env(mini_t *);
int my_putnbr(int);
void my_putchar(char);
void my_perror(char);
void my_putstr(char *, int);
int my_getnbr(mini_t *, char *);
int my_strlen(char *);
void display_exec_error(mini_t *);
int my_redirections(mini_t *, b_list_t *, int);
void check_echo(mini_t *);
int search_env(char **, char *);
char *get_in_env(char **, char *);
void change_dollar(mini_t *);
char *my_revstr(char *);
char *my_itoc(int);
char *delete_dollar(char *);
void free_linked_twist(mini_t *, b_list_t *);
void free_structure(mini_t *);
void free_buffer(char *);
void free_tab_buffer(char **);
int or_separator(mini_t *, b_list_t *);
int and_separator(mini_t *, b_list_t *);
int read_from_keyboard_redirection(mini_t *, b_list_t *);
void put_in_history(char *, mini_t *);
void print_history(mini_t *);
void free_history(mini_t *);
void print_one_history(mini_t *);

#endif
