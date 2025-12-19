/*9-1
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int minimum(int arr[], int N)
{
    int min = arr[0];
    for (int i = 1; i < N; i++)
        if (min > arr[i]) min = arr[i];
    return min;
}

int main(void)
{
    int N, arr[100];
    printf("Enter number of elements: ");
    scanf("%d", &N);
    printf("Enter %d integers: ", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    printf("\nMinimum value = %d", minimum(arr, N));
    return 0;
}
*/

/*9-2
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int compare_arrays(int a[], int b[], int n)
{
    for (int i = 0; i < n; i++)
        if (a[i] != b[i]) return 0;
    return 1;
}

int main(void)
{
    int N, a[100], b[100];
    printf("Enter number of elements: ");
    scanf("%d", &N);
    printf("Enter first array: ");
    for (int i = 0; i < N; i++)
        scanf("%d", &a[i]);
    printf("Enter second array: ");
    for (int i = 0; i < N; i++)
        scanf("%d", &b[i]);

    if (compare_arrays(a, b, N) == 1)
        printf("\nArrays are identical");
    else
        printf("\nArrays are different");

    return 0;
}
*/

/*9-3
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void count_even_odd(int arr[], int N, int* even, int* odd)
{
    for (int i = 0; i < N; i++)
    {
        if (arr[i] % 2 == 0)
            *even += 1;
        else
            *odd += 1;
    }
}

int main(void)
{
    int N, arr[100];
    printf("Enter number of elements: ");
    scanf("%d", &N);

    printf("Enter %d integers: ", N);
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    int even = 0;
    int odd = 0;
    count_even_odd(arr, N, &even, &odd);
    printf("\nEven numbers = %d", even);
    printf("\nOdd numbers = %d", odd);

    return 0;
}
*/

/*9-4
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

reverse_array(int arr[], int N)
{
    int temp;
    for (int i = 0; i <= N / 2; i++)
    {
        temp = arr[i];
        arr[i] = arr[N - 1 - i];
        arr[N - 1 - i] = temp;
    }
}

int main(void)
{
    int N, arr[100];
    printf("Enter number of elements: ");
    scanf("%d", &N);
    printf("Enter 5 integers: ");
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    printf("\nOriginal array: ");
    for (int i = 0; i < N; i++)
        printf("%d ", arr[i]);

    reverse_array(arr, N);

    printf("\nReversed array: ");
    for (int i = 0; i < N; i++)
        printf("%d ", arr[i]);

    return 0;
}
*/

/*9-5
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void xor_encrypt(const char plain[], unsigned int key, unsigned char enc[])
{
    int i;
    for (i = 0; plain[i] != '\0'; i++)
    {
        unsigned char c_key = (key >> (8 * (i % 4))) & 0xFF;
        enc[i] = ((unsigned char)plain[i]) ^ c_key;
    }
    enc[i] = '\0';
}

int main(void)
{
    char plain[101];
    printf("Enter plaintext (max 100 chars): ");
    scanf(" %100[^\n]", plain);

    unsigned int key;
    printf("Enter 32-bit key (unsigned integer): ");
    scanf("%u", &key);

    unsigned char enc[101];
    xor_encrypt(plain, key, enc);

    printf("\nEncrypted (hex): ");
    for (int i = 0; enc[i] != '\0'; i++)
        printf("%02X ", enc[i]);

    return 0;
}
*/

/*9-6
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void xor_decrypt(const unsigned char arr[], unsigned int key, int N, char dec[])
{
    int i = 0;
    for (i = 0; i < N; i++)
    {
        unsigned char k_byte = (key >> (8 * (i % 4))) & 0xFF;
        dec[i] = arr[i] ^ k_byte;
    }
    dec[i] = '\0';
}

int main(void)
{
    int N;
    unsigned char arr[101];
    char dec[101];
    unsigned int key;

    printf("Enter number of bytes: ");
    scanf("%d", &N);

    printf("Enter %d hex values (e.g., 3A FF 2C ...): ", N);
    for (int i = 0; i < N; i++)
    {
        unsigned int temp;
        scanf("%x", &temp);
        arr[i] = (unsigned char)(temp);
    }

    printf("Enter 32-bit key (unsigned integer): ");
    scanf("%u", &key);

    xor_decrypt(arr, key, N, dec);

    printf("\nDecrypted text: %s", dec);
    return 0;
}
*/


/*10-1
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main(void)
{
    int a, b;
    printf("Enter a and b: ");
    scanf("%d %d", &a, &b);
    if (a < b) swap(&a, &b);
    printf("GCD = %d", gcd(a, b));
    return 0;
}
*/

/*10-2
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int sum_array(int* p, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += *(p + i);
    return sum;
}

int main(void)
{
    int N;
    int arr[100];

    printf("Enter number of elements: ");
    scanf("%d", &N);

    printf("Enter %d integers: ", N);
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    printf("Sum = %d", sum_array(arr, N));
    return  0;
}
*/

/*10-3
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int count_even(int* p, int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
        if (*(p + i) % 2 == 0) count++;
    return count;
}

int main(void)
{
    int N, arr[100];
    printf("Enter number of elements: ");
    scanf("%d", &N);

    printf("Enter %d integers: ", N);
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    printf("Even count = %d", count_even(arr, N));
    return 0;
}
*/

/*10-4
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int reverse(int* p, int n)
{
    int temp;
    for (int i = 0; i <= n / 2; i++)
    {
        temp = *(p + i);
        *(p + i) = *(p + n - 1 - i);
        *(p + n - 1 - i) = temp;
    }
}

int main(void)
{
    int N, arr[100];
    printf("Enter number of elements: ");
    scanf("%d", &N);

    printf("Enter %d integers: ", N);
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    reverse(arr, N);
    printf("Reversed array: ");
    for (int i = 0; i < N; i++)
        printf("%d ", arr[i]);
    return 0;
}
*/

/*10-5
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void swap_arrays(int* a, int* b, int n)
{
    int temp;
    for (int i = 0; i < n; i++)
    {
        temp = *(a + i);
        *(a + i) = *(b + i);
        *(b + i) = temp;
    }
}

int main(void)
{
    int N, a[100], b[100];
    printf("Enter number of elements: ");
    scanf("%d", &N);

    printf("Enter %d integers for A: ", N);
    for (int i = 0; i < N; i++)
        scanf("%d", &a[i]);
    printf("Enter %d integers for B: ", N);
    for (int i = 0; i < N; i++)
        scanf("%d", &b[i]);

    swap_arrays(a, b, N);

    printf("\nAfter swap: ");
    printf("\nA: ");
    for (int i = 0; i < N; i++)
        printf("%d ", a[i]);
    printf("\nB: ");
    for (int i = 0; i < N; i++)
        printf("%d ", b[i]);

    return 0;
}
*/

/*10-6
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int* find_max(int* p, int n)
{
    int* max = p;
    for (int i = 1; i < n; i++)
        if (*(p + i) > *max) max = (p + i);
    return max;
}

int main(void)
{
    int N, arr[100];
    printf("Enter number of elements: ");
    scanf("%d", &N);
    printf("Enter %d integers: ", N);
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    printf("Maximum value = %d", *(find_max(arr, N)));
    return 0;
}
*/

/*11-1
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

size_t my_strlen(const char* s)
{
    size_t len = 0;
    while (s[len] != '\0') len++;
    return len;
}

int main(void)
{
    char arr[1001];
    printf("Enter a string: ");
    scanf(" %[^\n]", arr);
    printf("Length = %zu", my_strlen(arr));
    return 0;
}
*/

/*11-2
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char* my_strcpy(char* dst, const char* src)
{
    int i;
    for (i = 0; src[i] != '\0'; i++)
        dst[i] = src[i];
    dst[i] = '\0';
    return dst;
}

int main(void)
{
    char line[1001];
    char copy_line[1001];
    printf("Enter a string: ");
    scanf(" %[^\n]", line);
    printf("Copied: %s", my_strcpy(copy_line, line));
    return 0;
}
*/

/*11-3
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void split_and_print(const char* s, char delim)
{
    int start = 0;
    int end = 0;

    while (s[end] != '\0')
    {
        while (s[end] != delim && s[end] != '\0')
            end++;

        for (int i = start; i < end; i++)
            printf("%c", s[i]);  //putchar(s[i]);

        if (s[end] == delim)
        {
            if ( end > start ) printf("\n");
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
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char enc_char(char c, int k)
{
    k %= 26;

    if ('a' <= c && 'z' >= c)
    {
        int x = (c - 'a' + k + 26) % 26;
        return 'a' + x;
    }
    else if ('A' <= c && 'Z' >= c)
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
    char line[1001];
    printf("Enter shift: ");
    scanf("%d", &k);
    printf("Enter text: ");
    scanf(" %[^\n]", line);

    printf("Cipher: ");
    int count = 0;
    while (line[count] != '\0')
    {
        printf("%c", enc_char(line[count], k));
        count++;
    }
    return 0;
}
*/

/*11-5
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

unsigned long long mod_pow(unsigned long long base, unsigned long long exp, unsigned long long mod)
{
    unsigned long long result = 1;
    base %= mod;

    while (exp != 0)
    {
        if (exp & 1 == 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }

    return result;
}

int main(void)
{
    unsigned long long e, n;
    int T;
    unsigned long long message[1001];

    printf("Enter public key (e n): ");
    scanf("%llu %llu", &e, &n);

    printf("Enter number of messages: ");
    scanf("%d", &T);

    printf("Enter messages: ");
    for (int i = 0; i < T; i++)
        scanf("%llu", &message[i]);

    for (int i = 0; i < T; i++)
        printf("%llu ", mod_pow(message[i], e, n));
    return 0;
}
*/

/*11-6
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

unsigned long long mod_pow(unsigned long long base, unsigned long long exp, unsigned long long mod)
{
    unsigned long long result = 1;
    base %= mod;

    while (exp != 0)
    {
        if (exp & 1 == 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }

    return result;
}

int main(void)
{
    unsigned long long d, n;
    int T;
    unsigned long long ciphers[1001];

    printf("Enter private key (d n): ");
    scanf("%lld %lld", &d, &n);

    printf("Enter number of ciphertexts: ");
    scanf("%d", &T);

    printf("Enter ciphertexts: ");
    for (int i = 0; i < T; i++)
        scanf("%llu", &ciphers[i]);

    for (int i = 0; i < T; i++)
        printf("%llu ", mod_pow(ciphers[i], d, n));
    return 0;
}
*/

/*12-1
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

#define PI acos(-1.0)

struct Point
{
    double x;
    double y;
};

struct Circle
{
    struct Point center;
    double r;
};

double get_area(struct Circle c)
{
    return PI * c.r * c.r;
}
double get_circumference(struct Circle c)
{
    return 2 * PI * c.r;
}

int main(void)
{
    struct Circle C;
    printf("Enter x, y, and radius: ");
    scanf("%lf %lf %lf", &C.center.x, &C.center.y, &C.r);

    printf("Area = %.2lf", get_area(C));
    printf("\nCircumference = %.2lf", get_circumference(C));
    return 0;
}
*/

/*12-2

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

struct Point
{
    double x;
    double y;
};

double get_area(struct Point a, struct Point b, struct Point c)
{
    double da = sqrt((b.x - c.x) * (b.x - c.x) + (b.y - c.y) * (b.y - c.y));
    double db = sqrt((a.x - c.x) * (a.x - c.x) + (a.y - c.y) * (a.y - c.y));
    double dc = sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
    double s = (da + db + dc) / 2;
    return sqrt(s * (s - da) * (s - db) * (s - dc));
}

int main(void)
{
    struct Point p1, p2, p3;
    printf("Enter coordinates (x1 y1 x2 y2 x3 y3): ");
    scanf("%lf %lf %lf %lf %lf %lf", &p1.x, &p1.y, &p2.x, &p2.y, &p3.x, &p3.y);
    printf("Area = %.2lf", get_area(p1, p2, p3));
    return 0;
}
*/

/*12-3
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }
int divide(int a, int b) { return a / b; }

int main(void)
{
    int (*ops[4])(int, int) = { add, sub, mul, divide };
    // or ops[0] = add; ops[1] = sub; ops[2] = mul; ops[3] = divide;

    int a, b, op;
    printf("Enter two integers and operation (1:add 2:sub 3:mul 4:div): ");
    scanf("%d %d %d", &a, &b, &op);
    printf("Result = %d", ops[op - 1](a, b));
    return 0;
}
*/

/*12-4
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int type;
    printf("Enter type (1:int 2:float): ");
    scanf("%d", &type);

    void* ptr;

    if (type == 1)
    {
        int val;
        printf("Enter integer value: ");
        scanf("%d", &val);
        ptr = &val;
    }

    else
    {
        float val;
        printf("Enter float value: ");
        scanf("%f", &val);
        ptr = &val;
    }

    printf("Byte representation: ");
    unsigned char* p = (unsigned char*)ptr;
    int size = (type == 1) ? sizeof(int) : sizeof(float);

    for (int i = 0; i < size; i++)
        printf("%02X ", p[i]);
    return 0;
}
*/

/*12-5
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void add_matrix(int A[3][3], int B[3][3], int C[3][3])
{
    for (int r = 0; r < 3; r++)
        for (int c = 0; c < 3; c++)
            C[r][c] = A[r][c] + B[r][c];
}

int main(void)
{
    int A[3][3], B[3][3], C[3][3];

    printf("Enter matrix A (3x3): \n");
    for (int r = 0; r < 3; r++)
        scanf("%d %d %d", &A[r][0], &A[r][1], &A[r][2]);

    printf("Enter matrix B (3x3): \n");
    for (int r = 0; r < 3; r++)
        scanf("%d %d %d", &B[r][0], &B[r][1], &B[r][2]);

    add_matrix(A, B, C);

    printf("Matrix C: \n");
    for (int r = 0; r < 3; r++)
    {
        for (int c = 0; c < 3; c++)
            printf("C[%d][%d] =%d ", r, c, C[r][c]);
        printf("\n");
    }
    return 0;
}
*/

/*12-6
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    if (argc == 1) return 0;

    int sum = 0;
    double average;

    for (int i = 1; i < argc; i++)
        sum += atoi(argv[i]);

    average = (double)sum / (double)(argc - 1);

    printf("Sum = %d\n", sum);
    printf("Mean = %.2f", average);
    
    return 0;
}
*/