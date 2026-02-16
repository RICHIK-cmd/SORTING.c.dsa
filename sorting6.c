#include <stdio.h>

struct student {
    int roll;
    char name[20];
    float marks;
};

int main() {
    struct student s[50], temp;
    int n, i, j;

    // Taking number of students
    printf("Enter number of students: ");
    scanf("%d", &n);

    // Taking student details
    for (i = 0; i < n; i++) {
        printf("\nEnter details of student %d\n", i + 1);
        printf("Roll: ");
        scanf("%d", &s[i].roll);
        printf("Name: ");
        scanf("%s", s[i].name);
        printf("Marks: ");
        scanf("%f", &s[i].marks);
    }

    // Bubble Sort based on marks
    for (i = 0; i < n - 1; i++) {
        // Last i students are already sorted
        for (j = 0; j < n - i - 1; j++) {
            // Compare marks of adjacent students
            if (s[j].marks > s[j + 1].marks) {
                // Swap entire structure
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }

    // Printing sorted student list
    printf("\nStudents sorted by marks:\n");
    printf("Roll\tName\tMarks\n");

    for (i = 0; i < n; i++) {
        printf("%d\t%s\t%.2f\n", s[i].roll, s[i].name, s[i].marks);
    }

    return 0;
}
