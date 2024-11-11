#include <stdio.h>

int main() {
    // Declare an array of integers
    int arr[5] = {1, 2, 3, 4, 5};
    
    // Declare a pointer to an integer
    int *ptr;
    
    // Point the pointer to the first element of the array
    ptr = arr;
    
    // Access and print the array elements using the pointer
    for (int i = 0; i < 5; i++) {
        printf("Element %d: %d\n", i, *(ptr + i));
    }
    
    return 0;
}