#include <stdio.h>
#include <string.h>

#define MAX_LEN 256

int main(void) {
    char input[MAX_LEN];

    while (1) {
        printf("Enter a string: ");
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break;
        }

        size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0';
            len--;
        }

        printf("Length of string: %zu\n", len);

        if (strcmp(input, "stop") == 0) {
            printf("Stopping.\n");
            break;
        }
    }

    return 0;
}