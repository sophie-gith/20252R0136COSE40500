#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define CLIP(x, lo, hi) ( (((x) >= (lo)) && ((x) <= (hi))) ? (x) : ( ((x) < (lo)) ? (lo) : (hi) ) )

int main(void) 
{
    int val, min, max;
    printf("Enter value, min, and max: ");
    scanf("%d %d %d", &val, &min, &max);
    printf("Clipped = %d", CLIP(val, min, max));
    return 0;
}