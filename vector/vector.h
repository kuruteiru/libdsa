#ifndef VECTOR_H
#define VECTOR_H

#include <inttypes.h>

#define INITIAL_VECTOR_BUFFER_SIZE 32

typedef struct { 
    void *value;
} vector_node_t;

typedef struct {
    uint32_t size;
    void **values;
} vector_t;

#endif //VECTOR_H
