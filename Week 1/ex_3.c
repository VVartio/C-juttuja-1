#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    printf("How many students: ");
    scanf("%d", &n);

    int *grades = malloc(n * sizeof(int));
    if (!grades) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        grades[i] = -1;
    }

    while (1) {
        int student;
        printf("Enter student number (1 - %d) or 0 to stop: ", n);
        if (scanf("%d", &student) != 1) {
            while (getchar() != '\n');
            printf("Invalid input!\n");
            continue;
        }

        if (student == 0) break;

        if (student < 1 || student > n) {
            printf("Invalid student number!\n");
            continue;
        }

        int grade;
        printf("Enter grade (0 - 5) for student %d or -1 to cancel: ", student);
        while (1) {
            if (scanf("%d", &grade) != 1) {
                while (getchar() != '\n');
                printf("Invalid input!\n");
                printf("Enter grade (0 - 5) for student %d or -1 to cancel: ", student);
                continue;
            }
            if (grade == -1) break;
            if (grade >= 0 && grade <= 5) break;
            printf("Invalid grade!\n");
            printf("Enter grade (0 - 5) for student %d or -1 to cancel: ", student);
        }

        if (grade != -1) {
            grades[student - 1] = grade;
        }
    }

    printf("\n%-10s %s\n", "Student", "Grade");
    for (int i = 0; i < n; i++) {
        if (grades[i] == -1) {
            printf("%-10d N/A\n", i + 1);
        } else {
            printf("%-10d %d\n", i + 1, grades[i]);
        }
    }

    free(grades);
    return 0;
}