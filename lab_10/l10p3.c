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

struct Node *deleteNode(struct Node *root, int x) {
    if (root == NULL) return NULL;
    if (x < root->data) root->left = deleteNode(root->left, x);
    else if (x > root->data) root->right = deleteNode(root->right, x);
    else {
        if (root->left == NULL) {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        if (root->right == NULL) {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }
        struct Node *temp = root->right;
        while (temp->left != NULL) temp = temp->left;
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void inorder(struct Node *root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
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
    printf("Element to delete: ");
    scanf("%d", &x);
    root = deleteNode(root, x);
    printf("Inorder after deletion: ");
    inorder(root);
    printf("\n");
    return 0;
}
