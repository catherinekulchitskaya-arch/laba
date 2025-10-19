#include <stdio.h>


int sumDivisors(int n, int i) {
    if (i == 0) return 0;
    if (n % i == 0)
        return i + sumDivisors(n, i - 1);
    else
        return sumDivisors(n, i - 1);
}


int isAbundant(int n) {
    int sum = sumDivisors(n, n / 2);
    return sum > n;
}


void printAbundantInRange(int n, int m) {
    if (n > m) return; 
    if (isAbundant(n))
        printf("%d ", n);
    printAbundantInRange(n + 1, m);
}

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
    printAbundantInRange(N, M);
    printf("\n");

    return 0;
}

