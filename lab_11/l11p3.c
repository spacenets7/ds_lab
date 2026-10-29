#include <stdio.h>

int a[20][20], visited[20], queue[20];

int main() {
    int n, e, u, v, start, front = 0, rear = 0;
    printf("Vertices and edges: ");
    scanf("%d%d", &n, &e);
    if (n < 1 || n > 20 || e < 0) return 1;
    printf("Enter edges (0 to %d):\n", n - 1);
    for (int i = 0; i < e; i++) {
        scanf("%d%d", &u, &v);
        if (u < 0 || u >= n || v < 0 || v >= n) return 1;
        a[u][v] = a[v][u] = 1;
    }
    printf("Start vertex: ");
    scanf("%d", &start);
    if (start < 0 || start >= n) return 1;
    visited[start] = 1;
    queue[rear++] = start;
    printf("BFS: ");
    while (front < rear) {
        u = queue[front++];
        printf("%d ", u);
        for (int i = 0; i < n; i++) {
            if (a[u][i] && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
    return 0;
}
