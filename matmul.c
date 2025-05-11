#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 500

void matmul(double *A, double *B, double *C, int size) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++) {
            C[i*size + j] = 0.0;
            for (int k = 0; k < size; k++)
                C[i*size + j] += A[i*size + k] * B[k*size + j];
        }
}

int main() {
    double *A = malloc(SIZE * SIZE * sizeof(double));
    double *B = malloc(SIZE * SIZE * sizeof(double));
    double *C = malloc(SIZE * SIZE * sizeof(double));

    srand(time(NULL));
    for (int i = 0; i < SIZE*SIZE; i++) {
        A[i] = (double)rand() / RAND_MAX;
        B[i] = (double)rand() / RAND_MAX;
    }

    matmul(A, B, C, SIZE);

    printf("Result[0]=%f\n", C[0]);

    free(A);
    free(B);
    free(C);

    return 0;
}