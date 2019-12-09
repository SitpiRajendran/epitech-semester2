/*
** EPITECH PROJECT, 2019
** PSU Tetris
** File description:
** Help
*/

#include "tetris.h"

int help(char *str)
{
    write(1, "Usage:  ", 8);
    write(1, str, my_strlen(str));
    write(1, " [options]\nOptions:\n", 20);
    write(1, "  --help\t\tDisplay this help\n  -L --level={num}\t", 47);
    write(1, "Start Tetris at level num (def: 1)\n  -l --key-left={K}\t", 55);
    write(1, "Move the tetrimino LEFT using the K key (def: left", 50);
    write(1, " arrow)\n  -r --key-right={K}\tMove the tetrimino RIGHT", 53);
    write(1, " using the K key (def: right arrow)\n  -t --key-turn={K}", 55);
    write(1, "\tTURN the tetrimino clockwise 90d using the K key)", 50);
    write(1, " (def: toparrow)\n  -d --key-drop={K}\tDROP the tetrimino ", 56);
    write(1, "using the K key (def: down arrow)\n  -q --key-quit={K}\t", 54);
    write(1, "QUIT the game using the K key (def: 'q' key)\n  -p", 49);
    write(1, " --key-pause={K}\tPAUSE/RESTART the game using the K key", 55);
    write(1, " (def: space bar)\n  --map-size={row,col}\t", 41);
    write(1, "Set the numbers of rows and columns of the map", 46);
    write(1, " (def: 20,10)\n  -w --without-next\tHide next tetrimino ", 54);
    write(1, "(def: false)\n  -D --debug\t\tDebug mode (def: false)\n", 51);

    return 0;
}