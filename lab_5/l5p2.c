#include <stdio.h>

#define MAX 5

int main() {
    int q[MAX], front = -1, rear = -1;
    int choice, value;

    while (1) {
        printf("\n1.Enqueue 2.Dequeue 3.Display 4.Exit\n");
        scanf("%d", &choice);

        if (choice == 1) {
            if ((rear + 1) % MAX == front) {
                printf("Queue Full\n");
            } else {
                printf("Enter value: ");
                scanf("%d", &value);

                if (front == -1)
                    front = 0;

                rear = (rear + 1) % MAX;
                q[rear] = value;
            }
        }

        else if (choice == 2) {
            if (front == -1) {
                printf("Queue Empty\n");
            } else {
                printf("Deleted: %d\n", q[front]);

                if (front == rear)
                    front = rear = -1;
                else
                    front = (front + 1) % MAX;
            }
        }

        else if (choice == 3) {
            if (front == -1) {
                printf("Queue Empty\n");
            } else {
                int i = front;

                while (1) {
                    printf("%d ", q[i]);

                    if (i == rear)
                        break;

                    i = (i + 1) % MAX;
                }

                printf("\n");
            }
        }

        else if (choice == 4) {
            break;
        }
    }

    return 0;
}
