#include <stdio.h>

// Function to perform Counting Sort
void countingSort(int arr[], int n) {
    int i, max = arr[0];

    // Step 1: Find the maximum element
    for (i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }

    // Step 2: Create count array
    int count[max + 1];

    // Initialize count array to 0
    for (i = 0; i <= max; i++)
        count[i] = 0;

    // Step 3: Store frequency of each element
    for (i = 0; i < n; i++)
        count[arr[i]]++;

    // Step 4: Reconstruct the sorted array
    int index = 0;
    for (i = 0; i <= max; i++) {
        while (count[i] > 0) {
            arr[index] = i;
            index++;
            count[i]--;
        }
    }
}

int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    countingSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}