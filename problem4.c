#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SWAP(x, y, temp) {(temp) = (x);\
                                   (x) = (y);\
                                   (y) = (temp);}

int main(void)
{
    int a, b, temp;
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    SWAP(a, b, temp);

    printf("Swapped = %d %d", a, b);
    return 0;
}