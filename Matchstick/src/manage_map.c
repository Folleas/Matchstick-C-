/*
** EPITECH PROJECT, 2019
** Matchstick
** File description:
** Map managing functions
*/

#include "matchstick.h"

void fill_map(int **map, int nb_lines)
{
    int count = 1;

    for (int i = 0; i != nb_lines; i++) {
        map[0][i] = count;
        count += 2;
    }
}

int check_end(int *map, int nb_lines, int choice)
{
    int count = 0;

    for (int i = 0; i != nb_lines; i++) {
        if (map[i] == 0)
            count++;
    }
    if (count == nb_lines) {
        if (choice == 0)
            write(1, "I lost... snif... but I'll get you next time!!\n", 47);
        if (choice == 1)
            write(1, "You lost, too bad...\n", 21);
        return (FALSE);
    }
    return (TRUE);
}
