#include <stdio.h>

// Function to compute the Ackermann function
int ackermann(int n, int m) {
    if (n == 0) {
        return m + 1;
    } else if (m == 0) {
        return ackermann(n - 1, 1);
    } else {
        return ackermann(n - 1, ackermann(n, m - 1));
    }
}

int main() {
    // Calculating and printing the Ackermann function for given values
    printf("A(0, 0) = %d\n", ackermann(0, 0));
    printf("A(0, 2) = %d\n", ackermann(0, 2));
    printf("A(0, 4) = %d\n", ackermann(0, 4));
    printf("A(1, 0) = %d\n", ackermann(1, 0));
    printf("A(4, 0) = %d\n", ackermann(4, 0));
    printf("A(5, 0) = %d\n", ackermann(5, 0));

    return 0;
}