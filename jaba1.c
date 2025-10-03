#include <stdio.h>
#include <math.h>

int main() {
    double x, y;
    double hx = 0.4, hy = 0.3, yn = 1, yk = 2, xn = 0, xk = 1;
    double U;
    printf("  x  |  y  |  U\n");
    for (x = xn; x <= xk; x += hx) {
        for (y = yn; y <= yk; y += hy) {
            if (x * y <= -1) {
                double verx1 = exp(2) * sqrt(log(pow(x, 4) + 2));
                double verx2 = x * acos(x / y);
                U = fmax(verx1, verx2);
                printf(" %.2f | %.2f | %.12f\n", x, y, U);
            }
            else if (-1 < x * y && x * y < 2) {
                 U = 0;
                 printf(" %.2f | %.2f | %.12f\n", x, y, U);
                }
              if (x * y >= 2) {
                   double niz1 = sqrt(fabs(pow(x, 2) - y));
                   double niz2 = x * cbrt(y - 1);
                   U = fmin(niz1, niz2);
                   printf(" %.2f | %.2f | %.12f\n", x, y, U);
            }
         
        }
    }

    return 0;
}
