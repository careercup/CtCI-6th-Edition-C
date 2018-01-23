#include <stdio.h>
#include <stdlib.h>
void zeroMatrix(int**, int, int);

int main()
{
    int i, j, M, N, **data;
    printf("M: ");
    scanf("%d", &M);
    printf("N: ");
    scanf("%d", &N);
    data = (int**)malloc(M*sizeof(int*));
    for(i = 0; i < M; i++)
        data[i] = (int*)malloc(N*sizeof(int));
    printf("Enter the %dx%d matrix:\n", M, N);
    for(i = 0; i < M; i++)
        for(j = 0; j < N; j++)
            scanf("%d", &data[i][j]);
    zeroMatrix(data, M, N);
    printf("\nOn zeroing:\n");
    for(i = 0; i < M; i++)
    {
        for(j = 0; j < N; j++)
            printf("%d\t", data[i][j]);
        printf("\n");
    }
}

void zeroMatrix(int** data, int M, int N)
{
    int i, j, rows[M], cols[N];
    for(i = 0; i < M; i++)
        rows[i] = 0;
    for(j = 0; j < N; j++)
        cols[j] = 0;
    for(i = 0; i < M; i++)
        for(j = 0; j < N; j++)
            if(data[i][j] == 0)
            {
                rows[i] = 1;
                cols[j] = 1;
            }
    for(i = 0; i < M; i++)
        if(rows[i] == 1)
            for(j = 0; j < N; j++)
                data[i][j] = 0;
    for(i = 0; i < N; i++)
        if(cols[i] == 1)
            for(j = 0; j < M; j++)
                data[j][i] = 0;
}