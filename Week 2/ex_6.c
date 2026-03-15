#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int main (void) {
    srand (time(NULL));
    int d6 = rand() % 6;
    int d10 = rand () %10;
    int choice = 0;
    int quit = false;
    while (quit != true) {
        printf("Choose your action;\n");
        printf("Roll a d6\n"
           "Roll a d10\n"
           "Quit\n");
        scanf("%d", &choice);
        if (choice == 3) {
            quit = true;
        }
        else if (choice == 1) {
            printf("your d6 landed on:&d6");
            choice = 0;
        }
        else if (choice == 2) {
            printf("your d10 landed on:&d10");
            choice = 0;
        }
    }
}
