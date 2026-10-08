struct Node* createBinaryTree() {
    int data;
    if (scanf("%d", &data) != 1 || data == -1) return NULL;
    struct Node* newNode = createNode(data);
    newNode->left = createBinaryTree();
    newNode->right = createBinaryTree();
    return newNode;
}

void printGivenLevel(struct Node* root, int level) {
    if (root == NULL) return;
    if (level == 1) {
        printf("%d ", root->data);
    } else if (level > 1) {
        printGivenLevel(root->left, level - 1);
        printGivenLevel(root->right, level - 1);
    }
}

void printLevelOrderRecursive(struct Node* root) {
    int h = findDepth(root);
    for (int i = 1; i <= h; i++) {
        printGivenLevel(root, i);
    }
}
