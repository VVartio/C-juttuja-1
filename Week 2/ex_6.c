#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void roll_d6(void) {
    int result = rand() % 6 + 1;
    printf("Your d6 landed on: %d\n", result);
}

void roll_d10(void) {
    int result = rand() % 10 + 1;
    printf("Your d10 landed on: %d\n", result);
}

int main(void) {
    srand(time(NULL));
    int choice = 0;

    while (true) {
        printf("\nChoose your action:\n");
        printf("1) Roll a D6\n");
        printf("2) Roll a D10\n");
        printf("3) Quit\n");

        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            printf("NO! bad input! Enter 1, 2, or 3.\n");
            continue;
        }

        if (choice == 1) {
            roll_d6();
        } else if (choice == 2) {
            roll_d10();
        } else if (choice == 3) {
            printf("Peace!\n");
            break;
        } else {
            printf("NO! bad input! Enter 1, 2, or 3.\n");
        }
    }

    return 0;
}