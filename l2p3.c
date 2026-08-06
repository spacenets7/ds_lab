#include <stdio.h>
#include <stdlib.h>

int** allocateMatrix(int r, int c) {
    int** mat = (int**)malloc(r * sizeof(int*));
    for (int i = 0; i < r; i++) {
        *(mat + i) = (int*)malloc(c * sizeof(int));
    }
    return mat;
}

void readMatrix(int** mat, int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", (*(mat + i) + j));
        }
    }
}

void displayMatrix(int** mat, int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d ", *(*(mat + i) + j));
        }
        printf("\n");
    }
}

void multiplyMatrices(int** mat1, int** mat2, int** res, int r1, int c1, int c2) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            *(*(res + i) + j) = 0;
            for (int k = 0; k < c1; k++) {
                *(*(res + i) + j) += *(*(mat1 + i) + k) * *(*(mat2 + k) + j);
            }
        }
    }
}

void freeMatrix(int** mat, int r) {
    for (int i = 0; i < r; i++) {
        free(*(mat + i));
    }
    free(mat);
}

int main3() {
    int r1, c1, r2, c2;

    printf("Enter rows and columns for first matrix: ");
    if (scanf("%d %d", &r1, &c1) != 2) return 1;

    printf("Enter rows and columns for second matrix: ");
    if (scanf("%d %d", &r2, &c2) != 2) return 1;

    if (c1 != r2) {
        printf("Matrix multiplication not possible.\n");
        return 1;
    }

    int** mat1 = allocateMatrix(r1, c1);
    int** mat2 = allocateMatrix(r2, c2);
    int** res = allocateMatrix(r1, c2);

    printf("Enter elements of first matrix:\n");
    readMatrix(mat1, r1, c1);

    printf("Enter elements of second matrix:\n");
    readMatrix(mat2, r2, c2);

    multiplyMatrices(mat1, mat2, res, r1, c1, c2);

    printf("Resultant matrix:\n");
    displayMatrix(res, r1, c2);

    freeMatrix(mat1, r1);
    freeMatrix(mat2, r2);
    freeMatrix(res, r1);

    return 0;
}
