#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *first = NULL, *last = NULL;

void display() {
    if (first == NULL) {
        printf("List is empty\n");
        return;
    }

    Node *p = first;
    do {
        printf("%d ", p->data);
        p = p->next;
    } while (p != first);

    printf("\n");
}

void insertEnd(int x) {
    Node *n = malloc(sizeof(Node));
    n->data = x;

    if (first == NULL) {
        first = last = n;
        n->next = first;
    } else {
        n->next = first;
        last->next = n;
        last = n;
    }

    display();
}

void deleteBeginning() {
    if (first == NULL) {
        printf("List is empty\n");
        return;
    }

    Node *temp = first;

    if (first == last) {
        first = last = NULL;
    } else {
        first = first->next;
        last->next = first;
    }

    free(temp);
    display();
}

void deleteEnd() {
    if (first == NULL) {
        printf("List is empty\n");
        return;
    }

    if (first == last) {
        free(first);
        first = last = NULL;
    } else {
        Node *p = first;

        while (p->next != last)
            p = p->next;

        free(last);
        last = p;
        last->next = first;
    }

    display();
}

int main() {
    int ch, x;

    while (1) {
        printf("\n1.Insert End\n2.Delete Beginning\n3.Delete End\n4.Display\n5.Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &x);
                insertEnd(x);
                break;

            case 2:
                deleteBeginning();
                break;

            case 3:
                deleteEnd();
                break;

            case 4:
                display();
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
