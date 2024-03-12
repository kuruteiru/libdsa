#include "linkedList.h"

Node* createNode(void *value) {
    Node *node = (Node*) malloc(sizeof(Node));
    if (node == NULL) return NULL;
    node->value = value;
    node->next = NULL;
    return node;
}

LinkedList* initialize(size_t dataSize) {
    LinkedList *linkedList = (LinkedList*) malloc(sizeof(LinkedList)); 
    if (linkedList == NULL) return NULL;
    linkedList->length = 0;
    linkedList->dataSize = dataSize;
    linkedList->head = NULL;
    linkedList->tail = NULL;
    return linkedList;
}

void destroy(LinkedList *self) {
    Node *currentNode = self->head;
    Node *nextNode;
    while (self->length--) {
        nextNode = currentNode->next;
        free(currentNode->value);
        free(currentNode);
        currentNode = nextNode;
    }
    free(self);
    self = NULL;
}

void print(LinkedList *self) {
    //TODO: return when list is destroyed
    if (self == NULL) return;
    Node *currentNode = self->head;
    for (size_t i = 0; i < self->length; i++) {
        printf("[%d]->", *((int*) currentNode->value));
        currentNode = currentNode->next;
    }
    printf("\n");
}

void push(LinkedList *self, void *value, size_t dataSize) {
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

int main() {
    LinkedList *list = initialize(sizeof(int));

    int nums[] = {1, 2, 3, 4, 6, 6};
    for (size_t i = 0; i < sizeof(nums) / sizeof(int); i++) {
        push(list, (void*) &nums[i], sizeof(int));
    } 

    print(list);
    destroy(list);
    print(list);

    return 0;
}