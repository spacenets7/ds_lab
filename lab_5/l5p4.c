#include <stdio.h>

#define MAX 10

struct Patient {
    char name[30];
    int age;
    int priority;
};

int main() {
    struct Patient q[MAX];
    int front = 0, rear = 0;
    int choice;

    while (1) {
        printf("\n1.Enqueue 2.Dequeue 3.Display 4.Exit\n");
        scanf("%d", &choice);

        if (choice == 1) {
            if (rear == MAX) {
                printf("Queue Full\n");
            } else {
                printf("Enter name: ");
                scanf("%s", q[rear].name);

                printf("Enter age: ");
                scanf("%d", &q[rear].age);

                printf("Enter priority: ");
                scanf("%d", &q[rear].priority);

                rear++;
            }
        }

        else if (choice == 2) {
            if (front == rear) {
                printf("Queue Empty\n");
            } else {
                printf("Removed: %s %d %d\n",
                       q[front].name,
                       q[front].age,
                       q[front].priority);
                front++;
            }
        }

        else if (choice == 3) {
            if (front == rear) {
                printf("Queue Empty\n");
            } else {
                for (int i = front; i < rear; i++) {
                    printf("%s %d %d\n",
                           q[i].name,
                           q[i].age,
                           q[i].priority);
                }
            }
        }

        else if (choice == 4) {
            break;
        }
    }

    return 0;
}
