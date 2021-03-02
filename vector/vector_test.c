#include "vector.h"

#include <stdio.h>

int main() {
  Vector my_first_vector;
  vector_init(&my_first_vector, sizeof(short));

  printf("Vector is empty: %d\n", vector_is_empty(&my_first_vector));

  for (size_t i = 0; i < 5; i++) {
    vector_push(&my_first_vector, &i);
    printf("Added item: %d\n", ((short*)my_first_vector.items)[i]);
  }

  printf("Vector capacity: %d\n", my_first_vector.capacity);
  vector_shrink_to_fit(&my_first_vector);
  printf("Vector capacity: %d\n", my_first_vector.capacity);

  size_t new_item = 10;
  vector_push(&my_first_vector, &new_item);
  printf("Vector capacity: %d\n", my_first_vector.capacity);

  vector_free(&my_first_vector);
}
