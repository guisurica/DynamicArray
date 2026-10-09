#include <stdio.h>
#include <stdlib.h>

#include "numbers.h"
#include "dynamic_shared.h"

int main(void) {
    int elements[2] = {1, 2};
    Error *error = NULL;
    Numbers *ref = create_array(elements, 4, &error);

    if (error != NULL) {
        printf(error->message);
        printf(error->trouble_shooting);
        if (error->need_panic == 1) {
            exit(1);
        }
    }

    printf("%zu\n", ref->capacity);
    for(int i = 0; i < 2; i++) {
        printf("%d\n", ref->elements[i]);
    }

    return 0;
}