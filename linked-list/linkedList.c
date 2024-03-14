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

void push(LinkedList *self, void *value) {
    if (self == NULL) return;
    self->length++;
    Node *currentNode = self->head;
    if (currentNode == NULL) {
        self->head = createNode(value); 
        return;
    }
    for (size_t i = 0; i < self->length; i++) {
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
    while (currentNode->next != NULL)
        currentNode = currentNode->next;
    free(currentNode->next);
    currentNode->next = NULL;
    return;
}

void print(LinkedList *self, void (*print)(void*)) {
    if (self == NULL) return;
    Node *currentNode = self->head;
    for (size_t i = 0; i < self->length; i++) {
        printf("[%d]->", *((int*) currentNode->value));
        currentNode = currentNode->next;
    }
    printf("NULL\n");
}

Node* find(LinkedList *self, void (*compare)(void*), void *value) {
    if (self == NULL || self->head == NULL) return NULL;
    Node *currentNode = self->head;
    void *currentValue = currentNode->value;
    while (true) {

    }
}

int main() {
    LinkedList *list = initialize(sizeof(int));

    int nums[] = {};
    for (size_t i = 0; i < sizeof(nums) / sizeof(int); i++) {
        push(list, (void*) &nums[i]);
    } 

    print(list);
    pop(list);
    print(list);
    destroy(&list);
    print(list);

    return 0;
}