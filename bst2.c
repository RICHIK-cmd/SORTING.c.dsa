#include <stdio.h>
#include <stdlib.h>

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

// Global counter
int count = 0;

// Function to find kth smallest
void kthSmallest(struct Node* root, int k) {
    if (root == NULL)
        return;

    // Traverse left
    kthSmallest(root->left, k);

    // Increment count
    count++;

    // If count matches k
    if (count == k) {
        printf("K-th smallest element: %d\n", root->data);
        return;
    }

    // Traverse right
    kthSmallest(root->right, k);
}

int main() {
    struct Node* root = newNode(20);
    root->left = newNode(10);
    root->right = newNode(30);
    root->left->left = newNode(5);
    root->left->right = newNode(15);

    int k = 3;
    kthSmallest(root, k);

    return 0;
}