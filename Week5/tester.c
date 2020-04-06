// Name: Lindsey Reynolds
// Date: 04/07/20
// Title: Lab 5 – Step 3
// Description:

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *calc(void *);
void fillMatrices();
void printMatrices();
#define N 2
#define M 3
#define L 2
int matrixA[N][M];
int matrixB[M][L];
int matrixC[N][L];
pthread_t threads[N*N];

typedef struct {
    int matrixA_row;
    int matrixB_col;
} calcCell;

int main()
{
    fillMatrices();

    int thread_count = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            calcCell *cell = malloc(sizeof(calcCell));
            cell->matrixA_row = i;
            cell->matrixB_col = j;
            pthread_create(&threads[thread_count], NULL, calc, cell);
            thread_count++;
        }
    }
    printMatrices();
    return 0;
}

void printMatrices(){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            printf("%d ", matrixA[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < M; i++){
        for (int j = 0; j < L; j++){
            printf("%d ", matrixB[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < N; i++){
        for (int j = 0; j < L; j++){
            printf("%d ", matrixC[i][j]);
        }
        printf("\n");
    }
}

void fillMatrices()
{
    matrixA[0][0] = 0;
    matrixA[0][1] = 3;
    matrixA[0][2] = 5;
    matrixA[1][0] = 5;
    matrixA[1][1] = 5;
    matrixA[1][2] = 2;

    matrixB[0][0] = 3;
    matrixB[0][1] = 4;
    matrixB[1][0] = 3;
    matrixB[1][1] = -2;
    matrixB[2][0] = 4;
    matrixB[2][1] = -2;
}


void *calc(void *theCell){
    calcCell *cell = (calcCell *) theCell;
    int row = cell->matrixA_row;
    int col = cell->matrixB_col;

    double sum = 0;
    for(int j = 0; j < M; j++){
        sum += matrixA[row][j] * matrixB[j][col];
    }
    matrixC[row][col] = sum;

    free(theCell);
}
