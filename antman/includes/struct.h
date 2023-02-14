/*
** EPITECH PROJECT, 2022
** antman
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
    elem_t *list;
    char *pos;
    char *words;
    int i;
    int cur_data;
    int data_decompress;
} global_t;
