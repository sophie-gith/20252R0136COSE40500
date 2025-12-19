#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define ABS(x) (((x) < (0)) ? (-(x)) : (x))

int main(void)
{
    int N;
    printf("Enter an integer: ");
    scanf("%d", &N);
    printf("Absolute = %d", ABS(N));
    return 0;
}