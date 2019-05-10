/*
** EPITECH PROJECT, 2019
** Matchstick
** File description:
** Simple functions used by matchstick
*/

#include "matchstick.h"

int my_strncmp(char *str, char *str2)
{
    int i = 0;

    while (str[i] != '\0' && str2[i] != '\0') {
        if (str[i] == str2[i]) {
            i++;
        }
        else
            return (0);
    }
    return (1);
}

void my_putstr(char *str, int exit)
{
    write(exit, str, my_strlen(str));
    return;
}

int my_strlen(char *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    return (i);
}

int my_strlen_alpha(char *str, char param)
{
    int i = 0;

    for (int j = 0; str[j] != param; j++) {
        if (str[j] >= 48 && str[j] <= 57)
            i++;
    }
    return (i);
}

int p_ten(int times)
{
    int ten_power = 1;
    int i = 1;

    if (times != 1) {
        for (; i <= times; i++) {
            ten_power *= 10;
        }
    }
    return (ten_power);
}

int str_to_int(char *str, char param)
{
    int result = 0;
    int length = my_strlen_alpha(str, '\0');

    for (int i = 0; str[i] != param; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            result += (str[i] - '0') * p_ten(length);
            length -= 1;
        }
        else
            return (-1);
    }
    return (result);
}

int find_length(int nb)
{
    if (nb >= 10000)
        return (5);
    if (nb >= 1000)
        return (4);
    if (nb >= 100)
        return (3);
    if (nb >= 10)
	return (2);
    return (1);
}

void int_to_str(int nb, int base, char **nb_str, int choice)
{
    static int position = 0;

    if (choice == 0) {
        if (nb < 0) {
            (*nb_str)[position++] = '-';
            int_to_str((nb / base) * -1, base, nb_str, 0);
            (*nb_str)[position++] = ((nb % base) * -1) + '0';
        }
        else {
            if (nb >= base)
                int_to_str(nb / base, base, nb_str, 0);
            (*nb_str)[position++] = (nb % base) + '0';
        }
    }
    if (choice == 1)
        position = 0;
}
