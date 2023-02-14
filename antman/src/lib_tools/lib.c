/*
** EPITECH PROJECT, 2022
** antman
** File description:
** compress files
*/

#include "antman.h"

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i += 1;
    }
    return i;
}

int is_neg(char const *str)
{
    int i = 0;
    int neg = 1;

    while (!(str[i] >= '0' && str[i] <= '9')) {
        if (str[i] == '-') {
            neg *= -1;
        }
        i += 1;
    }
    return neg;
}

int my_getnbr(char const *str)
{
    int i = 0;
    int nbr = 0;
    int neg = is_neg(str);

    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            nbr *= 10;
            nbr += str[i] - 48;
        }
        i += 1;
    }
    nbr *= neg;
    return nbr;
}

char *my_strcat(char *dest, char const *src)
{
    int a = my_strlen(dest);
    int i = 0;

    while (src[i] != '\0') {
        dest[a + i] = src[i];
        i += 1;
    }
    return dest;
}
