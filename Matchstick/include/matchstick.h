/*
** EPITECH PROJECT, 2019
** Matchstick
** File description:
** Matchstick's header
*/

#ifndef MATCHSTICK
#define MATCHSTICK

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define TRUE 1
#define FALSE 0

//simple_functions.c
int my_strlen(char *str);
int my_strlen_alpha(char *str, char param);
int p_ten(int times);
int str_to_int(char *str, char param);
void int_to_str(int nb, int base, char **nb_str, int choice);
int find_length(int nb);
void my_putstr(char *str, int exit);
int my_strncmp(char *str, char *str2);

//manage_map.c
void fill_map(int **map, int nb_lines);
int check_end(int *map, int nb_lines, int choice);

//display_map.c
void map_ends(int max_pipes);
void map_spaces(int nb_pipes, int max_pipes, int choice);
void map_pipes(int nb_pipes);
void map_core(int nb_pipes, int max_pipes);
void display_map(int *map, int nb_lines, int max_pipes);

//matchstick.c
int manage_player(int **map, int nb_lines, int max_take);
void ia_matchstick(int **map, int nb_lines);
int handle_error(int **map, int ac, char *arg1, char *arg2, int *nb_lines, int *max_take);

//manage_player.c
int take_player(int *take, int nb_lines);
int from_player(int *from, int max_take);
void display_number(int nb);

#endif
