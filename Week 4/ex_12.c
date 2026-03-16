#include <stdio.h>
#include <string.h>

int count_words(const char *str, const char *word) {
    int count = 0;
    size_t word_len = strlen(word);
    if (word_len == 0) return 0;

    const char *pos = str;
    while ((pos = strstr(pos, word)) != NULL) {
        count++;
        pos += word_len;
    }
    return count;
}

int main(void) {
    char str[256];
    char word[256];

    while (1) {
        printf("Enter a string: ");
        fgets(str, sizeof(str), stdin);
        size_t len = strlen(str);
        if (len > 0 && str[len - 1] == '\n') str[len - 1] = '\0';

        printf("Enter a word: ");
        fgets(word, sizeof(word), stdin);
        len = strlen(word);
        if (len > 0 && word[len - 1] == '\n') word[len - 1] = '\0';

        if (strcmp(word, "stop") == 0) {
            printf("Stopping.\n");
            break;
        }

        int count = count_words(str, word);
        printf("\"%s\" appears %d time(s) in the string.\n", word, count);
    }

    return 0;
}