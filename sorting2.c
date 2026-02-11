#include <stdio.h>

// Function to perform Bubble Sort in descending order
// and count the number of swaps
void bubbleSortDescending(int arr[], int n, int *swapCount) {
    int i, j, temp;

    // Initialize swap counter to 0
    *swapCount = 0;

    // Outer loop controls number of passes
    for (i = 0; i < n - 1; i++) {

        // Inner loop for comparing adjacent elements
        for (j = 0; j < n - i - 1; j++) {

            // If current element is smaller than next,
            // swap them (for descending order)
            if (arr[j] < arr[j + 1]) {

                // Swap logic
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                // Increase swap count
                (*swapCount)++;
            }
        }
    }
}

int main() {
    int n, i, swaps;

    // Take number of elements from user
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];   // Declare array of size n

    // Input array elements
    printf("Enter elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Call bubble sort function
    bubbleSortDescending(arr, n, &swaps);

    // Display sorted array
    printf("Sorted array (Descending):\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    // Display total swaps
    printf("\nTotal swaps performed: %d\n", swaps);

    return 0;
}
