#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"

Node* createNode(void *value) {
    Node *node = (Node*)malloc(sizeof(Node));
    if (!node) return NULL;
    
    node->data = value;
    node->parent = NULL;
    node->left = NULL;
    node->right = NULL;

    return node;
}

BinaryTree* initialize() {
    BinaryTree *binaryTree = (BinaryTree*)malloc(sizeof(BinaryTree));
    if (!binaryTree) return NULL;

    binaryTree->root = NULL;
    binaryTree->count = 0;

    return binaryTree;
}

void print(BinaryTree *self, void (*print)()) {
    
}

Node* insert(BinaryTree *self, void *value) {
    if (!self) return NULL;

    if (!self->root) {
        self->root = createNode(value);
        self->count++;
        return self->root;
    }

    int front = 0;
    int rear = 0; 
    Node* queue[self->count];
    queue[rear++] = self->root;

    while (front != rear) {
        Node *current = queue[front++];

        if (!current->left) {
            current->left = createNode(value);
            current->left->parent = current;
            self->count++;
            return current->left;
        }

        if (!current->right) {
            current->right = createNode(value);
            current->right->parent = current;
            self->count++;
            return current->right;
        }

        queue[rear++] = current->left;
        queue[rear++] = current->right;
    }

    return NULL;

}

void inOrderTraversal(Node *root, void (*print)()) {
    if (!root) return;

}

void inOrderTraversal(Node *root, void (*print)()) {
    if (!root) return;
    preOrderTraversal(root->left, print);
    if (root->data) print(root->data);
    preOrderTraversal(root->right, print);
}
