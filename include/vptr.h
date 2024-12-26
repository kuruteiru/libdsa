#ifndef VOID_POINTER_H
#define VOID_POINTER_H

#include <stdbool.h>

void vptr_print_int(void *value);
void vptr_print_string(void *value);
bool vptr_compare_int(void *value1, void *value2);
bool vptr_compare_string(void *value1, void *value2);

#endif //VOID_POINTER_H
