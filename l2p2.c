#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int* findMinIndex(int *start, int *end) {
    if (start == end) {
        return start;
    }
    int *minOfRest = findMinIndex(start + 1, end);
    if (*start < *minOfRest) {
        return start;
    } else {
        return minOfRest;
    }
}

void selectionSortRecursive(int *start, int *end) {
    if (start >= end) {
        return;
    }
    int *minPtr = findMinIndex(start, end);
    if (minPtr != start) {
        swap(start, minPtr);
    }
    selectionSortRecursive(start + 1, end);
}

int main2() {
    int n;
    printf("Enter the number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        return 1;
    }

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        return 1;
    }

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", (arr + i));
    }

    selectionSortRecursive(arr, arr + n - 1);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");

    free(arr);
    return 0;
}

