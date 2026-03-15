#include <stdio.h>

int read_range(int low, int high) {
    while (1) {
        int value;
        printf("Enter a number between %d and %d: ", low, high);
        if (scanf("%d", &value) != 1) {
            while (getchar() != '\n');
            printf("Invalid input! Please enter a number.\n");
            continue;
        }
        if (value < low || value > high) {
            printf("Number must be between %d and %d!\n", low, high);
            continue;
        }
        return value;
    }
}

int main(void) {
    printf("Let's play!\n");

    for (int round = 0; round < 3; round++) {
        printf("Roll a die and enter your result.\n");
        int user_roll = read_range(1, 6);

        if (user_roll == 6) {
            printf("I got 6. It is a tie!\n");
        } else {
            printf("I got %d. I win!\n", user_roll + 1);
        }
    }

    printf("Better luck next time. Bye!\n");
    return 0;
}