/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** handle pipe functions
*/

#include "my.h"

int handle_pipe_sec(int *fd, mini_t *m)
{
    pid_t pid = fork();

    if (pid == -1)
        exit(84);
    if (pid > 0) {
        dup2(fd[1], STDOUT_FILENO);
        compare_my_functions(m, m->root->command);
        dup2(STDIN_FILENO, STDOUT_FILENO);
    } else if (pid == 0) {
        dup2(fd[0], STDIN_FILENO);
        compare_my_functions(m, m->root->next->next->command);
        dup2(STDOUT_FILENO, STDIN_FILENO);
        exit(0);
    }
    return (0);
}

int handle_pipe(char *fir_command, char *sec_command, mini_t *mini_s)
{
    pid_t pid = fork();
    int fd[2];

    if (pid == -1)
        return (84);
    if (pid == 0) {
        if (pipe(fd) == -1)
            exit(84);
        if (handle_pipe_sec(fd, mini_s) == 84)
            exit(84);
        close(*fd);
        exit(0);
    } else if (pid > 0) {
        wait(&pid);
    }
    return (0);
}