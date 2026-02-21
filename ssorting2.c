#include <stdio.h>
#include <string.h>

void selectionSort(char arr[][50], int n) {
    int i, j, minIndex;
    char temp[50];

    for (i = 0; i < n - 1; i++) {
        minIndex = i;

        for (j = i + 1; j < n; j++) {
            // Compare strings
            if (strcmp(arr[j], arr[minIndex]) < 0) {
                minIndex = j;
            }
        }

        // Swap strings
        if (minIndex != i) {
            strcpy(temp, arr[i]);
            strcpy(arr[i], arr[minIndex]);
            strcpy(arr[minIndex], temp);
        }
    }
}

int main() {
    char arr[5][50] = {"banana", "apple", "mango", "cherry", "grapes"};
    int n = 5;

    selectionSort(arr, n);

    printf("Sorted strings:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", arr[i]);
    }

    return 0;
}