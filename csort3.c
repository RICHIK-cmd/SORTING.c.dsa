#include <stdio.h>
#include <string.h>

int main() {

    char str[100];
    int count[256] = {0};
    int i;

    printf("Enter a string: ");
    scanf("%s", str);

    int len = strlen(str);

    // Count frequency of characters
    for(i = 0; i < len; i++) {
        count[str[i]]++;
    }

    printf("Sorted string: ");

    // Print characters in sorted order
    for(i = 0; i < 256; i++) {
        while(count[i] > 0) {
            printf("%c", i);
            count[i]--;
        }
    }

    return 0;
}