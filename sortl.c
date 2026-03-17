#include <stdio.h>

int main() {
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(arr) / sizeof(arr[0]);

    int max_sum = arr[0];
    int current_sum = arr[0];

    int start = 0, end = 0, temp_start = 0;

    for (int i = 1; i < n; i++) {
        if (current_sum + arr[i] < arr[i]) {
            current_sum = arr[i];
            temp_start = i;
        } else {
            current_sum += arr[i];
        }

        if (current_sum > max_sum) {
            max_sum = current_sum;
            start = temp_start;
            end = i;
        }
    }

    printf("Maximum sum = %d\n", max_sum);
    printf("Subarray: ");
    for (int i = start; i <= end; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}