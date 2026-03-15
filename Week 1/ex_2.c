#include <stdio.h>

#define MONTHS 12

int main(void) {
    double salaries[MONTHS];
    double taxes[MONTHS];

    double tax_rate, limit, high_tax_rate;

    printf("Enter tax rate: ");
    scanf("%lf", &tax_rate);
    printf("Enter income limit: ");
    scanf("%lf", &limit);
    printf("Enter tax rate for income over the limit: ");
    scanf("%lf", &high_tax_rate);

    for (int i = 0; i < MONTHS; i++) {
        printf("Enter income for month %d: ", i + 1);
        scanf("%lf", &salaries[i]);
    }

    double cumulative = 0.0;
    for (int i = 0; i < MONTHS; i++) {
        double prev = cumulative;
        cumulative += salaries[i];

        if (prev >= limit) {
            taxes[i] = salaries[i] * (high_tax_rate / 100.0);
        } else if (cumulative <= limit) {
            taxes[i] = salaries[i] * (tax_rate / 100.0);
        } else {
            double below = limit - prev;
            double above = salaries[i] - below;
            taxes[i] = below * (tax_rate / 100.0) + above * (high_tax_rate / 100.0);
        }
    }

    printf("\n%5s %10s %10s\n", "month", "income", "tax");
    for (int i = 0; i < MONTHS; i++) {
        printf("%5d %10.2f %10.2f\n", i + 1, salaries[i], taxes[i]);
    }

    return 0;
}