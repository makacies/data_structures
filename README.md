In order to just run test.exe:
```sh
gcc -o vector_test.exe vector.c vector_test.c
```

In order to compile the lib and link it to test file:
```sh
gcc -c -o vector.o vector.c -O3
gcc -c -o vector_test.o vector_test.c -O3
ar rcs libvector.a vector.o
gcc -o vector_test.exe libvector.a vector_test.o
```
