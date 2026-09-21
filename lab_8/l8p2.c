#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coef, exp;
    struct Node *prev, *next;
} Node;

Node *insert(Node *head, int c, int e) {
    Node *n = malloc(sizeof(Node));
    n->coef = c;
    n->exp = e;
    n->prev = n->next = NULL;

    if (head == NULL)
        return n;

    Node *p = head;

    while (p->next != NULL)
        p = p->next;

    p->next = n;
    n->prev = p;

    return head;
}

Node *readPoly() {
    Node *head = NULL;
    int n, c, e;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent: ");
        scanf("%d%d", &c, &e);
        head = insert(head, c, e);
    }

    return head;
}

Node *add(Node *p, Node *q) {
    Node *r = NULL;

    while (p != NULL && q != NULL) {
        if (p->exp > q->exp) {
            r = insert(r, p->coef, p->exp);
            p = p->next;
        } else if (p->exp < q->exp) {
            r = insert(r, q->coef, q->exp);
            q = q->next;
        } else {
            int sum = p->coef + q->coef;

            if (sum != 0)
                r = insert(r, sum, p->exp);

            p = p->next;
            q = q->next;
        }
    }

    while (p != NULL) {
        r = insert(r, p->coef, p->exp);
        p = p->next;
    }

    while (q != NULL) {
        r = insert(r, q->coef, q->exp);
        q = q->next;
    }

    return r;
}

void display(Node *p) {
    while (p != NULL) {
        printf("%dx^%d", p->coef, p->exp);

        if (p->next != NULL)
            printf(" + ");

        p = p->next;
    }

    printf("\n");
}

int main() {
    Node *p1, *p2, *sum;

    printf("Polynomial 1\n");
    p1 = readPoly();

    printf("Polynomial 2\n");
    p2 = readPoly();

    sum = add(p1, p2);

    printf("Polynomial 1: ");
    display(p1);

    printf("Polynomial 2: ");
    display(p2);

    printf("Sum: ");
    display(sum);

    return 0;
}
