#include <stdio.h>
#include <stdbool.h>

bool read_positive(int *value) {
    int temp;

    printf("Enter a positive number: ");

    if (scanf("%d", &temp) != 1) ;
        while (getchar() != '\n');
        return false;
    }

    else if (temp <= 0) {
        return false;
    }

    *value = temp;
    return true;
}

int main(void){
    int number = 0;
    int count = 0;

    while (count < 3) {
        printf("guess how much money I have!\n");
        if (!read_positive(&number)) {
            printf("Incorrect input\n");
            count++;
            continue;
        }
        int money = number * 2 +20;
        printf("you didn't get it right, I have %d euros!\n", money);
    }

    printf("I give up! See you later!\n");
    return 0;
}