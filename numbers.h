#ifndef NUMBERS_H
#define NUMBERS_H

#include <stdio.h>

#include "dynamic_shared.h"

typedef struct {
    size_t capacity;
    int *elements;
} Numbers;

Numbers* create_array(int *n, int init_value, Error **error);

void push(Numbers *pref, int n, Error *error);

void pop(Numbers *pref, Error *error);

size_t *get_element(Numbers *pref, int index, Error *error);


#endif