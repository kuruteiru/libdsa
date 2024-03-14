#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

void push(LinkedList *self, void *value);
void pop(LinkedList *self);

void print(LinkedList *self, void (*print)(void*));

void printInt(void *value);
void printString(void *value);

Node* find(LinkedList *self, void (*compare)(void*), void *value);

bool compareInt(void *value1, void *value2);
bool compareString(void *value1, void *value2);

#endif //LINKED_LIST_H