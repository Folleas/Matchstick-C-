/*
** EPITECH PROJECT, 2019
** Matchstick
** File description:
** Functions that manage inputs
*/

#include "matchstick.h"

int from_player(int *from, int nb_lines)
{
    size_t len = 0;
    char *input = NULL;

    if (getline(&input, &len, stdin) == -1)
        return (-1);
    *from = str_to_int(input, '\n');
    if (*from == -1)
        return (2);
    if (*from > nb_lines) {
        write (1, "Error: this line is out of range", 32);
        return (0);
    }
    return (1);
}

int take_player(int *take, int max_take)
{
    size_t len = 0;
    char *input = NULL;

    if (getline(&input, &len, stdin) == -1)
        return (-1);
    *take = str_to_int(input, '\n');
    if (*take == -1)
        return (2);
    if (*take > max_take) {
        write (1, "Error: you cannot remove more than 5 matches per turn\n", 53);
        return (0);
    }
    return (1);
}

void display_number(int nb)
{
    int length = find_length(nb);
    char *nb_str = malloc(sizeof(char) * length);

    int_to_str(nb, 10, &nb_str, 0);
    write(1, nb_str, length);
    int_to_str(nb, 10, &nb_str, 1);
}
