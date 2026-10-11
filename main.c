#include <stdio.h>
#include <stdlib.h>

#include "numbers.h"
#include "dynamic_shared.h"

int main(void) {
    int elements[2] = {1, 2};
    Error *error = NULL;
    Numbers *ref = create_array(elements, 2, &error);

    if (error != NULL) {
        printf("%s\n", error->message);
        printf("%s\n", error->trouble_shooting);
        if (error->need_panic == 1) {
            exit(1);
        }
    }

    return 0;
}