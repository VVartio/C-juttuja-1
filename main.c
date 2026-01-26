#include <stdio.h>

int moving(int bus, int taxi, int money);

int main(void) {
    int bus = 0;
    int taxi = 0;
    int money = 0;
    printf("Enter price on bus ticket: ");
    scanf("%d", &bus);
    printf("enter price of taxi: ");
    scanf("%d", &taxi);
    printf("Enter your amount of money: ");
    scanf("%d", &money);

    moving(bus, taxi, money);
    return 0;
}
int moving(int bus, int taxi, int money) {
    int choice = 0;
    do {
        printf("You have %d\n", money);
        printf("do you want to take the taxi(1) or the bus(2)");
        scanf("%d", &choice);
        if (choice == 1 && money >= taxi) {
            money -= taxi;
            printf (" you have %d dolors left", money);
        }
        else if (choice == 2 && money >= bus) {
            money -= bus;
            printf (" you have %d dolors left", money);
        }
        else {
            printf("Not enough money!\n");
            printf("Time to start walking buddy ol' pal\n");
        }
    }
    while (bus <= money && taxi <= money);
}

