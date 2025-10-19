#include <stdio.h>

int deliteli( int n, int i) {
        if ( i == 0  ) {
                return 0;
        }
        if ( n % i == 0) {
                return i + deliteli( n, i-1);
        }
        else {
                return deliteli(n, i-1);
        }
 }

int izbit(int n) {
        int sum = deliteli(n, n /2);
        return sum > n;
}

void  izbit_chain(int n, int m) {
        if (n > m) {
                return;
        }
        if (izbit(n)) {
                printf("%d ", n);
        izbit_chain(n + 1, m ); 
        }
}
int main () {
        int N, M;

        printf("Vvedite N & M: ");
        if (scanf("%d %d ", &N, &M) != 2 || N <=0 || M<=0) {
                printf ("Oshibka\n");
                return 1;

        }

        if (N > M) {
                int temp = N;
                N = M;
                M = temp;
        }


        izbit_chain (N, M);
        printf(" \n", N, M);
        return 0;
}

