/*
** EPITECH PROJECT, 2022
** antman
** File description:
** list_functions
*/

#include "antman.h"

int malloc_word_nbr(char *string, global_t *global)
{
    int i = 0;

    for (; string[i] != global->cur_data; i++);
    return i;
}

elem_t *init_list(char *string, global_t *global)
{
    elem_t *head = malloc(sizeof(elem_t));
    char *f_word = malloc(sizeof(char) * malloc_word_nbr(string, global) + 1);

    global->pos = malloc(sizeof(char) * my_strlen(string) + 1);
    global->words = malloc(sizeof(char) * my_strlen(string) + 1);
    if (!head || !f_word || !string || !global
        || !global->pos || !global->words)
        return head;
    global->pos[0] = '1';
    for (int i = 0; string[i] != '\0'; i += 1) {
        if (string[i] != global->cur_data)
            f_word[i] = string[i];
        else {
            head = create_list(1, f_word);
            my_strcat(global->words, f_word);
            my_strcat(global->words, "~");
            return head;
        }
    }
    free_all(global, f_word);
}

void add_word(global_t *global, char *word)
{
    int nb = check_list_for_word(global->list, word);

    if (nb == 0) {
        add_node(global->list, global->i, word);
        my_strcat(global->words, word);
        my_strcat(global->words, "~");
        my_strcat(global->pos, ".");
        my_strcat(global->pos, convert_int(global->i));
        global->i += 1;
    } else {
        my_strcat(global->pos, ".");
        my_strcat(global->pos, convert_int(nb));
    }
}

int call_add_word(char *string, global_t *global)
{
    char *word = malloc(sizeof(char) * my_strlen(string) + 1);
    int y = 0;

    if (!word)
        return 84;
    for (int i = 0; string[i - 1] != '\0'; i++) {
        if (!word)
            return 84;
        if (string[i] != global->cur_data && string[i] != '\0') {
            word[y] = string[i];
            y++;
        } else {
            add_word(global, word);
            word = malloc(sizeof(char) * my_strlen(string) + 1);
            y = 0;
        }
    }
    free(word);
}

elem_t *fill_list(char *string, global_t *global)
{
    elem_t *head = global->list;

    if (!head || !string || !global)
        return NULL;
    for (int i = 0; string[0] != global->cur_data; i++)
        string += 1;
    string++;
    call_add_word(string, global);
    return head;
}
