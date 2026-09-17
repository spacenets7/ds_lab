#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev, *next;
} Node;

Node* create(int v) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = v;
    n->prev = n->next = NULL;
    return n;
}

Node* append(Node* head, int v) {
    Node* n = create(v);
    if (!head) return n;
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = n;
    n->prev = temp;
    return head;
}

void concatenate(Node** X1, Node* X2) {
    if (!*X1) {
        *X1 = X2;
        return;
    }
    if (!X2) return;

    Node* temp = *X1;
    while (temp->next) temp = temp->next;

    temp->next = X2;
    X2->prev = temp;
}

int main() {
    Node *X1 = NULL, *X2 = NULL;

    X1 = append(X1, 10);
    X1 = append(X1, 20);

    X2 = append(X2, 30);
    X2 = append(X2, 40);

    concatenate(&X1, X2);

    for (Node* t = X1; t; t = t->next) {
        printf("%d ", t->data);
    }
    printf("\n");

    return 0;
}
