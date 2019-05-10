/*
** EPITECH PROJECT, 2019
** Matchstick
** File description:
** Displaying functions
*/

#include "matchstick.h"

void map_ends(int max_pipes)
{
    for (int i = 0; i != max_pipes + 2; i++) {
        write(1, "*", 1);
    }
    write(1, "\n", 1);
}

void map_spaces(int nb_pipes, int max_pipes, int choice)
{
    int i = 0;

    if (choice == 1) {
        if (nb_pipes % 2 == 0)
            i -= 1;
    }
    for (; i != (max_pipes - nb_pipes) / 2; i++)
        write (1, " ", 1);
}

void map_pipes(int nb_pipes)
{
    for (int i = 0; i != nb_pipes; i++) {
        write (1, "|", 1);
    }
}

void map_core(int nb_pipes, int max_pipes)
{
    write (1, "*", 1);
    map_spaces(nb_pipes, max_pipes, 0);
    map_pipes(nb_pipes);
    map_spaces(nb_pipes, max_pipes, 1);
    write (1, "*", 1);
    write (1, "\n", 1);
}

void display_map(int *map, int nb_lines, int max_pipes)
{
    map_ends(max_pipes);
    for (int count = 0; count != nb_lines; count++) {
        map_core(map[count], max_pipes);
    }
    map_ends(max_pipes);
}
