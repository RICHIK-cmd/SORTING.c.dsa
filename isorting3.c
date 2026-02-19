#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int marks;
};

int main() {
    int n;

    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student s[n];

    // Taking input
    for(int i = 0; i < n; i++) {
        printf("\nStudent %d\n", i + 1);
        printf("Name: ");
        scanf("%s", s[i].name);
        printf("Marks: ");
        scanf("%d", &s[i].marks);
    }

    // Insertion Sort
    for(int i = 1; i < n; i++) {
        struct Student key = s[i];   // Store current student
        int j = i - 1;

        // Sort by marks (ascending)
        // If marks equal, then sort by name alphabetically
        while(j >= 0 && 
             (s[j].marks > key.marks || 
             (s[j].marks == key.marks && strcmp(s[j].name, key.name) > 0))) {
            
            s[j + 1] = s[j];   // Shift element to right
            j--;
        }

        s[j + 1] = key;   // Place key at correct position
    }

    // Display sorted list
    printf("\nSorted List:\n");
    for(int i = 0; i < n; i++) {
        printf("%s - %d\n", s[i].name, s[i].marks);
    }

    return 0;
}
