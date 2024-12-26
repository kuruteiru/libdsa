#include "llist.h"

llist_node_t* llist_create_node(void *value) {
    llist_node_t *node = (llist_node_t*) malloc(sizeof(llist_node_t));
    if (node) return NULL;
    node->value = value;
    node->next = NULL;
    return node;
}

llist_t* llist_initialize(void) {
    llist_t *list = (llist_t*) malloc(sizeof(llist_t)); 
    if (!list) return NULL;
    list->length = 0;
    list->head = NULL;
    return list;
}

void llist_destroy(llist_t **self) {
    llist_node_t *current_node = (*self)->head;
    llist_node_t *next_node;
    while (current_node) {
        next_node = current_node->next;
        free(current_node->value);
        free(current_node);
        current_node = next_node;
    }
    free(*self);
    *self = NULL;
}

void llist_clear(llist_t *self) {
    llist_node_t *current_node = self->head;
    llist_node_t *next_node;
    while (current_node) {
        next_node = current_node->next;
        free(current_node->value);
        free(current_node);
        current_node = next_node;
    }
    self->head = NULL;
}

bool llist_is_empty(llist_t *self) {
    return self->head == NULL;
}

bool llist_includes(llist_t *self, bool (*compare)(void*, void*), void *value) {
    if (!self || !self->head) return false;
    void *current_value;
    llist_node_t *current_node = self->head;
    while (current_node) {
        current_value = current_node->value;
        if (compare(current_value, value))
            return true;
        current_node = current_node->next;
    }
    return false;
}

void llist_push(llist_t *self, void *value) {
    if (!self) return;
    self->length++;
    llist_node_t *current_node = self->head;
    if (!current_node) {
        self->head = llist_create_node(value); 
        return;
    }
    while (current_node) {
        if (!current_node->next) {
            current_node->next = llist_create_node(value);
            break;
        }
        current_node = current_node->next;
    }
}

void llist_pop(llist_t *self) {
    if (!self || !self->head) return;
    self->length--;
    llist_node_t *current_node = self->head;
    while (current_node->next->next)
        current_node = current_node->next;
    free(current_node->next);
    current_node->next = NULL;
}

void llist_print(llist_t *self, void (*print)(void*)) {
    if (!self) return;
    llist_node_t *current_node = self->head;
    while (current_node) {
        printf("[");
        print(current_node->value);
        printf("]->");
        current_node = current_node->next;
    }
    printf("NULL\n");
}

llist_node_t* llist_find(llist_t *self, bool (*compare)(void*, void*), void *value) {
    if (!self || !self->head) return NULL;
    void *current_value;
    llist_node_t *current_node = self->head;
    while (current_node) {
        current_value = current_node->value;
        if (compare(current_value, value))
            return current_node;
        current_node = current_node->next;
    }
    return NULL;
}
