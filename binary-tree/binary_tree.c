#include <stdio.h>
#include "binary_tree.h"
#include "void-pointer/void_pointer.c"

Node* createNode(void *value) {
    Node *node = (Node*)malloc(sizeof(Node));
    if (!node) return NULL;
    node->data = NULL;
    node->parent = NULL;
    node->left = NULL;
    node->right = NULL;
    return node;
}

BinaryTree* initialize() {
    BinaryTree *binaryTree = (BinaryTree*)malloc(sizeof(BinaryTree));
    if (!binaryTree) return NULL;
    binaryTree->root = NULL;
    return binaryTree;
}

void insert(BinaryTree *self, void *value) {
    
}

void preOrderTraversal(Node *root, void (*print)()) {
    if (!root) return;
    preOrderTraversal(root->left, print);
    print(root->left);
    preOrderTraversal(root->right, print);
}