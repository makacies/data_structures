#include <stdlib.h>
#include <stdio.h>

#define INITIAL_CAPACITY 10

typedef struct {
    int* items;
    size_t size;
    size_t capacity;
} Vector;

void vector_init(Vector* vector) {
    vector->items = malloc(INITIAL_CAPACITY * sizeof(int));
    vector->size = 0;
    vector->capacity = INITIAL_CAPACITY;
}

void vector_free(Vector* vector) {
    free(vector->items);
}

void vector_resize(Vector* vector, size_t capacity) {
    vector->items = realloc(vector->items, capacity * sizeof(int));
    printf("Vector resize: %d to %d\n", vector->capacity, capacity);
    vector->capacity = capacity;
}

void vector_push(Vector* vector, int item) {
    if (vector->size >= vector->capacity) {
        vector_resize(vector, vector->capacity * 2);
    }
    
    vector->items[vector->size] = item;
    vector->size++;
}

int main() {
    Vector my_first_vector;
    vector_init(&my_first_vector);

    for (size_t i = 0; i < 30; i++) {
        vector_push(&my_first_vector, i);
        printf("%d\n", my_first_vector.items[i]);
        printf("%d\n", my_first_vector.capacity);
    }

    vector_free(&my_first_vector);
}
