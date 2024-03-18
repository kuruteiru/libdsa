#include "linkedList.h"

Node* createNode(void *value) {
    Node *node = (Node*) malloc(sizeof(Node));
    if (node == NULL) return NULL;
    node->value = value;
    node->next = NULL;
    return node;
}

LinkedList* initialize() {
    LinkedList *linkedList = (LinkedList*) malloc(sizeof(LinkedList)); 
    if (linkedList == NULL) return NULL;
    linkedList->length = 0;
    linkedList->head = NULL;
}

void destroy(LinkedList **self) {
    Node *currentNode = (*self)->head;
    Node *nextNode;
    while (currentNode != NULL) {
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
    while (currentNode != NULL) {
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
    if (self == NULL || self->head == NULL) return false;
    void *currentValue;
    Node *currentNode = self->head;
    while (currentNode != NULL) {
        currentValue = currentNode->value;
        if (compare(currentValue, value))
            return true;
        currentNode = currentNode->next;
    }
    return false;
}

void push(LinkedList *self, void *value) {
    if (self == NULL) return;
    self->length++;
    Node *currentNode = self->head;
    if (currentNode == NULL) {
        self->head = createNode(value); 
        return;
    }
    while (currentNode != NULL) {
        if (currentNode->next == NULL) {
            currentNode->next = createNode(value);
            break;
        }
        currentNode = currentNode->next;
    }
}

void pop(LinkedList *self) {
    if (self == NULL || self->head == NULL) return;
    self->length--;
    Node *currentNode = self->head;
    while (currentNode->next->next != NULL)
        currentNode = currentNode->next;
    free(currentNode->next);
    currentNode->next = NULL;
    return;
}

void print(LinkedList *self, void (*print)(void*)) {
    if (self == NULL) return;
    Node *currentNode = self->head;
    while (currentNode != NULL) {
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
    if (self == NULL || self->head == NULL) return NULL;
    void *currentValue;
    Node *currentNode = self->head;
    while (currentNode != NULL) {
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