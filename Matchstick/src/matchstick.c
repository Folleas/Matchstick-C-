/*
** EPITECH PROJECT, 2019
** Matchstick
** File description:
** Matchstick principal .c file
*/

#include "matchstick.h"

int action_player(int **map, int nb_lines, int max_take, int take, int from)
{
    if (take <= map[0][from - 1])
        map[0][from - 1] -= take;
    else {
        write (1, "Error: not enough matches on this line\n", 38);
        manage_player(map, nb_lines, max_take);
        return (0);
    }
    write (1, "Player removed ", 15);
    display_number(take);
    write (1, " match(es) from line ", 21);
    display_number(from);
    write(1, "\n", 1);
    return (1);
}

int manage_player(int **map, int nb_lines, int max_take)
{
    int take = 0;
    int from = 0;
    int return_from;
    int return_take;

    write (1, "\nLine: ", 7);
    return_from = from_player(&from, nb_lines);
    if (return_from == 0 || return_from == 2) {
        if (return_from == 2)
            write(1, "Error: invalid input (positive number expected)", 47);
        manage_player(map, nb_lines, max_take);
        return (0);
    }
    write (1, "Matches: ", 10);
    return_take = take_player(&take, max_take);
    if (return_take == 0 || return_take == 2) {
        if (return_take == 2)
            write(1, "Error: invalid input (positive number expected)", 47);
        manage_player(map, nb_lines, max_take);
        return (0);
    }
    if (action_player(map, nb_lines, max_take, take, from) == 0)
        return (0);
    return (0);
}

void ia_matchstick(int **map, int nb_lines)
{
    int take;

    write (1, "\nIA's turn...\n", 14);
    for (int i = nb_lines; i != 0; i--) {
        if (map[0][i] != 0) {
            take = random() % map[0][i];
            if (take == 0)
                take++;
            map[0][i] -= take;
            write (1, "AI removed ", 11);
            display_number(take);
            write (1, " match(es) from line ", 21);
            display_number(i + 1);
            write(1, "\n", 1);
            return;
        }
    }
}

int init_game(int ac, char **av, int *nb_lines, int **map, int *max_take, int *max_pipes)
{
    if (ac == 2 && my_strncmp(av[1], "-h")) {
        my_putstr("Correct Usage :\ti : map size (int)\n\t\tj : max number of matches per turn (int)\n\n\t\t./matchstick i j\n", 1);
        exit(1);
    }
    if (ac != 3) {
        my_putstr("Error : Incorrect declaration\nYou should check -h\n", 2);
        return (84);
    }
    if ((*nb_lines = str_to_int(av[1], '\0')) == -1) {
        my_putstr("Error : Incorrect declaration\nYou should check -h\n", 2);
        return (84);
    }
    (*map) = malloc(sizeof(int) * *nb_lines);
    if ((*max_take = str_to_int(av[2], '\0')) == -1) {
        my_putstr("Error : Incorrect declaration\nYou should check -h\n", 2);
        return (84);
    }
    fill_map(&map[0], *nb_lines);
    *max_pipes = (*map)[*nb_lines - 1];
    return (1);
}

int main(int ac, char **av)
{
    int nb_lines;
    int max_pipes;
    int max_take;
    int *map;

    if (init_game(ac, av, &nb_lines, &map, &max_take, &max_pipes) == 84)
        return (84);
    while (1) {
        display_map(map, nb_lines, max_pipes);
        write(1, "\nYour turn:", 11);
        if (manage_player(&map, nb_lines, max_take) == -1)
            break;
        display_map(map, nb_lines, max_pipes);
        if (check_end(map, nb_lines, 1) == FALSE)
            return (2);
        ia_matchstick(&map, nb_lines);
        if (check_end(map, nb_lines, 0) == FALSE)
            return (1);
    }
    free (map);
    return (0);
}
