#include <stdio.h>

// Function to print numbers from n to 1 in descending order
void printDescending(int n) {
    if (n > 0) {
        printf("%d ", n);
        printDescending(n - 1);
    }
}

// Function to print numbers from 1 to n in ascending order
void printAscending(int n) {
    if (n > 0) {
        printAscending(n - 1);
        printf("%d ", n);
    }
}

int main() {
    int n;
    printf("Enter a natural number: ");
    scanf("%d", &n);

    printf("Numbers in descending order: ");
    printDescending(n);
    printf("\n");

    printf("Numbers in ascending order: ");
    printAscending(n);
    printf("\n");

    return 0;
}