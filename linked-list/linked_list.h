#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Node {
    void *value;
    struct Node *next;
} Node;

Node* createNode(void *value);

typedef struct LinkedList {
    size_t length;
    Node *head;
} LinkedList;

LinkedList* initialize();

void destroy(LinkedList **self);
void clear(LinkedList *self);

bool isEmpty(LinkedList *self);
bool includes(LinkedList *self, bool (*compare)(), void *value);

void push(LinkedList *self, void *value);
void pop(LinkedList *self);

void print(LinkedList *self, void (*print)());

Node* find(LinkedList *self, bool (*compare)(), void *value);

#endif //LINKED_LIST_H