#include <stdio.h>
#include <string.h>

void selectionSort(char str[]) {
    int i, j, minIndex;
    char temp;
    int n = strlen(str);

    for (i = 0; i < n - 1; i++) {
        minIndex = i;

        for (j = i + 1; j < n; j++) {
            if (str[j] < str[minIndex]) {
                minIndex = j;
            }
        }

        // Swap characters
        if (minIndex != i) {
            temp = str[i];
            str[i] = str[minIndex];
            str[minIndex] = temp;
        }
    }
}

int main() {
    char str[100];

    printf("Enter a string: ");
    scanf("%s", str);   // For single word only

    selectionSort(str);

    printf("Sorted string: %s", str);

    return 0;
}