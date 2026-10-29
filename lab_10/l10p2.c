#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node *insert(struct Node *root, int x) {
    if (root == NULL) {
        root = malloc(sizeof(struct Node));
        root->data = x;
        root->left = root->right = NULL;
    } else if (x < root->data)
        root->left = insert(root->left, x);
    else if (x > root->data)
        root->right = insert(root->right, x);
    return root;
}

int search(struct Node *root, int x) {
    if (root == NULL) return 0;
    if (root->data == x) return 1;
    if (x < root->data) return search(root->left, x);
    return search(root->right, x);
}

int main() {
    struct Node *root = NULL;
    int n, x;
    printf("Number of nodes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }
    printf("Element to search: ");
    scanf("%d", &x);
    if (search(root, x)) printf("Found\n");
    else printf("Not found\n");
    return 0;
}
