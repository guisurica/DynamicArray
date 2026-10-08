#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_TOTAL_ELEMENTS 8

typedef struct {
    uint current_total_elements;
    size_t current_length;
    int elements[ARRAY_TOTAL_ELEMENTS];
} Dynamic;

Dynamic *create_array(int elements[ARRAY_TOTAL_ELEMENTS]) {

    Dynamic *ref = malloc(sizeof(Dynamic)); 

    ref->current_length = sizeof(int) * ARRAY_TOTAL_ELEMENTS;
    ref->current_total_elements = ARRAY_TOTAL_ELEMENTS;

    for(int i = 0; i < ARRAY_TOTAL_ELEMENTS; i++) {
        ref->elements[i] = elements[i];
    }
}

size_t get_current_array_length(Dynamic *ref) {
    return ref->current_length;
}

void show_array_size(Dynamic *ref) {
    if (ref == NULL) {
        perror("Ref is null");
        return;
    }

    if (ref->current_length == 0) {
        return;
    }

    if (ref->current_total_elements == 0) {
        return;
    }

    printf("%ld\n", ref->current_length);
}

void show_array_total_elements(Dynamic *ref) {
    if (ref == NULL) {
        perror("Ref is null");
        return;
    }

    if (ref->current_length == 0) {
        return;
    }

    if (ref->current_total_elements == 0) {
        return;
    }

    printf("%d\n", ref->current_total_elements);

}

void print_array(Dynamic *ref) {
    if (ref->current_total_elements <= 0) {
        printf("Empty list\n");
        return;
    }

    for(int i = 0; i < ref->current_total_elements; i++) {
        if (i <= 0) {
            printf("[");
        }

        if (i == ref->current_total_elements - 1) {
            printf("%d", ref->elements[i]);
            printf("]\n");
        } else {
            printf("%d, ", ref->elements[i]);
        }
    }
}

void print_array_element_addrs(Dynamic *ref, int direction) {
    if (ref->current_total_elements <= 0) {
        printf("Empty list\n");
        return;
    }

    for(int i = 0; i < ref->current_total_elements; i++) {
        if (i == ref->current_total_elements - 1) {
            printf("%p\n", &ref->elements[i]);
        } else {
            if (direction > 0) {
                printf("%p\n", &ref->elements[i]);
            } else {
                printf("%p|", &ref->elements[i]);
            }
        }
    }
}

int *lookup_first(Dynamic *ref) {
    if (ref->current_total_elements <= 0) return NULL;
    
    return &ref->elements[0];
}

int *lookup_last(Dynamic *ref) {
    if (ref->current_total_elements <= 0) return NULL;

    return &ref->elements[ref->current_total_elements - 1];
}

int *lookup(Dynamic *ref, int index) {
    if (ref->current_total_elements <= 0) return NULL;

    return &ref->elements[index];
}

size_t push(Dynamic **ref, int new_element) {
    Dynamic *temp = NULL;

    if (*ref == NULL) {
        perror("Ref is null");
        exit(1);
    }

    temp = realloc(*ref, get_current_array_length(*ref) * sizeof(new_element));
    if (temp == NULL) {
        perror("Realloc failed");
        exit(1);
    }

    temp->current_total_elements++;
    temp->elements[temp->current_total_elements - 1] = new_element;
    temp->current_length = sizeof(int) * temp->current_total_elements;

    *ref = temp;

    temp = NULL;
    free(temp);

    return (*ref)->current_length;
}

int main() {
    int els[ARRAY_TOTAL_ELEMENTS] = {1, 2, 3, 4, 5, 6, 7, 8};

    Dynamic *ref = create_array(els);
    
    size_t new_length = push(&ref, 9);

    print_array(ref);
    show_array_size(ref);

    return 0;
}