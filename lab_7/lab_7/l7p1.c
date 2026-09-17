#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev, *next;
} Node;

Node *head = NULL, *tail = NULL;

Node* create1(int v) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = v;
    n->prev = n->next = NULL;
    return n;
}

void insertRear(int v) {
    Node* n = create(v);
    if (!head) head = tail = n;
    else { tail->next = n; n->prev = tail; tail = n; }
}

void deleteRear() {
    if (!tail) return;
    Node* t = tail;
    if (head == tail) head = tail = NULL;
    else { tail = tail->prev; tail->next = NULL; }
    free(t);
}

void insertPos(int v, int p) {
    if (p < 1) return;
    if (p == 1) {
        Node* n = create(v);
        if (!head) head = tail = n;
        else { n->next = head; head->prev = n; head = n; }
        return;
    }
    Node* c = head;
    for (int i = 1; i < p - 1 && c; i++) c = c->next;
    if (!c) return;
    if (c == tail) { insertRear(v); return; }
    Node* n = create(v);
    n->next = c->next; n->prev = c;
    c->next->prev = n; c->next = n;
}

void deletePos(int p) {
    if (p < 1 || !head) return;
    Node* c = head;
    if (p == 1) {
        head = head->next;
        if (head) head->prev = NULL; else tail = NULL;
        free(c); return;
    }
    for (int i = 1; i < p && c; i++) c = c->next;
    if (!c) return;
    if (c == tail) { deleteRear(); return; }
    c->prev->next = c->next;
    c->next->prev = c->prev;
    free(c);
}

void insertAfter(int v, int val) {
    Node* c = head;
    while (c && c->data != val) c = c->next;
    if (!c) return;
    if (c == tail) { insertRear(v); return; }
    Node* n = create(v);
    n->next = c->next; n->prev = c;
    c->next->prev = n; c->next = n;
}

void insertBefore(int v, int val) {
    if (!head) return;
    if (head->data == val) { insertPos(v, 1); return; }
    Node* c = head;
    while (c && c->data != val) c = c->next;
    if (!c) return;
    Node* n = create(v);
    n->prev = c->prev; n->next = c;
    c->prev->next = n; c->prev = n;
}

void traverseF() {
    for (Node* c = head; c; c = c->next) printf("%d ", c->data);
    printf("\n");
}

void traverseR() {
    for (Node* c = tail; c; c = c->prev) printf("%d ", c->data);
    printf("\n");
}

int main1() {
    int ch, v, p;
    while (1) {
        printf("\n1.InsRear 2.DelRear 3.InsPos 4.DelPos 5.InsAfter 6.InsBefore 7.TravF 8.TravR 9.Exit\n> ");
        scanf("%d", &ch);
        if (ch == 9) break;
        switch (ch) {
            case 1: printf("Val: "); scanf("%d", &v); insertRear(v); break;
            case 2: deleteRear(); break;
            case 3: printf("Val Pos: "); scanf("%d %d", &v, &p); insertPos(v, p); break;
            case 4: printf("Pos: "); scanf("%d", &p); deletePos(p); break;
            case 5: printf("Val Target: "); scanf("%d %d", &v, &p); insertAfter(v, p); break;
            case 6: printf("Val Target: "); scanf("%d %d", &v, &p); insertBefore(v, p); break;
            case 7: traverseF(); break;
            case 8: traverseR(); break;
        }
    }
    return 0;
}
