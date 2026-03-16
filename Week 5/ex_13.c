#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(void) {
    char filename[256];
    printf("enter filename: ");
    fgets(filename, sizeof(filename), stdin);
    size_t len = strlen(filename);
    if (len > 0 && filename[len - 1] == '\n') filename[len - 1] = '\0';

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: could not open teh file '%s'\n", filename);
        return EXIT_FAILURE;
    }

    int count = 0;
    int value;
    int min = INT_MAX;
    int max = INT_MIN;

    while (fscanf(file, "%d", &value) == 1) {
        count++;
        if (value < min) min = value;
        if (value > max) max = value;
    }

    fclose(file);

    if (count == 0) {
        printf("No integers found in file:(\n");
    } else {
        printf("Count: %d\n", count);
        printf("Lowest:  %d\n", min);
        printf("Highest: %d\n", max);
    }

    return 0;
}