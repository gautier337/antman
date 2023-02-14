/*
** EPITECH PROJECT, 2022
** free_all
** File description:
** antman
*/

#include "antman.h"

void free_all(global_t *global, char *f_word)
{
    free(global->pos);
    free(global->words);
    free(f_word);
}
