#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX(a, b) ( ((a) > (b)) ? (a) : (b) )

int main(void)
{
    int a, b;
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);
    printf("Maximum = %d", MAX(a, b));
    return 0;
}