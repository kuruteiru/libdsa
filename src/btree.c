#include <stdio.h>
#include <stdlib.h>
#include "btree.h"

btree_node_t* btree_create_node(void *value) {
    btree_node_t *node = (btree_node_t*)malloc(sizeof(btree_node_t));
    if (!node) return NULL;
    
    node->data = value;
    node->parent = NULL;
    node->left = NULL;
    node->right = NULL;

    return node;
}

btree_t* btree_initialize(void) {
    btree_t *btree = (btree_t*)malloc(sizeof(btree_t));
    if (!btree) return NULL;

    btree->root = NULL;
    btree->count = 0;

    return btree;
}

void btree_print(btree_t *self, void (*print)(void*)) {
    
}

btree_node_t* btree_insert(btree_t *self, void *value) {
    if (!self) return NULL;

    if (!self->root) {
        self->root = btree_create_node(value);
        self->count++;
        return self->root;
    }

    int front = 0;
    int rear = 0; 
    btree_node_t *current;
    btree_node_t *queue[self->count];
    queue[rear++] = self->root;

    while (front != rear) {
        current = queue[front++];

        if (!current->left) {
            current->left = btree_create_node(value);
            current->left->parent = current;
            self->count++;
            return current->left;
        }

        if (!current->right) {
            current->right = btree_create_node(value);
            current->right->parent = current;
            self->count++;
            return current->right;
        }

        queue[rear++] = current->left;
        queue[rear++] = current->right;
    }

    return NULL;
}

void btree_print_tree(btree_t *self, void (*print)(void*)) {
    if (!self || !self->root) return;

    int levels = 1;

    int front = 0;
    int rear = 0; 
    btree_node_t *current;
    btree_node_t *queue[self->count];
    queue[rear++] = self->root;

    while (front != rear) {
        current = queue[front++];
        if (current->left) queue[rear++] = current->left;
        if (current->right) queue[rear++] = current->right;
        if (current->left || current->right) levels++;
    }

    printf("\nlevels: %d", levels);

    int height = btree_get_height(self->root);
    printf("\nheight: %d", height);
}

void btree_in_order_traversal(btree_node_t *root, void (*print)(void*)) {
    if (!root) return;
    btree_in_order_traversal(root->left, print);
    if (root->data) print(root->data);
    btree_in_order_traversal(root->right, print);
}

void btree_pre_order_traversal(btree_node_t *root, void (*print)(void*)) {
    if (!root) return;
    if (root->data) print(root->data);
    btree_pre_order_traversal(root->left, print);
    btree_pre_order_traversal(root->right, print);
}

void btree_post_order_traversal(btree_node_t *root, void (*print)(void*)) {
    if (!root) return;
    btree_post_order_traversal(root->left, print);
    btree_post_order_traversal(root->right, print);
    if (root->data) print(root->data);
}

void btree_breadth_first_search(btree_t *self, void (*print)(void*)) {
    if (!self || !self->root) return;

    int front = 0;
    int rear = 0; 
    btree_node_t *current;
    btree_node_t *queue[self->count];
    queue[rear++] = self->root;

    while (front != rear) {
        current = queue[front++];
        print(current->data);
        if (current->left) queue[rear++] = current->left;
        if (current->right) queue[rear++] = current->right;
    }
}

int btree_get_height(btree_node_t *root) {
    if (!root) return 0;

    int left = btree_get_height(root->left);
    int right = btree_get_height(root->right);

    if (left > right) return ++left;

    return ++right;
}
