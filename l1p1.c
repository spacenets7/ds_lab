//max
#include <stdio.h>

#define ROWS 3
#define COLS 3

int main1() {
    int A[ROWS][COLS], B[ROWS][COLS], C[ROWS][COLS];
    int i, j;


    printf("Enter elements of matrix A (%dx%d):\n", ROWS, COLS);
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            scanf("%d", &A[i][j]);
        }
    }


    printf("Enter elements of matrix B (%dx%d):\n", ROWS, COLS);
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            scanf("%d", &B[i][j]);
        }
    }


    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            C[i][j] = (A[i][j] > B[i][j]) ? A[i][j] : B[i][j];
        }
    }


    printf("Resultant Matrix C (Maximum values):\n");
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            printf("%d \t", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}

