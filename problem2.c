#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int get_gcd(int x, int y)
{
    if (y == 0)
        return x;
    else
        return get_gcd(y, x % y);
}

int main(void)
{
    int a, b;
    printf("Enter two integers (large, small): ");
    scanf("%d %d", &a, &b);

    printf("GCD = %d", get_gcd(a, b));
    return 0;
}