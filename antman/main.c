/*
** EPITECH PROJECT, 2022
** antman
** File description:
** compress a file
*/

#include "antman.h"

int main(int argc, char **argv)
{
    if (check_errors(argc, argv) == 84) {
        return 84;
    }
    return antman(argv[1], my_getnbr(argv[2]), argv);
}
