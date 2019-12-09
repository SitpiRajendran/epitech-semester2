/*
** EPITECH PROJECT, 2019
** PSU_Navy
** File description:
** connection
*/

#include "my.h"

int play(char **my_map, char **enemy_map, char *input, int pid)
{
    my_putstr("my_positions:\n");
    print_map(my_map);
    my_putstr("enemy's positions:\n");
    print_map(enemy_map);
    my_putstr("attack: ");
    if ((my_strlen(input = get_next_line(1))) != 2)
        return (84);
    game(my_map, enemy_map, input, pid);
    return (0);
}

int waiting_to_play(char **my_map, char **enemy_map, char *input, int pid)
{
    my_putstr("my positions:\n");
    print_map(my_map);
    my_putstr("enemy's positions:\n");
    print_map(enemy_map);
    my_putstr("waiting for enemy's attack...\n");
    if ((my_strlen(input = get_next_line(1))) != 2)
        return (84);
    game(my_map, enemy_map, input, pid);
    return (0);
}

void catch_connection(int signum)
{
    signum = signum;
    my_putstr("\nenemy connected\n\n");
}

int player_one(char *path)
{
    int pid_player1 = getpid();
    char **my_map = init_map();
    char **enemy_map = init_map();
    char *input = malloc(sizeof(char) * 2);
    struct sigaction act;

    my_map = first_add_map(orstr(path), my_map);
    if (my_map == NULL)
        return (84);
    act.sa_handler = &catch_connection;
    sigemptyset(&act.sa_mask);
    sigaction(SIGUSR2, &act, NULL);
    my_putstr("my_pid: ");
    my_put_nbr(pid_player1);
    my_putstr("\nwaiting for enemy connection...\n");
    pause();
    play(my_map, enemy_map, input, pid_player1);
    return (0);
}

int player_two(char *strpid, char *path)
{
    int pid_player1 = my_getnbr(strpid);
    int pid_player2 = getpid();
    char **my_map = init_map();
    char **enemy_map = init_map();
    char *input = malloc(sizeof(char) * 2);

    my_map = first_add_map(orstr(path), my_map);
    if (my_map == NULL)
        return (84);
    if (kill(pid_player1, SIGUSR2) == -1)
        return (84);
    my_putstr("my_pid: ");
    my_put_nbr(pid_player2);
    my_putstr("\n");
    my_putstr("successfully connected\n\n");
    waiting_to_play(my_map, enemy_map, input, pid_player1);
    return (0);
}
