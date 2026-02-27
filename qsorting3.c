#include <stdio.h> // floating qs

void swap(float *a, float *b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}

int partition(float arr[], int low, int high) {
    float pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++) {
        if(arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(float arr[], int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    float arr[] = {3.2, 1.5, 4.84, 4.80, 0.9};
    int n = sizeof(arr)/sizeof(arr[0]);

    quickSort(arr, 0, n - 1);

    printf("Sorted float array:\n");
    for(int i = 0; i < n; i++)
        printf("%.2f ", arr[i]);

    return 0;
}