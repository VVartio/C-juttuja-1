#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINES 100
#define MAX_LINE_LEN 81

int main(void) {
    char filename[256];
    printf("enter filename: ");
    fgets(filename, sizeof(filename), stdin);
    size_t len = strlen(filename);
    if (len > 0 && filename[len - 1] == '\n') filename[len - 1] = '\0';

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: could not open the file(sad) '%s'\n", filename);
        return EXIT_FAILURE;
    }

    char lines[MAX_LINES][MAX_LINE_LEN];
    int line_count = 0;

    while (line_count < MAX_LINES &&
           fgets(lines[line_count], MAX_LINE_LEN, file) != NULL) {
        line_count++;
           }
    fclose(file);

    for (int i = 0; i < line_count; i++) {
        for (int j = 0; lines[i][j] != '\0'; j++) {
            lines[i][j] = (char)toupper((unsigned char)lines[i][j]);
        }
    }

    file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "Error: could not open file '%s' for writing\n", filename);
        return EXIT_FAILURE;
    }

    for (int i = 0; i < line_count; i++) {
        fputs(lines[i], file);
    }
    fclose(file);

    printf("done. %d lines converted to uppercase and written to '%s'.\n",
           line_count, filename);
    return 0;
}