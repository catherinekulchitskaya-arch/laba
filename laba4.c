#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void copy_array(int *src, int *dest, int n) {
    for (int i = 0; i < n; i++)
        dest[i] = src[i];
}

void bubble_sort(int *a, int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (a[j] > a[j+1]) {
                int t = a[j]; a[j] = a[j+1]; a[j+1] = t;
            }
}

void insertion_sort(int *a, int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i], j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}

void merge(int *a, int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int *L = malloc(n1 * sizeof(int));
    int *R = malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++) L[i] = a[l+i];
    for (int i = 0; i < n2; i++) R[i] = a[m+1+i];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
        a[k++] = (L[i] < R[j] ? L[i++] : R[j++]);

    while (i < n1) a[k++] = L[i++];
    while (j < n2) a[k++] = R[j++];

    free(L);
    free(R);
}

void merge_sort(int *a, int l, int r) {
    if (l >= r) return;
    int m = (l + r) / 2;
    merge_sort(a, l, m);
    merge_sort(a, m+1, r);
    merge(a, l, m, r);
}

double measure_time(void (*sort)(int*,int), int *arr, int n) {
    int *tmp = malloc(n * sizeof(int));
    copy_array(arr, tmp, n);

    clock_t start = clock();
    sort(tmp, n);
    clock_t end   = clock();

    free(tmp);
    return (double)(end - start) / CLOCKS_PER_SEC;
}

double measure_merge(int *arr, int n) {
    int *tmp = malloc(n * sizeof(int));
    copy_array(arr, tmp, n);

    clock_t start = clock();
    merge_sort(tmp, 0, n-1);
    clock_t end = clock();

    free(tmp);
    return (double)(end - start) / CLOCKS_PER_SEC;
}

int main() {
    srand(time(NULL));

    int sizes[] = {10, 1000, 10000, 100000};
    int tests = 4;

    printf("\n===== Таблица времени (сек) =====\n");
    printf("%10s %15s %15s %15s\n",
           "N", "Bubble", "Insertion", "Merge");

    for (int t = 0; t < tests; t++) {
        int n = sizes[t];
        int *array = malloc(n * sizeof(int));

        for (int i = 0; i < n; i++)
            array[i] = rand();

        double t_bubble   = measure_time(bubble_sort, array, n);
        double t_insert   = measure_time(insertion_sort, array, n);
        double t_merge    = measure_merge(array, n);

        printf("%10d %15lf %15lf %15lf\n",
               n, t_bubble, t_insert, t_merge);

        free(array);
    }

    return 0;
}
