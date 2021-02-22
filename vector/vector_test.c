#include "vector.h"

#include <stdio.h>

int main() {
  Vector my_first_vector;
  vector_init(&my_first_vector);

  printf("Vector is empty: %d\n", vector_is_empty(&my_first_vector));

  for (size_t i = 0; i < 30; i++) {
    vector_push(&my_first_vector, i);
    printf("%d\n", my_first_vector.items[i]);
    printf("%d\n", my_first_vector.capacity);
  }

  printf("Vector is empty: %d\n", vector_is_empty(&my_first_vector));

  vector_free(&my_first_vector);
}
