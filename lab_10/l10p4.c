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

int main() {
    struct Node *root = NULL, *temp;
    int n, x;
    printf("Number of nodes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }
    if (root == NULL) {
        printf("Tree is empty\n");
        return 0;
    }
    temp = root;
    while (temp->left != NULL) temp = temp->left;
    printf("Minimum: %d\n", temp->data);
    temp = root;
    while (temp->right != NULL) temp = temp->right;
    printf("Maximum: %d\n", temp->data);
    return 0;
}
