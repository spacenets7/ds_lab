#include <stdio.h>

#define MAX 10

int main() {
    int q[MAX], front = 0, rear = 0;
    int choice, value;

    while (1) {
        printf("\n1.Enqueue 2.Dequeue 3.Display 4.Exit\n");
        scanf("%d", &choice);

        if (choice == 1) {
            if (rear == MAX) {
                printf("Queue Full\n");
            } else {
                printf("Enter value: ");
                scanf("%d", &value);
                q[rear++] = value;
            }
        }

        else if (choice == 2) {
            if (front == rear) {
                printf("Queue Empty\n");
            } else {
                printf("Deleted: %d\n", q[front++]);
            }
        }

        else if (choice == 3) {
            if (front == rear) {
                printf("Queue Empty\n");
            } else {
                for (int i = front; i < rear; i++)
                    printf("%d ", q[i]);

                printf("\n");
            }
        }

        else if (choice == 4) {
            break;
        }
    }

    return 0;
}
