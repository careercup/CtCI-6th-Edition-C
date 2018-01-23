#include <stdio.h>
#include <stdlib.h>
void rotate(int**, int, int);
void rotateEdge(int**, int, int);

int main()
{
    int** img, N, i, j;
    printf("N: ");
    scanf("%d", &N);
    img = (int**)malloc(N*sizeof(int*));
    for(i = 0; i < N; i++)
        img[i] = (int*)malloc(N*sizeof(int));
    printf("Enter the image matrix:\n");
    for(i = 0; i < N; i++)
        for(j = 0; j < N; j++)
            scanf("%d", &img[i][j]);
    rotate(img, 0, N-1);
    printf("\nOn rotation:\n");
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
            printf("%d\t", img[i][j]);
        printf("\n");
    }
    return 0;
}

// a: first element index in submatrix of top row, b: last element index in submatrix of top row
void rotate(int** img, int a, int b)
{
    if(a < b)
    {
        rotateEdge(img, a, b);
        rotate(img, a+1, b-1);
    }
}

void rotateEdge(int** img, int a, int b)
{
    int i, temp;
    for(i = a; i < b; i++)
    {
        // store right in temp
        // up to right
        // left to up
        // bottom to left
        // temp to bottom
        temp = img[i][b];
        img[i][b] = img[a][i];
        img[a][i] = img[b-(i-a)][a];
        img[b-(i-a)][a] = img[b][b-(i-a)];
        img[b][b-(i-a)] = temp;
    }
}