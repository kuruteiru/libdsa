#include "void_pointer.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void printInt(void *value) {
    printf("%d", *((int*) value));
}

void  printString(void *value) {
    printf("%s", *((char**) value));
}

bool compareInt(void *value1, void *value2) {
    return *((int*) value1) == *((int*) value2);
}

bool compareString(void *value1, void *value2) {
    return strcmp(((char*) value1), ((char*) value2)) == 0;
}