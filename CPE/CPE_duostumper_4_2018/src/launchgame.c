/*
** EPITECH PROJECT, 2019
** DuoStumper
** File description:
** launch game
*/

#include "pokemon.h"

void first_poke(t_pokinfo *one, t_pokinfo *two)
{
    int n;
    int j;

    n = rand() % one->att;
    printf("%s attack for %d damage\n", one->name, n);
    j = n - two->def;
    if (j > 0) {
        two->lif -= j;
        printf("%s blocks %d damage\n", two->name, two->def);
        if (two->lif < 0)
            printf("%s loses %d health (0 left)\n", two->name, j);
        else
            printf("%s loses %d health (%d left)\n", two->name, j, two->lif);
    } else
        printf("%s blocks %d damage\n", two->name, two->def);
}

void launch_game(t_pokinfo *one, t_pokinfo *two)
{
    while (one->lif > 0 && two->lif > 0) {
        first_poke(one, two);
        if (two->lif > 0)
            first_poke(two, one);
    }
    if (two->lif <= 0)
        printf("%s is KO\n%s wins the fight!\n", two->name, one->name);
    else
        printf("%s is KO\n%s wins the fight!\n", one->name, two->name);
}
