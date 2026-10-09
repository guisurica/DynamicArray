#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "numbers.h"
#include "dynamic_shared.h"

#define DEFAULT_VALUE 4

Numbers *create_array(int *n, int init_value, Error **error) {
    Error *temp_error = malloc(sizeof(Error));
    Numbers *ref = malloc(sizeof(Numbers));
    
    int number_size = *n;
    int input_array_length = sizeof(n) / sizeof(int);

    if (init_value != input_array_length) {
        temp_error->error_code = errno;
        temp_error->message = "Error: Init value need to be equal to the length of the array.\n";
        temp_error->need_panic = 1;
        temp_error->trouble_shooting = "TS: try set init value equal the array's length\n";

        *error = temp_error;

        temp_error = NULL;
        free(temp_error);

        return NULL;
    }

    if (n == NULL) {
        ref->elements = malloc(DEFAULT_VALUE * DEFAULT_VALUE);
        ref->capacity = DEFAULT_VALUE * DEFAULT_VALUE;

        ref->elements = NULL;
    } else {
        ref->elements = malloc(sizeof(number_size) * sizeof(number_size));
        ref->capacity = sizeof(number_size) * sizeof(number_size);

        for(int i = 0; i < init_value; i++) {
            ref->elements[i] = n[i];
        }
    }

    temp_error = NULL;
    free(temp_error);

    return ref;
}

void push(Numbers *pref, int n, Error *error) {

}

void pop(Numbers *pref, Error *error) {

}

size_t *get_element(Numbers *pref, int index, Error *error) {

}

