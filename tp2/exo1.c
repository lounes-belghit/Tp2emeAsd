#include <stdio.h>

int main() {
    int var = 10;       // Declare an integer variable
    int *ptr = &var;    // Declare a pointer to an integer and assign it the address of var

    // Print the value of var
    printf("Value of var: %d\n", var);

    // Print the address of var
    printf("Address of var: %p\n", (void*)&var);

    // Print the value stored in ptr (which is the address of var)
    printf("Value of ptr (Address of var): %p\n", (void*)ptr);

    // Print the value pointed to by ptr (which is the value of var)
    printf("Value pointed to by ptr: %d\n", *ptr);

    return 0;
}