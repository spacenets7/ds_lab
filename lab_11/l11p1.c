#include <stdio.h>

int main() {
    int a[20][20] = {0}, n, e, u, v, directed;
    printf("Vertices and edges: ");
    scanf("%d%d", &n, &e);
    if (n < 1 || n > 20 || e < 0) return 1;
    printf("Directed (1) or undirected (0): ");
    scanf("%d", &directed);
    printf("Enter edges (0 to %d):\n", n - 1);
    for (int i = 0; i < e; i++) {
        scanf("%d%d", &u, &v);
        if (u < 0 || u >= n || v < 0 || v >= n) return 1;
        a[u][v] = 1;
        if (!directed) a[v][u] = 1;
    }
    printf("Adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) printf("%d ", a[i][j]);
        printf("\n");
    }
    return 0;
}
