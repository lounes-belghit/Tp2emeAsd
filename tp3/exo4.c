#include <stdio.h>

void convertToBinary(int n) {
    if (n > 1) {
        convertToBinary(n / 2);
    }
    printf("%d", n % 2);
}

int main() {
    int n;
    printf("Enter a non-negative integer: ");
    scanf("%d", &n);
    if (n < 0) {
        printf("Please enter a non-negative integer.\n");
        return 1;
    }
    printf("Binary representation: ");
    convertToBinary(n);
    printf("\n");
    return 0;
}