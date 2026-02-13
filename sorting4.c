#include <stdio.h>
#include <string.h>

// Structure to store student details
struct Student {
    char name[50];
    int marks;
};

void bubbleSort(struct Student s[], int n) {
    int i, j;
    struct Student temp;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {

            // Compare marks
            if (s[j].marks > s[j + 1].marks) {

                // Swap entire structure
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n, i;

    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student s[n];

    // Input student details
    for (i = 0; i < n; i++) {
        printf("\nStudent %d Name: ", i + 1);
        scanf("%s", s[i].name);

        printf("Student %d Marks: ", i + 1);
        scanf("%d", &s[i].marks);
    }

    // Sort students based on marks
    bubbleSort(s, n);

    // Display sorted list
    printf("\nStudents sorted by marks (Ascending):\n");
    for (i = 0; i < n; i++) {
        printf("%s - %d\n", s[i].name, s[i].marks);
    }

    return 0;
}
