/*
** EPITECH PROJECT, 2019
** MUL Defender
** File description:
** score counting
*/

#include "defender.h"

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i = i + 1;
    return (i);
}

char *my_strcat(char *dest, char const *scr)
{
    int f = 0;
    char *nw = malloc(sizeof(char *) *(my_strlen(dest) + my_strlen(scr) +1));
    int i = 0;

    if (scr == NULL)
        return (NULL);
    for (; dest[i] != '\0'; i++)
        nw[i] = dest[i];
    nw[i] = '\0';
    for (; nw[f] != '\0'; f = f + 1);
    for (i = 0; scr[i] != '\0'; i++) {
        if (scr[i] != '\n') {
            nw[f] = scr[i];
            f++;
        }
    }
    nw[f] = '\0';
    return (nw);
}

char *my_revstr(char *str)
{
    int i = 0;
    int len = my_strlen(str);
    char c;

    while (i < len / 2){
    c = *(str + i);
        *(str + i) = *(str + len - i -1);
        *(str + len - i -1) = c;
        i++;
    }
    return (str);
}

char *my_itoa(int nbr)
{
    int i = 0;
    char *str = malloc(sizeof(char) * 9);

    while (nbr > 9) {
        str[i] = (nbr % 10) + 48;
        nbr = (nbr - (nbr % 10)) / 10;
        i++;
    }
    str[i] = nbr + 48;
    str[i + 1] = '\0';
    str = my_revstr(str);
    return (str);
}

int score_count(sfText *text, int score)
{
    score++;
    sfText_setString(text, my_strcat(my_itoa(score / 10), "$"));
    return (score);
}