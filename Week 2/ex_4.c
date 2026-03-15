#include <stdio.h>

int read_integer(void) {
    int value;
    while (1) {
        if (scanf("%d", &value) == 1) {
            return value;
        }
        while (getchar() != '\n');
        printf("invalid input\n");
    }
}

int main(void) {
    int count = 0;
    double sum = 0.0;

    while (1) {
        printf("Enter positive numbers or negative to stop: ");
        int n = read_integer();
        if (n < 0) break;
        sum += n;
        count++;
    }

    if (count == 0) {
        printf("No numbers entered.\n");
    } else {
        printf("You entered %d positive numbers. The average is: %.3f\n", count, sum / count);
    }

    return 0;
}