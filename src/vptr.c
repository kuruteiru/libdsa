#include "vptr.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void vptr_print_int(void *value) {
    if (!value) return;
    printf("%d", *((int*) value));
}

void vptr_print_string(void *value) {
    if (!value) return;
    printf("%s", *((char**) value));
}

bool vptr_compare_int(void *value1, void *value2) {
    if (!value1 || !value2) return false;
    return *((int*) value1) == *((int*) value2);
}

bool vptr_compare_string(void *value1, void *value2) {
    if (!value1 || !value2) return false;
    return strcmp(((char*) value1), ((char*) value2)) == 0;
}
