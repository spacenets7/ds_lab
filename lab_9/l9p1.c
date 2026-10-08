#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void iterativeInorder(struct Node* root) {
    struct Node* stack[100];
    int top = -1;
    struct Node* curr = root;
    while (curr != NULL || top != -1) {
        while (curr != NULL) {
            stack[++top] = curr;
            curr = curr->left;
        }
        curr = stack[top--];
        printf("%d ", curr->data);
        curr = curr->right;
    }
}

void iterativePostorder(struct Node* root) {
    if (root == NULL) return;
    struct Node* stack1[100];
    struct Node* stack2[100];
    int top1 = -1, top2 = -1;
    stack1[++top1] = root;
    while (top1 != -1) {
        struct Node* curr = stack1[top1--];
        stack2[++top2] = curr;
        if (curr->left != NULL) stack1[++top1] = curr->left;
        if (curr->right != NULL) stack1[++top1] = curr->right;
    }
    while (top2 != -1) {
        printf("%d ", stack2[top2--]->data);
    }
}

void iterativePreorder(struct Node* root) {
    if (root == NULL) return;
    struct Node* stack[100];
    int top = -1;
    stack[++top] = root;
    while (top != -1) {
        struct Node* curr = stack[top--];
        printf("%d ", curr->data);
        if (curr->right != NULL) stack[++top] = curr->right;
        if (curr->left != NULL) stack[++top] = curr->left;
    }
}

void printParent(struct Node* root, int key) {
    if (root == NULL) return;
    if ((root->left && root->left->data == key) || (root->right && root->right->data == key)) {
        printf("%d", root->data);
        return;
    }
    printParent(root->left, key);
    printParent(root->right, key);
}

int findDepth(struct Node* root) {
    if (root == NULL) return 0;
    int leftDepth = findDepth(root->left);
    int rightDepth = findDepth(root->right);
    return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
}

int printAncestors(struct Node* root, int key) {
    if (root == NULL) return 0;
    if (root->data == key) return 1;
    if (printAncestors(root->left, key) || printAncestors(root->right, key)) {
        printf("%d ", root->data);
        return 1;
    }
    return 0;
}

int countLeafNodes(struct Node* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}
