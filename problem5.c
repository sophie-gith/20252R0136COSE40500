#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int N;
    printf("Enter number of elements: ");
    scanf("%d", &N);

    int* arr = (int*)malloc(N * sizeof(int));
    if (arr == NULL) exit(1);
    printf("Enter elements: ");
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    int sum = 0;
    for (int i = 0; i < N; i++)
        sum += arr[i];
    printf("Sum = %d", sum);

    free(arr);
    return 0;
}