/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** all library functions
*/

#include "my.h"

int my_getnbr(mini_t *mini_s, char *number)
{
    int nbr = 0;
    int neg = 0;

    if (number[0] == '-')
        neg = 1;
    for (int y = neg; number[y] != '\0'; y++)
        if (number[y] < '0' || number[y] > '9')
            mini_s->error = 1;
    for (int i = neg; number[i] != '\0'; i++)
        nbr = (nbr + number[i] - 48) * 10;
    nbr = (nbr / 10);
    if (neg == 1)
        nbr = nbr * (-1);
    return (nbr);
}

int my_putnbr(int nb)
{
    if (nb >= 10) {
        my_putnbr(nb / 10);
        my_putchar(nb % 10 + 48);
    }
    if (nb >= 0 && nb < 10)
        my_putchar(nb + 48);
    if (nb < 0) {
        my_putchar(45);
        my_putnbr(-nb);
    }
    return (0);
}

void my_putstr(char *buffer, int mode)
{
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (mode == 1)
            my_putchar(buffer[i]);
        if (mode == 2)
            my_perror(buffer[i]);
    }
}

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_perror(char c)
{
    write(2, &c, 1);
}