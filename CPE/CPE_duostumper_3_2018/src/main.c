/*
** EPITECH PROJECT, 2019
** CPE_duostumper2
** File description:
** Main
*/

#include "my.h"

int main(int ac, char **av)
{
    if (ac < 3 || ac % 2 != 1)
        return error("Argument Error : Number of Argument invalid\n");
    if (ac == 3) {
        if (my_strcmp(av[1], "-n") != 0 || my_strisnum(av[2]) != 0)
            return error("Argument Error : Non Valid argument or parameters\n");
        print_while(av[2], "0");
    }
    if (ac == 5) {
        if ((my_strcmp(av[1], "-n") != 0 && my_strcmp(av[1], "-s")) ||
            (my_strcmp(av[3], "-n") != 0 && my_strcmp(av[3], "-s")))
            return error("Argument flag unvalid\n");
        if (my_strisnum(av[2]) != 0 && my_strisnum(av[4]) != 0)
            return error("Argument type unvalid (not numbers)\n");
        if (my_strcmp(av[1], "-n") == 1 && my_strcmp(av[3], "-s") == 1)
            print_while(av[4], av[2]);
        else if (my_strcmp(av[3], "-n") == 1 && my_strcmp(av[1], "-s") == 1)
            print_while(av[2], av[4]);
        else
            return error("Same flags detected\n");
    }
    return 0;
}
