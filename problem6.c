#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int R, C;
	printf("Enter number of rows and columns: ");
	scanf("%d %d", &R, &C);


	int** arr = (int**)malloc(R * sizeof(int*));
	if (arr == NULL) exit(1);

	for (int i = 0; i < R; i++)
	{
		arr[i] = (int*)malloc(C * sizeof(int));
		if (arr[i] == NULL) exit(1);
	}

	printf("Enter elements: ");
	for (int r = 0; r < R; r++)
		for (int c = 0; c < C; c++)
			scanf("%d", &arr[r][c]);

	int sum = 0;
	for (int r = 0; r < R; r++)
		for (int c = 0; c < C; c++)
			sum += arr[r][c];
	printf("Sum = %d", sum);

	for (int r = 0; r < R; r++)
			free(arr[r]);
	free(arr);
	return 0;
}