/*
** EPITECH PROJECT, 2022
** antman
** File description:
** compress a file
*/

#include "giantman.h"

int main(int argc, char **argv)
{
    if (check_errors(argc, argv) == 84) {
        return 84;
    }
    return giantman(argv[1], my_getnbr(argv[2]), argv);
}
