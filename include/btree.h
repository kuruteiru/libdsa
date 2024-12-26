#ifndef BTREE_H
#define BTREE_H

#include <stdbool.h>

typedef struct btree_node {
    void *data;
    struct btree_node *parent;
    struct btree_node *left;
    struct btree_node *right;
} btree_node_t;

typedef struct btree {
    unsigned int count;
    btree_node_t *root;
} btree_t;

btree_node_t* btree_create_node(void *value);
btree_t* btree_initialize(void);

void btree_print_tree(btree_t *self, void (*print)());
void btree_in_order_traversal(btree_node_t *root, void (*print)());
void btree_pre_order_traversal(btree_node_t *root, void (*print)());
void btree_post_order_traversal(btree_node_t *root, void (*print)());
void btree_breadth_first_search(btree_t *self, void (*print)());

int btree_get_height(btree_node_t *root);

btree_node_t* btree_insert(btree_t *self, void *value);

#endif //BTREE_H
