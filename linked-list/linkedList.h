#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    void *value;
    struct Node *next;
} Node;

Node* createNode(void *value);

typedef struct LinkedList {
    size_t length;
    size_t dataSize;
    Node *head;
    Node *tail;
} LinkedList;

LinkedList* initialize(size_t dataSize);

void destroy(LinkedList *self);
void print(LinkedList *self);

void find(LinkedList *self, void *value, size_t dataSize);
void push(LinkedList *self, void *value, size_t dataSize);
void pop(LinkedList *self, void *value, size_t dataSize);

#endif //LINKED_LIST_H