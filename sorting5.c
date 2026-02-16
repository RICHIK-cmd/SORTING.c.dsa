#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int i, j;
    char temp;

    // Taking string input
    printf("Enter a string: ");
    scanf("%s", str);

    int n = strlen(str);

    // Bubble Sort logic
    for (i = 0; i < n - 1; i++) {
        // After every pass, last i characters are already sorted
        for (j = 0; j < n - i - 1; j++) {
            // Compare adjacent characters
            if (str[j] > str[j + 1]) {
                // Swap characters
                temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }

    // Printing sorted string
    printf("Sorted string: %s", str);

    return 0;
}
