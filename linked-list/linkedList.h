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
    Node *head;
    Node *tail;
} LinkedList;

LinkedList* initialize();

void destroy(LinkedList **self);
void print(LinkedList *self);

void find(LinkedList *self, void *value);
void push(LinkedList *self, void *value);
void pop(LinkedList *self);

#endif //LINKED_LIST_H