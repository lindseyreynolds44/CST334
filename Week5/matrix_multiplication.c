// Name: Lindsey Reynolds
// Date: 04/07/20
// Title: Lab 5 – Step 3
// Description: This program multiplies two matrices, 
// matrixA and matrixB, displaying their result in matrixC.

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Function declarations
void *calc(void *);
void fillMatrices();
void printMatrices();

// Global variables
#define N 4
#define M 3
#define L 6

// Matrix declarations
int matrixA[N][M];
int matrixB[M][L];
int matrixC[N][L];

// Thread array declaration
pthread_t threads[N * L];

// Create a struct to hold the row and columns to be calculated by
// the running thread
typedef struct
{
    int matrixA_row;
    int matrixB_col;
} calcCell;

int main()
{
    fillMatrices();

    int thread_count = 0; // Keep track of how many threads are created
    for (int i = 0; i < N; i++){
        for (int j = 0; j < L; j++){
            calcCell *cell = malloc(sizeof(calcCell));
            cell->matrixA_row = i;
            cell->matrixB_col = j;
            pthread_create(&threads[thread_count], NULL, calc, cell);
            thread_count++;
        }
    }

    for (int i = 0; i < thread_count; i++)
        pthread_join(threads[i], NULL);

    printMatrices();
    return 0;
}

/**
 * Populate matrixA and matrixB with random numbers between 0 and 100
 */
void fillMatrices()
{
    srand(time(0));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++){
            int num = rand() % 100 + 1;
            matrixA[i][j] = num;
        }
    for (int i = 0; i < M; i++)
        for (int j = 0; j < L; j++){
            int num = rand() % 100 + 1;
            matrixB[i][j] = num;
        }
}

/**
 * Given the row from matrixA and the column from matrixB, calculate
 * the dot product. Then plug the answer into matrixC. 
 */
void *calc(void *theCell)
{
    calcCell *cell = (calcCell *)theCell;
    int row = cell->matrixA_row;
    int col = cell->matrixB_col;

    double sum = 0;
    for (int j = 0; j < M; j++)
    {
        sum += matrixA[row][j] * matrixB[j][col];
    }
    matrixC[row][col] = sum;

    free(theCell);
    return 0; // To please the compiler
}

/**
 * For testing purposes, this function prints the contents
 * of each matrix. Do not use for N, M, L over around 50.
 */
void printMatrices()
{
    // Print matrixA
    printf("\nMatrix A:\n");
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            printf("%d ", matrixA[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // Print matrixB
    printf("Matrix B:\n");
    for (int i = 0; i < M; i++){
        for (int j = 0; j < L; j++){
            printf("%d ", matrixB[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // Print matrixC
    printf("Matrix C:\n");
    for (int i = 0; i < N; i++){
        for (int j = 0; j < L; j++){
            printf("%d ", matrixC[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}