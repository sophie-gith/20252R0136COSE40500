#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int digit_sum(int x)
{
    if (x <= 0)
        return 0;
    else
        return (x % 10) + digit_sum(x / 10);
}

int main(void)
{
    int n;
    printf("Enter an integer: ");
    scanf("%d", &n);

    if (n < 0)
        n = -n;

    printf("Sum of digits = %d", digit_sum(n));
    return 0;
}