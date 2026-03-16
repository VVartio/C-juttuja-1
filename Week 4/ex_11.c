#include <stdio.h>
#include <string.h>

int replace_char(char *str, const char *repl) {
    if (strlen(repl) != 2) {
        return 0;
    }

    char find = repl[0];
    char replacement = repl[1];
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == find) {
            str[i] = replacement;
            count++;
        }
    }

    return count;
}

int main(void) {
    char text[256];
    char repl[16];

    printf("Enter the string to modify: ");
    fgets(text, sizeof(text), stdin);
    size_t len = strlen(text);
    if (len > 0 && text[len - 1] == '\n') text[len - 1] = '\0';

    printf("Enter two characters (find then replace): ");
    fgets(repl, sizeof(repl), stdin);
    len = strlen(repl);
    if (len > 0 && repl[len - 1] == '\n') repl[len - 1] = '\0';

    int count = replace_char(text, repl);

    if (count > 0) {
        printf("Replaced %d character(s). Modified string: %s\n", count, text);
    } else {
        printf("String was not modified\n");
    }

    return 0;
}