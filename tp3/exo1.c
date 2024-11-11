#include <stdio.h>

int convertirEnBase10(int n, int b) {
    if (n == 0) {
        return 0;
    } else {
        return (n % 10) + b * convertirEnBase10(n / 10, b);
    }
}

int main() {
    int n = 100; // Example number in base 2
    int b = 16;    // Base
    printf("The number %d in base %d is %d in base 10\n", n, b, convertirEnBase10(n, b));
    return 0;
}