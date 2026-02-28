#include <stdio.h>

int comparisons = 0;
int movements = 0;

void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++) {
        L[i] = arr[left + i];
        movements++;
    }

    for (j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
        movements++;
    }

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        comparisons++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        movements++;
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
        movements++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
        movements++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int arr[] = {45, 12, 89, 32, 5, 77, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, n - 1);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\nComparisons: %d", comparisons);
    printf("\nMovements: %d", movements);

    return 0;
}