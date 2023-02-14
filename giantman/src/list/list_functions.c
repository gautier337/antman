/*
** EPITECH PROJECT, 2022
** lists_functions
** File description:
** giantman
*/

#include "giantman.h"

elem_t *init_list(global_t *global, char *string)
{
    elem_t *head = malloc(sizeof(elem_t));
    char *f_word = malloc(sizeof(char) * my_strlen(string) + 1);

    if (!f_word || !head || !string || !global)
        return NULL;
    global->i = 2;
    for (int i = 0; string[i] != '\0'; i += 1) {
        if (string[i] != global->data_decompress)
            f_word[i] = string[i];
        else {
            head = create_list(1, f_word);
            return head;
        }
    }
    free(f_word);
}

void add_word(global_t *global, char *word)
{
    if (add_node(global->list, global->i, word) != NULL)
        global->i += 1;
}

char *forward_string(char *string, global_t *global)
{
    for (int i = 0; string[0] != global->data_decompress; i++)
        string += 1;
    string++;
    return string;
}

elem_t *fill_list(global_t *global, char *string)
{
    elem_t *head = global->list;
    char *word = malloc(sizeof(char) * my_strlen(string) + 1);
    int y = 0;
    int j = 0;

    if (!word || !global || !string)
        return NULL;
    string = forward_string(string, global);
    for (int i = 0; y <= global->nbr_at && string[i] != '\0'; i += 1) {
        if (string[i] == global->data_decompress) {
            add_word(global, word);
            word = malloc(sizeof(char) * my_strlen(string) + 1);
            y += 1;
            j = 0;
        } else {
            word[j] = string[i];
            j += 1;
        }
    }
    return head;
}
