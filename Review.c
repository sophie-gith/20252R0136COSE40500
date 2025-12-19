#define _CRT_SECURE_NO_WARNINGS

/*14-4
#include <stdio.h>

#define SWAP(x, y, temp) { (temp) = (x); (x) = (y); (y) = (temp); }

int main(void)
{
	int x, y;
	printf("Enter two integers: ");
	scanf("%d %d", &x, &y);

	int temp;
	SWAP(x, y, temp);

	printf("Swapped = %d %d", x, y);

	return 0;
}
*/

/*14-6
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int R, C;
	printf("Enter number of rows and columns: ");
	scanf("%d %d", &R, &C);

	int** p = (int**)malloc(sizeof(int*) * R);
	if (p == NULL) return 0;

	for (int i = 0; i < R; i++)
	{
		p[i] = (int*)malloc(sizeof(int) * C);
		if (p[i] == NULL) return 0;
	}

	int sum = 0;
	printf("Enter elements: ");
	for (int r = 0; r < R; r++)
	{
		for (int c = 0; c < C; c++)
		{
			scanf("%d", &p[r][c]);
			sum += p[r][c];
		}
	}

	printf("Sum = %d", sum);

	for (int r = 0; r < R; r++)
		free(p[r]);
	free(p);

	return 0;
}
*/

/*13-4
#include <stdio.h>

int main(void)
{
	FILE* fp = fopen("numbers.bin", "rb");
	if (fp == NULL) return 0;

	int num;
	int sum = 0;
	while (fread(&num, sizeof(int), 1, fp) == 1)
		sum += num;

	printf("Sum = %d", sum);


	fclose(fp);
	return 0;
}
*/

/*13-6

#include <stdio.h>
long long mod_pow(long long base, long long exp, long long mod)
{
	long long result = 1;
	base %= mod;

	while (exp != 0)
	{
		if (exp & 1 == 1)
			result = (result * base) % mod;

		base = (base * base) %  mod;
		exp /= 2;
	}
	return result;
}

int main(void)
{
	const long long N = 100160063;   // modulus
	const long long D = 94249457;    // private exponent

	long long C1, C2;
	printf("Enter C1 and C2: ");
	scanf("%lld %lld", &C1, &C2);

	long long year = mod_pow(C1, D, N);
	long long serial = mod_pow(C2, D, N);

	printf("Student ID = %04lld%06lld", year, serial);
	return 0;
}
*/

/*
FILE* fp = fread("text.txt", "r");
fscanf(fp, "text");

FILE* fp = fread("text.txt", "w");
fprintf(fp, "%d", &num);

FILE* fp = fread("test.bin", "rb");
fread(&buf, sizeof(int), N, fp);

FILE* fp = fread("test.bin", "wb");
fwrite(arr, sizeof(int), N, fp);

*/

/*12-3

#include <stdio.h>

int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }
int divide(int a, int b) { return a / b; }

int main(void)
{
	int a, b, op;
	printf("Enter two integers and operation (1:add 2:sub 3:mul 4:div): ");
	scanf("%d %d %d", &a, &b, &op);

	int (*p[4])(int, int) = { add, sub, mul, divide };

	printf("Result = %d", p[op - 1](a, b));
	return 0;
}
*/

/*12-4

#include <stdio.h>

int main(void)
{
	int type;
	printf("Enter type (1:int 2:float): ");
	scanf("%d", &type);

	void* pt;

	if (type == 1)
	{
		int val;
		printf("Enter integer value: ");
		scanf("%d", &val);
		pt = &val;
	}

	else
	{
		float val;
		printf("Enter float value: ");
		scanf("%f", &val);
		pt = &val;
	}

	unsigned char* p = (unsigned char*)pt;
	int size = (type == 1) ? sizeof(int) : sizeof(float);

	printf("Byte representation: ");
	for (int i = 0; i < size; i++)
		printf("%02X ", *(p + i));

	return 0;
}
*/

/*12-6

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	if (argc == 1) return 0;

	int sum = 0;

	for (int i = 1; i < argc; i++)
		sum += atoi(argv[i]);

	printf("Sum = %d", sum);
	printf("\nMean = %lf", (double)sum / (argc-1));
	return 0;
}
*/

/*11-2
#include <stdio.h>

char* my_strcpy(char* dst, const char* src)
{
	int i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	
	return dst;
}


int main(void)
{
	char arr[1001];
	printf("Enter a string: ");
	scanf(" %1000[^\n]", arr);

	char cop[1001];
	my_strcpy(cop, arr);
	printf("Copied: %s", cop);
	
	return 0;
}
*/

/*12-3

#include <stdio.h>

void split_and_print(const char* s, char delim)
{
	int start = 0;
	int end = 0;
	while (s[end] != '\0')
	{
		while (s[end] != '\0' && s[end] != delim)
			end++;

		for (int i = start; i < end; i++)
			printf("%c", s[i]);


		if (s[end] == delim)
		{
			if (end - start > 1)
				printf("\n");
			start = ++end;
		}
	}
}

int main(void)
{
	char delim;
	char line[1001];
	printf("Delimiter: ");
	scanf("%c", &delim);

	printf("Input: ");
	scanf(" %1000[^\n]", line);

	split_and_print(line, delim);
	return 0;
}
*/

/*11-4

#include <stdio.h>

char enc_char(char c, int k)
{
	k %= 26;
	if (c >= 'a' && c <= 'z')
	{
		int x = (c - 'a' + k + 26) % 26;
		return 'a' + x;
	}
	else if (c >= 'A' && c <= 'Z')
	{
		int x = (c - 'A' + k + 26) % 26;
		return 'A' + x;
	}
	else
		return c;
}

int main(void)
{
	int k; 
	char text[1001];
	printf("Enter shift: ");
	scanf("%d", &k);
	printf("Enter text: ");
	scanf(" %1000[^\n]", text);

	printf("Cipher: ");
	for (int i = 0; text[i] != '\0'; i++)
		printf("%c", enc_char(text[i], k));
	return 0;
}
*/

/*9-5

#include <stdio.h>

void xor_encrypt(const char line[], unsigned int key, unsigned char enc[])
{
	int i;
	for (i = 0; line[i] != '\0'; i++)
	{
		unsigned char k_byte = (key >> (8 * (i % 4))) & 0xFF;
		enc[i] = k_byte ^ (unsigned char)line[i];
	}
	enc[i] = '\0';
}

int main(void)
{
	char line[101];
	unsigned int key;
	printf("Enter plaintext (max 100 chars): ");
	scanf(" %[^\n]", line);
	printf("Enter 32-bit key (unsigned integer): ");
	scanf("%u", &key);

	unsigned char enc[101];
	xor_encrypt(line, key, enc);

	printf("Encrypted (hex): ");
	for (int i = 0; enc[i] != '\0'; i++)
		printf("%02X ", enc[i]);
	return 0;
}
*/

/*9-6*/
#include <stdio.h>

void xor_decrypt(unsigned char enc[], int N, unsigned int key, char dec[])
{
	for (int i = 0; i < N; i++)
	{
		unsigned char k_byte = (key >> (8 * (i % 4))) & 0xFF;
		dec[i] = enc[i] ^ k_byte;
	}
	dec[N] = '\0';
}

int main(void)
{
	int N;
	printf("Enter number of bytes: ");
	scanf("%d", &N);

	unsigned char enc[101];
	printf("Enter %d hex values (e.g., 3A FF 2C ...): ", N);
	for (int i = 0; i < N; i++)
	{
		unsigned int temp;
		scanf("%x", &temp);
		enc[i] = (unsigned char)temp;
	}

	unsigned int key;
	printf("Enter 32-bit key (unsigned integer): ");
	scanf("%u", &key);

	char dec[101];
	xor_decrypt(enc, N, key, dec);

	printf("\nDecrypted text: %s", dec);
	return 0;
}