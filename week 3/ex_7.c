#include <stdio.h>
#include <stdbool.h>

bool read_positive(int *value) {
    int temp;
    if (scanf("%d", &temp) != 1) {
        while (getchar() != '\n');
        return false;
    }
    if (temp <= 0) {
        return false;
    }
    *value = temp;
    return true;
}

int main(void) {
    int failures = 0;

    while (failures < 3) {
        printf("Guess how much money I have!\n");
        printf("Enter a positive number: ");

        int guess = 0;
        if (!read_positive(&guess)) {
            printf("Incorrect input\n");
            failures++;
            continue;
        }

        int amount = guess * 2 + 20;
        printf("You didn't get it right. I have %d euros.\n", amount);
    }

    printf("I give up! See you later!\n");
    return 0;
}