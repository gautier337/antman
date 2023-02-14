/*
** EPITECH PROJECT, 2022
** antman
** File description:
** compress a file
*/

#include "giantman.h"

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

elem_t *add_node(elem_t *list, int val, char *word)
{
    elem_t *head = list;
    elem_t *node = malloc(sizeof(elem_t));

    if (!node || !head || !word)
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

void destroy_list(elem_t *list)
{
    while (list->next != NULL)
        list = list->next;
    while (list->previous != NULL) {
        list = list->previous;
        free(list->next);
    }
    free(list);
}
