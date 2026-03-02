// Apply Merge Sort to sort a linked list.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Print linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Merge two sorted linked lists
struct Node* merge(struct Node* left, struct Node* right) {
    if (left == NULL)
        return right;
    if (right == NULL)
        return left;

    struct Node* result = NULL;

    if (left->data <= right->data) {
        result = left;
        result->next = merge(left->next, right);
    } else {
        result = right;
        result->next = merge(left, right->next);
    }

    return result;
}

// Find middle of linked list
struct Node* getMiddle(struct Node* head) {
    if (head == NULL)
        return head;

    struct Node* slow = head;
    struct Node* fast = head->next;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

// Merge Sort for linked list
struct Node* mergeSort(struct Node* head) {
    if (head == NULL || head->next == NULL)
        return head;

    struct Node* middle = getMiddle(head);
    struct Node* nextOfMiddle = middle->next;

    middle->next = NULL;  // split list

    struct Node* left = mergeSort(head);
    struct Node* right = mergeSort(nextOfMiddle);

    return merge(left, right);
}

int main() {
    struct Node* head = NULL;

    head = newNode(4);
    head->next = newNode(2);
    head->next->next = newNode(1);
    head->next->next->next = newNode(3);

    printf("Original List: ");
    printList(head);

    head = mergeSort(head);

    printf("Sorted List: ");
    printList(head);

    return 0;
}