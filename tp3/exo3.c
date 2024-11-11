#include <stdio.h>
#include <math.h>

double f(double x) {
    return x * x * x + x + 1;
}

double dichotomy(double a, double b, double precision) {
    double mid = (a + b) / 2.0;
    if (fabs(f(mid)) < precision) {
        return mid;
    } else if (f(a) * f(mid) < 0) {
        return dichotomy(a, mid, precision);
    } else {
        return dichotomy(mid, b, precision);
    }
}

int main() {
    double a = -3.0;
    double b = 3.0;
    double precision;

    printf("Enter the precision: ");
    scanf("%lf", &precision);

    double root = dichotomy(a, b, precision);
    printf("The root is approximately: %lf\n", root);

    return 0;
}