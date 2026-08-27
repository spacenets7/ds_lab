#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

struct Job {
    int id;
    char name[30];
};

int main() {
    struct Job q[MAX];
    int front = 0, rear = 0, n;

    printf("Enter number of print jobs: ");
    scanf("%d", &n);

    for (int i = 0; i < n && rear < MAX; i++) {
        q[rear].id = rand() % 1000 + 1;

        printf("Enter document name: ");
        scanf("%s", q[rear].name);

        printf("Added: %d %s\n", q[rear].id, q[rear].name);
        rear++;
    }

    printf("\nPrinting jobs:\n");

    while (front < rear) {
        printf("Printing: %d %s\n", q[front].id, q[front].name);
        front++;
    }

    return 0;
}
