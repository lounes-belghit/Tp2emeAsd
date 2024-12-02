#include <stdio.h>
#include <stdlib.h>

// Definition of the tree node
typedef struct TreeNode {
    int value;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Function to create a new tree node
TreeNode* createNode(int value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->value = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a value into the binary search tree
TreeNode* insert(TreeNode* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->value) {
        root->left = insert(root->left, value);
    } else if (value > root->value) {
        root->right = insert(root->right, value);
    }
    return root;
}

// Function to perform in-order traversal and print the tree values
void inOrderTraversal(TreeNode* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->value);
        inOrderTraversal(root->right);
    }
}

// Function to calculate the size of the tree
int treeSize(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + treeSize(root->left) + treeSize(root->right);
}

// Function to calculate the sum of all nodes in the tree
int treeSum(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    return root->value + treeSum(root->left) + treeSum(root->right);
}

// Function to free the memory occupied by the tree nodes
void freeTree(TreeNode* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// Main function to demonstrate the functionality
int main() {
    TreeNode* root = NULL;
    int n, value;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("In-order traversal: ");
    inOrderTraversal(root);
    printf("\n");

    printf("Size of the tree: %d\n", treeSize(root));
    printf("Sum of all nodes: %d\n", treeSum(root));

    freeTree(root);
    return 0;
}