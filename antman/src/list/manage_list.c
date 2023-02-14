/*
** EPITECH PROJECT, 2022
** antman
** File description:
** compress a file
*/

#include "antman.h"

elem_t *create_list(int val, char *word)
{
    elem_t *list = malloc(sizeof(elem_t));

    if (!list)
        return NULL;
    list->data = val;
    list->word = word;
    list->next = NULL;
    list->previous = NULL;
    return list;
}

int check_list_for_word(elem_t *list, char *word)
{
    int nb = 0;

    while (list->next != NULL) {
        if (my_strcmp(list->word, word) == 2) {
            nb = list->data;
            return nb;
        }
        list = list->next;
    }
    if (my_strcmp(list->word, word) == 2) {
        nb = list->data;
        return nb;
    }
    return nb;
}

elem_t *add_node(elem_t *list, int val, char *word)
{
    elem_t *head = list;
    elem_t *node = malloc(sizeof(elem_t));

    if (!node || !head)
        return NULL;
    while (list->next != NULL)
        list = list->next;
    list->next = node;
    node->data = val;
    node->word = word;
    node->next = NULL;
    node->previous = list;
    return head;
}

int destroy_list(elem_t *list)
{
    if (!list)
        return 84;
    while (list->next != NULL)
        list = list->next;
    while (list->previous != NULL) {
        list = list->previous;
        free(list->next);
    }
    free(list);
}
