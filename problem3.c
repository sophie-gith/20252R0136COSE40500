#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

long long get_power(int b, int e)
{
    if (e <= 0)
        return 1;
    else
        return (long long)b * get_power(b, e - 1);
}

int main(void)
{
    int base, exp;
    printf("Enter base and exponent: ");
    scanf("%d %d", &base, &exp);

    printf("Result = %lld", get_power(base, exp));
    return 0;
}