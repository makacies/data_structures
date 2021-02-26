#include "vector.h"

#include <stdio.h>

int main() {
  Vector my_first_vector;
  vector_init(&my_first_vector, sizeof(short));

  printf("Vector is empty: %d\n", vector_is_empty(&my_first_vector));

  for (size_t i = 0; i < 30; i++) {
    vector_push(&my_first_vector, &i);
    printf("Added item: %d\n", ((short*)my_first_vector.items)[i]);
    printf("Capacity: %d\n", my_first_vector.capacity);
  }

  printf("Vector is empty: %d\n", vector_is_empty(&my_first_vector));

  short frst_ins = 100;
  short scnd_ins = 500;
  printf("Insert at index 1: %d\n", vector_insert(&my_first_vector, &frst_ins, 1));
  printf("Insert at index 5: %d\n", vector_insert(&my_first_vector, &scnd_ins, 5));

  for (size_t i = 0; i < my_first_vector.size; i++) {
    printf("Item: %d\n", ((short*)my_first_vector.items)[i]);
  }

  vector_free(&my_first_vector);
}
