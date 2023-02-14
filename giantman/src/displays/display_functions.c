/*
** EPITECH PROJECT, 2022
** display_functions
** File description:
** display_functions
*/

#include "giantman.h"

void get_and_print_last(global_t *global, int nb)
{
    elem_t *head = global->list;

    while (global->list->next != NULL) {
        if (nb == global->list->data)
            my_putstr(global->list->word);
        global->list = global->list->next;
    }
    if (nb == global->list->data)
        my_putstr(global->list->word);
    global->list = head;
}

void get_and_print_word(global_t *global, int nb)
{
    elem_t *head = global->list;

    while (global->list->next != NULL) {
        if (nb == global->list->data) {
            my_putstr(global->list->word);
            my_putchar(global->cur_data);
        }
        global->list = global->list->next;
    }
    if (nb == global->list->data) {
        my_putstr(global->list->word);
        my_putchar(global->cur_data);
    }
    global->list = head;
}

int check_and_print_word(global_t *global, char *string)
{
    int nb = 0;

    if (!global || !string)
        return 84;
    for (;string[0] != '\0';) {
        if (string[0] == '.')
            string++;
        nb = my_getnbr(string);
        if (string[lenght_int(nb) + 1] == '\0') {
            get_and_print_last(global, nb);
            return 0;
        } else
            get_and_print_word(global, nb);
        for (int i = 0; i < lenght_int(nb); i += 1)
            string++;
    }
}

int print_decompressed(global_t *global, char *string)
{
    int y = 0;

    if (!string || !global)
        return 84;
    for (;string[0] != '\0';) {
        if (global->nbr_at == y) {
            if (check_and_print_word(global, string) == 84)
                return 84;
            return 0;
        }
        if (string[0] == global->data_decompress)
            y += 1;
        string++;
    }
}
