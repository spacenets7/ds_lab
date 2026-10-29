#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data, height;
    struct Node *left, *right;
};

int height(struct Node *root) {
    return root == NULL ? 0 : root->height;
}

int max(int a, int b) {
    return a > b ? a : b;
}

struct Node *newNode(int x) {
    struct Node *root = malloc(sizeof(struct Node));
    root->data = x;
    root->height = 1;
    root->left = root->right = NULL;
    return root;
}

struct Node *rotateRight(struct Node *y) {
    struct Node *x = y->left;
    struct Node *t = x->right;
    x->right = y;
    y->left = t;
    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));
    return x;
}

struct Node *rotateLeft(struct Node *x) {
    struct Node *y = x->right;
    struct Node *t = y->left;
    y->left = x;
    x->right = t;
    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));
    return y;
}

struct Node *insert(struct Node *root, int x) {
    if (root == NULL) return newNode(x);
    if (x < root->data) root->left = insert(root->left, x);
    else if (x > root->data) root->right = insert(root->right, x);
    else return root;

    root->height = 1 + max(height(root->left), height(root->right));
    int balance = height(root->left) - height(root->right);

    if (balance > 1 && x < root->left->data) return rotateRight(root);
    if (balance < -1 && x > root->right->data) return rotateLeft(root);
    if (balance > 1 && x > root->left->data) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }
    if (balance < -1 && x < root->right->data) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }
    return root;
}

void preorder(struct Node *root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
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
    printf("AVL preorder: ");
    preorder(root);
    printf("\n");
    return 0;
}
