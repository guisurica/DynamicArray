#ifndef DYNAMIC_SHARED_H
#define DYNAMIC_SHARED_H

#include <errno.h>

typedef struct {
    char *message;
    int error_code;
    int need_panic;
    char *trouble_shooting;
} Error;

#endif