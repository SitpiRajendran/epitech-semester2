/*
1;5202;0c** EPITECH PROJECT, 2019
** duo stumper
** File description:
** handle victory
*/

#include "my.h"

/*
void replace_referee(char **board, int x, int y, int rvalue)
{
    if (rvalue == 1) {
        for (int i = y; i != (y - 3) && board[x][i] == board[x][y]; i--)
            board[x][i] = '#';
        for (int j = y; j != (y + 3) && board[x][j] == board[x][y]; j++)
            board[x][j] = '#';
    }
    if (rvalue == 2) {
        for (int k = x; k != (x - 3) && board[k][y] == board[x][y]; k--)
            board[k][y] = '#';
        for (int m = x; m != (x + 3) && board[m][y] == board[x][y]; m++)
            board[m][y] = '#';
    }
    replace_referee_2(board, x, y, rvalue);
}

void replace_referee_2(char **board, int x, int y, int rvalue)
{
    if (rvalue == 3) {
        for (int i = y, int k = x; i != (y - 3) && k != (x - 3)
                 && board[k][i] == board[x][y]; i--, k--)
            board[k][i] = '#';
        for (int j = y, int m = x; j != (y + 3) && m != (x + 3)
                 && board[m][j] == board[x][y]; j--, m--)
            board[m][j] = '#';
    }
    if (rvalue == 4) {
        for (int a = y, int c = x; a != (y - 3) && c != (x + 3)
                 && board[c][a] == board[x][y]; a--, c--)
            board[c][a] = '#';
        for (int b = y, int d = x; b != (y + 3) && d != (x - 3)
                 && board[d][b] == board[x][y]; b--, d--)
            board[d][b] = '#';
    }
    }
*/

int check_victory(char **board, int x, int y, char **infos)
{
    int count = 1;
    int max_x = my_getnbr(infos[0]);
    int max_y = my_getnbr(infos[y]);

    for (int i = y; i > 0 && board[x][i] == board[x][y]; i--)
        count++;
    for (int j = y; j <= max_y && board[x][j] == board[x][y]; j++)
        count++;
    if (count >= 4)
        return (1);
    count = 1;
    for (int k = x; k > 0 && board[k][y] == board[x][y]; k--)
        count++;
    for (int m = x; m <= max_x && board[m][y] == board[x][y]; m++)
        count++;
    if (count >= 4)
        return (2);
    return (check_victory_diagonals(board, x, y, infos));
}

int check_victory_diagonals(char **board, int x, int y, char **infos)
{
    int count = 1;
    int i;
    int k;
    int m_x = my_getnbr(infos[1]);
    int m_y = my_getnbr(infos[0]);

    for (i = y, k = x; i > 0 && k > 0 && board[k][i] == board[x][y]; i--, k--)
        count++;
    for (i = y, k = x; i < m_x && k < m_y
             && board[k][i] == board[x][y]; i++, k++)
        count++;
    if (count >= 4)
        return (3);
    count = 1;
    for (i = y, k = x; i > 0 && k < m_x && board[k][i] == board[x][y]; i--, k++)
        count++;
    for (i = y, k = x; k > 0 && i < m_y && board[k][i] == board[x][y]; i++, k--)
        count++;
    if (count >= 4)
        return (4);
    return (0);
}
