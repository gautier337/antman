/*
** EPITECH PROJECT, 2022
** giantman
** File description:
** compress a file
*/

typedef struct elem {
    int data;
    char *word;
    struct elem *next;
    struct elem *previous;
} elem_t;

typedef struct global {
    int nbr_at;
    elem_t *list;
    int i;
    char *output;
    int cur_data;
    int data_decompress;
} global_t;
