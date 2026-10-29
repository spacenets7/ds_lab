#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node *next;
};

struct Node *a[20];

void add(int u, int v) {
    struct Node *p = malloc(sizeof(struct Node));
    if (p == NULL) exit(1);
    p->vertex = v;
    p->next = a[u];
    a[u] = p;
}

int main() {
    int n, e, u, v, directed;
    printf("Vertices and edges: ");
    scanf("%d%d", &n, &e);
    if (n < 1 || n > 20 || e < 0) return 1;
    printf("Directed (1) or undirected (0): ");
    scanf("%d", &directed);
    printf("Enter edges (0 to %d):\n", n - 1);
    for (int i = 0; i < e; i++) {
        scanf("%d%d", &u, &v);
        if (u < 0 || u >= n || v < 0 || v >= n) return 1;
        add(u, v);
        if (!directed) add(v, u);
    }
    printf("Adjacency list:\n");
    for (int i = 0; i < n; i++) {
        printf("%d:", i);
        for (struct Node *p = a[i]; p != NULL; p = p->next)
            printf(" %d", p->vertex);
        printf("\n");
    }
    return 0;
}
