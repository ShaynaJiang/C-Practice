#include <stdio.h>
#include <math.h>
int nCr(int n, int r) {
    if (r == 0 || r == n) {
        return 1;
    } else {
        return nCr(n - 1, r - 1) + nCr(n - 1, r);
    }
}

void printAA(int a, int b, int n) {
   printf("(%d+%d)^%d=", a, b, n);
    int i;
    for ( i = n; i >= 0; i--) {
        int c = nCr(n, i);
        int term = c * pow(a, i) * pow(b, n - i);

        if (c != 1) {
            printf("%d*", c);
        }
        if (i > 0) {
            printf("%d^%d*", a, i);
        }
        if (n - i > 0) {
            printf("%d^%d", b, n - i);
        }

        if (i != 0) {
            printf("+");
        }
    }
}

int main() {
    int a, b, n;
    printf("Please input the value of a:");
    scanf("%d", &a);
    printf("Please input the value of b:");
    scanf("%d", &b);
    printf("Please input the value of n:");
    scanf("%d", &n);	

    if (n <= 0 || a<=0 || b<=0) {

	printf("Input erro");
	return 1;
}

    printAA(a, b, n);

    int result;
    result = pow(a + b, n);
    printf("=%d\n", result);

    return 0;
}

