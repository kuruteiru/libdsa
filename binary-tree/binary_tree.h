#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdbool.h>

typedef struct Node {
    void *data;
    struct Node *parent;
    struct Node *left;
    struct Node *right;
} Node;

Node* createNode(void *value);

typedef struct BinaryTree {
    Node *root;
} BinaryTree;

BinaryTree* initialize();

void destroy(BinaryTree *self);
void clear(BinaryTree *self);

bool isEmpty(BinaryTree *self);
bool includes(BinaryTree *self, void *value, bool (*compare)());

void insert(BinaryTree *self, void *value);

void deleteDeepest(BinaryTree *self);
void deleteNode(BinaryTree *self, void *value, bool (*compare)());

void inOrderTraversal(Node *root, void (*print)());
void preOrderTraversal(Node *root, void (*print)());
void postOrderTraversal(Node *root, void (*print)());
void levelOrderTraversal(Node *root, void (*print)());

void print(BinaryTree *self, void (*print)());

Node* find(BinaryTree *self, bool (*compare)(), void *value);

#endif //BINARY_TREE_H