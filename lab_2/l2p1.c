#include <stdio.h>
#include <stdlib.h>


int findSmallest(int *arr, int size) {

    int smallest = *arr;


    for (int i = 1; i < size; i++) {
        if (*(arr + i) < smallest) {
            smallest = *(arr + i);
        }
    }

    return smallest;
}

int main1() {
    int size;


    printf("Enter the number of elements: ");
    if (scanf("%d", &size) != 1 || size <= 0) {
        printf("Invalid array size.\n");
        return 1;
    }


    int *array = (int *)malloc(size * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }


    printf("Enter %d integers:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", (array + i));
    }


    int min_element = findSmallest(array, size);
    printf("The smallest element in the array is: %d\n", min_element);
    free(array);

    return 0;
}

