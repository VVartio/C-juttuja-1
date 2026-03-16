#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int find_first(const unsigned int *array, unsigned int what) {
    int i = 0;
    while (array[i] != 0) {
        if (array[i] == what) {
            return i;
        }
        i++;
    }
    return -1;
}

int main(void) {
    srand(time(NULL));

    unsigned int numbers[20];
    for (int i = 0; i < 19; i++) {
        numbers[i] = (unsigned int)(rand() % 20 + 1); // range 1-20
    }
    numbers[19] = 0; // sentinel

    printf("Array contents:\n");
    for (int i = 0; i < 20; i++) {
        printf("%u\n", numbers[i]);
    }

    while (1) {
        printf("\nEnter number to search for or 0 to stop: ");
        unsigned int target;
        if (scanf("%u", &target) != 1) {
            while (getchar() != '\n');
            printf("Invalid input!\n");
            continue;
        }
        if (target == 0) break;

        int idx = find_first(numbers, target);
        if (idx == -1) {
            printf("not found\n");
        } else {
            printf("Found at index %d\n", idx);
        }
    }

    return 0;
}