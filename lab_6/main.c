#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void add(int x) {
    struct Node *n = malloc(sizeof(struct Node)), *p = head;
    n->data = x; n->next = NULL;
    if(!head) head = n;
    else {
        while(p->next) p = p->next;
        p->next = n;
    }
}

void before(int x, int y) {
    struct Node *n = malloc(sizeof(struct Node)), *p = head;
    n->data = x;
    if(head && head->data == y) {
        n->next = head; head = n; return;
    }
    while(p && p->next && p->next->data != y) p = p->next;
    if(p && p->next) {
        n->next = p->next; p->next = n;
    } else free(n);
}

void after(int x, int y) {
    struct Node *p = head;
    while(p && p->data != y) p = p->next;
    if(p) {
        struct Node *n = malloc(sizeof(struct Node));
        n->data = x; n->next = p->next; p->next = n;
    }
}

void del(int x) {
    struct Node *p = head, *q = NULL;
    while(p && p->data != x) { q = p; p = p->next; }
    if(!p) return;
    if(q) q->next = p->next;
    else head = p->next;
    free(p);
}

void display() {
    struct Node *p = head;
    while(p) { printf("%d ", p->data); p = p->next; }
    printf("\n");
}

void reverse() {
    struct Node *p = head, *q = NULL, *r;
    while(p) {
        r = p->next; p->next = q;
        q = p; p = r;
    }
    head = q;
}

void sort() {
    for(struct Node *p=head; p; p=p->next)
        for(struct Node *q=p->next; q; q=q->next)
            if(p->data > q->data) {
                int t=p->data; p->data=q->data; q->data=t;
            }
}

void alternate() {
    if(!head) return;
    struct Node *p = head, *q;
    while(p && p->next) {
        q = p->next;
        p->next = q->next;
        free(q);
        p = p->next;
    }
}

void sortedInsert(int x) {
    struct Node *n = malloc(sizeof(struct Node)), *p = head;
    n->data = x;
    if(!head || x < head->data) {
        n->next = head; head = n; return;
    }
    while(p->next && p->next->data < x) p = p->next;
    n->next = p->next; p->next = n;
}

int main() {
    int ch, x, y;

    while(1) {
        printf("\n1.Add 2.Before 3.After 4.Delete 5.Display\n");
        printf("6.Reverse 7.Sort 8.Delete Alternate 9.Sorted Insert 10.Exit\n");
        scanf("%d",&ch);

        if(ch==1) { scanf("%d",&x); add(x); }
        else if(ch==2) { scanf("%d%d",&x,&y); before(x,y); }
        else if(ch==3) { scanf("%d%d",&x,&y); after(x,y); }
        else if(ch==4) { scanf("%d",&x); del(x); }
        else if(ch==5) display();
        else if(ch==6) reverse();
        else if(ch==7) sort();
        else if(ch==8) alternate();
        else if(ch==9) { scanf("%d",&x); sortedInsert(x); }
        else break;
    }
}
