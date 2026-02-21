#include <stdio.h>

void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n - 1; i++) {

        // Assume the current position has the minimum element
        minIndex = i;

        // Find the minimum element in remaining unsorted array
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap the found minimum element with the first element
        if (minIndex != i) {
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}