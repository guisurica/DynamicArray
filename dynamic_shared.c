#include <stdio.h>
#include <errno.h>

#include "dynamic_shared.h"

void print_elements(char *format, int *elements, int number_elements, Error **error) {
    Error *temp_error = malloc(sizeof(Error));
    
    if (elements == NULL) {
        temp_error->error_code = errno;
        temp_error->message = "Error: Try Printing null array";
        temp_error->trouble_shooting = "TS: Try create an array before printing. Use: create_array(int *n, int init_value, Error **error)";
        temp_error->need_panic = 1;

        return;
    }

    if (format == NULL) {
        temp_error->error_code = errno;
        temp_error->message = "Error: Try Printing array without a format";
        temp_error->trouble_shooting = "TS: Try pass a format to the function";
        temp_error->need_panic = 1;

        return;
    }

    if (number_elements <= 0) {
        return;
    }

    for(int i = 0; i < number_elements; i++) {
        if (i >= 0) {
            printf("[");
        }

        if (i < number_elements - 1) {
            printf(format, elements[i]);
        }

        if (i >= number_elements - 1) {
            printf("]");
        }
    }

    *error = temp_error;

    free(temp_error);
    temp_error = NULL;
}