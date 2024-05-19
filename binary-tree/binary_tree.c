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
    Node *current;
    Node *queue[self->count];
    queue[rear++] = self->root;

    while (front != rear) {
        current = queue[front++];

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

void printTree(BinaryTree *self, void (*print)()) {
    if (!self || !self->root) return;

    int levels = 1;

    int front = 0;
    int rear = 0; 
    Node *current;
    Node *queue[self->count];
    queue[rear++] = self->root;

    while (front != rear) {
        current = queue[front++];
        if (current->left) queue[rear++] = current->left;
        if (current->right) queue[rear++] = current->right;
        if (current->left || current->right) levels++;
    }

    printf("\nlevels: %d", levels);

    int height = getHeight(self->root);
    printf("\nheight: %d", height);

    front = 0;
    rear = 0; 

    // while (front != rear) {
    //     current = queue[front++];
    //     print(current->data);
    //     if (current->left) queue[rear++] = current->left;
    //     if (current->right) queue[rear++] = current->right;
    // }
}

void inOrderTraversal(Node *root, void (*print)()) {
    if (!root) return;
    inOrderTraversal(root->left, print);
    if (root->data) print(root->data);
    inOrderTraversal(root->right, print);
}

void preOrderTraversal(Node *root, void (*print)()) {
    if (!root) return;
    if (root->data) print(root->data);
    preOrderTraversal(root->left, print);
    preOrderTraversal(root->right, print);
}

void postOrderTraversal(Node *root, void (*print)()) {
    if (!root) return;
    postOrderTraversal(root->left, print);
    postOrderTraversal(root->right, print);
    if (root->data) print(root->data);
}

void breadthFirstSearch(BinaryTree *self, void (*print)()) {
    if (!self || !self->root) return;

    int front = 0;
    int rear = 0; 
    Node *current;
    Node *queue[self->count];
    queue[rear++] = self->root;

    while (front != rear) {
        current = queue[front++];
        print(current->data);
        if (current->left) queue[rear++] = current->left;
        if (current->right) queue[rear++] = current->right;
    }
}

int getHeight(Node *root) {
    if (!root) return 0;

    int left = getHeight(root->left);
    int right = getHeight(root->right);

    if (left > right) return ++left;

    return ++right;
}