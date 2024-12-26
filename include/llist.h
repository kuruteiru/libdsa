#ifndef LLIST_H
#define LLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct llist_node {
    void *value;
    struct llist_node *next;
} llist_node_t;

typedef struct llist {
    size_t length;
    llist_node_t *head;
} llist_t;

llist_node_t* llist_create_node(void *value);
llist_t* llist_initialize(void);
void llist_destroy(llist_t **self);
void llist_clear(llist_t *self);
bool llist_is_empty(llist_t *self);
bool llist_includes(llist_t *self, bool (*compare)(), void *value);
void llist_push(llist_t *self, void *value);
void llist_pop(llist_t *self);
void llist_print(llist_t *self, void (*print)());
llist_node_t* llist_find(llist_t *self, bool (*compare)(), void *value);

#endif //LLIST_H
