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
// void deleteNode(Node *node);
// void freeNode(Node *node);

typedef struct BinaryTree {
    unsigned int count;
    Node *root;
} BinaryTree;

BinaryTree* initialize();

// void destroy(BinaryTree *self);
// void clear(BinaryTree *self);

// bool isEmpty(BinaryTree *self);
// bool includes(BinaryTree *self, void *value, bool (*compare)());

void printTree(BinaryTree *self, void (*print)());

void inOrderTraversal(Node *root, void (*print)());
void preOrderTraversal(Node *root, void (*print)());
void postOrderTraversal(Node *root, void (*print)());
void breadthFirstSearch(BinaryTree *self, void (*print)());

// void deleteDeepest(BinaryTree *self);
// void deleteNode(BinaryTree *self, void *value, bool (*compare)());

int getHeight(Node *root);

Node* insert(BinaryTree *self, void *value);
// Node* find(BinaryTree *self, bool (*compare)(), void *value);

#endif //BINARY_TREE_H