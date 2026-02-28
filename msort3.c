#include <stdio.h>

void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int removeDuplicates(int arr[], int n) {
    if (n == 0 || n == 1)
        return n;

    int temp[n];
    int j = 0;

    for (int i = 0; i < n - 1; i++) {
        if (arr[i] != arr[i + 1])
            temp[j++] = arr[i];
    }

    temp[j++] = arr[n - 1];

    for (int i = 0; i < j; i++)
        arr[i] = temp[i];

    return j;
}

int main() {
    int arr[] = {45, 12, 89, 12, 5, 77, 5, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, n - 1);
    n = removeDuplicates(arr, n);

    printf("Sorted array without duplicates:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}