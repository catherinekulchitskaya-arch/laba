#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *f = fopen(argv[1], "r");
    if (!f)
    {
        printf("Cannot open file %s\n", argv[1]);
        return 1;
    }

    int N, M;
    fscanf(f, "%d %d", &N, &M);

    double **a = malloc(N * sizeof(double *));
    if (!a){
        printf("FFFFFF\n");
        fclose(f);
        return 1;
    }
    for (int i = 0; i < N; i++) {
        a[i] = malloc(M * sizeof(double));
        if (!a){
            printf("FFFFFF\n", i);
            for (int k= 0; k < i;k++)
                free(a[k]);
            free(a);
            
            fclose(f);
            return 1;
        }
    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            fscanf(f, "%lf", &a[i][j]);

    fclose(f);

    }
    double maxEven = a[0][1];

    for (int j = 1; j < M; j += 2)     
        for (int i = 0; i < N; i++)
            if (a[i][j] > maxEven)
                maxEven = a[i][j];
  
    if (M < 4)
    {
        printf("Матрица меньше 4 столбцов!\n");
         for (int i= 0; i < N;i++)
                free(a[i]);
            free(a);
        return 1;
    }

    double P = 1.0;
    for (int i = 0; i < N; i++)
        P *= (1 + cos(1 - 1.0 / a[i][3]));

    P += 8.3;

    printf("Максимум среди элементов четных столбцов: %.4lf\n", maxEven);
    printf("Произведение P = %.6lf\n", P);

    for (int i = 0; i < N; i++)
        free(a[i]);
    free(a);

    return 0;
}
