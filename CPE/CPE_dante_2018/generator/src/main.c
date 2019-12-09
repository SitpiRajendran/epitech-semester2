/*
** EPITECH PROJECT, 2019
** CPE_duostumper2
** File description:
** Main
*/

#include "generator.h"
#include "time.h"

int main(int ac, char **av)
{
    struct maze_t maze;

    srand(time(NULL));
    if (ac < 3 || ac > 4)
        return (error("Argument Error : Number of Argument invalid\n"));
    if ((maze.nb_cols = atoi(av[1])) < 0)
        return (84);
    if ((maze.nb_rows = atoi(av[2])) < 0)
        return (84);
    if (maze.nb_cols >= 3 && maze.nb_rows >= 3) {
        if (ac == 3)
            generator(&maze, 0);
        if (ac == 4 && strcmp(av[3], "perfect") == 0)
            generator(&maze, 1);
    }
    return (0);
}
