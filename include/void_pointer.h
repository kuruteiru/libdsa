#ifndef VOID_POINTER_H
#define VOID_POINTER_H

#include <stdbool.h>

void printInt(void *value);
void printString(void *value);

bool compareInt(void *value1, void *value2);
bool compareString(void *value1, void *value2);

#endif //VOID_POINTER_H