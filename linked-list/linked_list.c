#include "linked_list.h"

Node* createNode(void *value) {
    Node *node = (Node*) malloc(sizeof(Node));
    if (node) return NULL;
    node->value = value;
    node->next = NULL;
    return node;
}

LinkedList* initialize() {
    LinkedList *linkedList = (LinkedList*) malloc(sizeof(LinkedList)); 
    if (!linkedList) return NULL;
    linkedList->length = 0;
    linkedList->head = NULL;
}

void destroy(LinkedList **self) {
    Node *currentNode = (*self)->head;
    Node *nextNode;
    while (currentNode) {
        nextNode = currentNode->next;
        free(currentNode->value);
        free(currentNode);
        currentNode = nextNode;
    }
    free(*self);
    *self = NULL;
}

void clear(LinkedList *self) {
    Node *currentNode = self->head;
    Node *nextNode;
    while (currentNode) {
        nextNode = currentNode->next;
        free(currentNode->value);
        free(currentNode);
        currentNode = nextNode;
    }
    self->head = NULL;
}

bool isEmpty(LinkedList *self) {
    return self->head == NULL;
}

bool includes(LinkedList *self, bool (*compare)(), void *value) {
    if (!self || !self->head) return false;
    void *currentValue;
    Node *currentNode = self->head;
    while (currentNode) {
        currentValue = currentNode->value;
        if (compare(currentValue, value))
            return true;
        currentNode = currentNode->next;
    }
    return false;
}

void push(LinkedList *self, void *value) {
    if (!self) return;
    self->length++;
    Node *currentNode = self->head;
    if (!currentNode) {
        self->head = createNode(value); 
        return;
    }
    while (currentNode) {
        if (!currentNode->next) {
            currentNode->next = createNode(value);
            break;
        }
        currentNode = currentNode->next;
    }
}

void pop(LinkedList *self) {
    if (!self || !self->head) return;
    self->length--;
    Node *currentNode = self->head;
    while (currentNode->next->next)
        currentNode = currentNode->next;
    free(currentNode->next);
    currentNode->next = NULL;
    return;
}

void print(LinkedList *self, void (*print)(void*)) {
    if (!self) return;
    Node *currentNode = self->head;
    while (currentNode) {
        printf("[");
        print(currentNode->value);
        printf("]->");
        currentNode = currentNode->next;
    }
    printf("NULL\n");
}

void printInt(void *value) {
    printf("%d", *((int*) value));
}

void  printString(void *value) {
    printf("%s", *((char**) value));
}

Node* find(LinkedList *self, bool (*compare)(), void *value) {
    if (!self || !self->head) return NULL;
    void *currentValue;
    Node *currentNode = self->head;
    while (currentNode) {
        currentValue = currentNode->value;
        if (compare(currentValue, value))
            return currentNode;
        currentNode = currentNode->next;
    }
    return NULL;
}

bool compareInt(void *value1, void *value2) {
    return *((int*) value1) == *((int*) value2);
}

bool compareString(void *value1, void *value2) {
    return strcmp(((char*) value1), ((char*) value2)) == 0;
}