#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Structure of node
struct Node {
    int data;
    struct Node *left, *right;
};

// Create new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to check BST
int isBSTUtil(struct Node* root, int min, int max) {
    if (root == NULL)
        return 1;

    // Check current node value in range
    if (root->data <= min || root->data >= max)
        return 0;

    // Recursively check left and right
    return isBSTUtil(root->left, min, root->data) &&
           isBSTUtil(root->right, root->data, max);
}

// Wrapper function
int isBST(struct Node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

int main() {
    struct Node* root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(15);
    root->right->left = newNode(12);
    root->right->right = newNode(20);

    if (isBST(root))
        printf("Valid BST\n");
    else
        printf("Not a BST\n");

    return 0;
}