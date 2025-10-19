#include <stdio.h>

int deliteli(int n, int i) {
    if (i == 0) return 0;
    if (n % i == 0)
        return i + deliteli(n, i - 1);
    else
        return deliteli(n, i - 1);
}


int abundant(int n) {
    int sum = deliteli(n, n / 2); 
    return sum > n;
}


void abundant_chain(int n, int m) {
    if (n > m) return; 
    if (abundant(n))
        printf("%d ", n);
    abundant_chain(n + 1, m); 

int main() {
    int N, M;

    printf("Введите два натуральных числа (N и M): ");
    scanf("%d %d", &N, &M);

    if (N <= 0 || M <= 0) {
        printf("Ошибка: числа должны быть натуральными.\n");
        return 1;
    }

    if (N > M) {
        int temp = N;
        N = M;
        M = temp;
    }

    printf("Избыточные числа в диапазоне [%d, %d]: ", N, M);
    abundant_chain(N, M);
    printf("\n");

    return 0;
}

