#include <stdio.h>
#include <math.h>
int nCr(int n, int r) {
    if (r == 0 || r == n) {
        return 1;
    } else {
        return nCr(n - 1, r - 1) + nCr(n - 1, r);
    }
}

void printBinomialExpansion(int a, int b, int n) {
    printf("(%d+%d)^%d=", a, b, n);
    for (int i = n; i >= 0; i--) {
        int coefficient = nCr(n, i);
        int term = coefficient * pow(a, i) * pow(b, n - i);

        if (coefficient != 1) {
            printf("%d*", coefficient);
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

    // ?取?入
    printf("??入 a：");
    scanf("%d", &a);
    printf("??入 b：");
    scanf("%d", &b);
    printf("??入 n（大于0）：");
    scanf("%d", &n);

    // ???入的合法性
    if (n <= 0) {
        printf("?入的 n 必?大于0。\n");
        return 1;
    }

    printBinomialExpansion(a, b, n);

    int result = pow(a + b, n);
    printf("=%d\n", result);

    return 0;
}

