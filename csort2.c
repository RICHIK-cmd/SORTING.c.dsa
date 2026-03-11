#include <stdio.h>

int main() {
    int n, i;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int max = arr[0];

    // Find maximum element
    for(i = 1; i < n; i++) {
        if(arr[i] > max)
            max = arr[i];
    }

    int count[max + 1];

    // Initialize count array
    for(i = 0; i <= max; i++) {
        count[i] = 0;
    }

    // Count frequency
    for(i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Print frequencies
    for(i = 0; i <= max; i++) {
        if(count[i] > 0) {
            printf("%d appears %d times\n", i, count[i]);
        }
    }

    return 0;
}