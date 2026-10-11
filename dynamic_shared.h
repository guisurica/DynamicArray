#ifndef DYNAMIC_SHARED_H
#define DYNAMIC_SHARED_H

#define STASH_VALUE 999999

#include <errno.h>

typedef struct {
    char *message;
    int error_code;
    int need_panic;
    char *trouble_shooting;
} Error;

void print_elements(char* format, int *elements, int number_elements, Error **error);

#endif