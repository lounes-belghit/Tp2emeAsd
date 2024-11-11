#include <stdio.h>

// Function prototypes
void swap(int *a, int *b);

int main() {
    int x = 10;
    int y = 20;

    printf("Before swap: x = %d, y = %d\n", x, y);

    // Call the swap function
    swap(&x, &y);

    printf("After swap: x = %d, y = %d\n", x, y);

    return 0;
}

// Function to swap the values of two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}