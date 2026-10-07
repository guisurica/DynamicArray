#include <stdio.h>
#include <stdlib.h>

// elementos atuais
// tamanho atual

typedef struct {
    uint current_total_elements;
    size_t current_length;
    int elements[];
} Dynamic;

int *create_array(*Dynamic ref) {

}

int main() {
    printf("%ld\n", sizeof(int));
    int numbers[5] = {1, 2, 3, 4, 5};
    for(int i = 0; i < 5; i++) {
        printf("%p\n", &numbers[i]);
    }

    return 0;
}