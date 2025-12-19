#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

unsigned long long fact_calc(int x)
{
    if (x <= 1)
        return 1;
    else
        return x * fact_calc(x - 1);
}

int main(void)
{
    int n;
    printf("Enter an integer: ");
    scanf("%d", &n);

    printf("Factorial = %llu", fact_calc(n));
    return 0;
}