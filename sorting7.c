#include <stdio.h>

int main() {
    int arr[100], temp[100];
    int n, i, j;

    // Input size
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Input elements
    printf("Enter elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Step 1: Bubble Sort in ascending order
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap
                int t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
        }
    }

    // Step 2: Rearrange in alternate order
    int start = 0;          // smallest index
    int end = n - 1;        // largest index
    int k = 0;              // index for temp array

    while (start <= end) {
        // Add smallest
        temp[k++] = arr[start++];

        // Add largest (only if different element remains)
        if (start <= end) {
            temp[k++] = arr[end--];
        }
    }

    // Print final alternate array
    printf("Alternate sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", temp[i]);
    }

    return 0;
}
