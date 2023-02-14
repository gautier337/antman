/*
** EPITECH PROJECT, 2022
** antman
** File description:
** compress files
*/

#include "giantman.h"

int my_strcmp (char const *s1, char const *s2)
{
    int i = 0;
    int count;
    int value = 0;

    while (s1[i] != '\0' && s2[i] != '\0') {
        count = s1[i] - s2[i];
        if (count < 0 || count > 0) {
            return 0;
        } else
            i++;
    }
    if (my_strlen(s1) > my_strlen(s2)) {
        return 0;
    } else if (my_strlen(s1) < my_strlen(s2)) {
        return 0;
    }
    return 2;
}

int lenght_int(int nbr)
{
    int count = 0;

    if (nbr > 0)
        count = 1;

    while (nbr >= 10) {
        nbr = nbr / 10;
        count++;
    }
    return count;
}

char *convert_int(int nb)
{
    char *str = malloc(lenght_int(nb));
    int i = 1;
    int j = 0;

    if (nb < 0) {
        str[0] = ('-');
        convert_int(nb * -1);
        return 0;
    }
    for (int a = nb; a > 9;) {
        a = a / 10;
        i = i * 10;
    }
    while (i >= 1) {
        str[j] = (((nb / i) % 10) + '0');
        i = i / 10;
        j += 1;
    }
    str[j] = '\0';
    return str;
}
