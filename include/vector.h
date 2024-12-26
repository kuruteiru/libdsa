#ifndef VECTOR_H
#define VECTOR_H

#include <inttypes.h>

#define VECTOR_INITIAL_BUFFER_SIZE 32

typedef struct vector_node {
    void *value;
} vector_node_t;

typedef struct vector {
    uint32_t size;
    void **values;
} vector_t;

#endif //VECTOR_H
