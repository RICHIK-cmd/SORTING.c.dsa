#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "abcabcbb";
    int n = strlen(str);

    int last_seen[256];
    for (int i = 0; i < 256; i++) {
        last_seen[i] = -1;
    }

    int max_length = 0;
    int start = 0;

    for (int i = 0; i < n; i++) {
        if (last_seen[str[i]] >= start) {
            start = last_seen[str[i]] + 1;
        }

        last_seen[str[i]] = i;

        int length = i - start + 1;
        if (length > max_length) {
            max_length = length;
        }
    }

    printf("Longest substring length = %d\n", max_length);

    return 0;
}