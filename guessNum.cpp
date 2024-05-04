#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TRIES 10

void generateRandomNumber(int *num) {
    int digits[10] = {0};
    int i;
    for (i = 0; i < 4; i++) {
        int digit;
        do {
            digit = rand() % 10;
        } while (digits[digit]);
        digits[digit] = 1;
        num[i] = digit;
    }
}

int main() {
    int secretNumber[4];
    int guess[4];
    int i, j;
    int numTries = 0;

    srand(time(0));
    generateRandomNumber(secretNumber);

    printf("歡迎來到猜數字遊戲！\n");
    printf("請猜一個四位數字（0-9之間），每個數字不重複。\n");

    do {
        printf("請輸入你的猜測（例如: 1234）：");
        scanf("%d", &guess[0]);
        guess[1] = guess[0] / 10 % 10;
        guess[2] = guess[0] / 100 % 10;
        guess[3] = guess[0] / 1000;

        int numA = 0;
        int numB = 0;

        for (i = 0; i < 4; i++) {
            if (guess[i] == secretNumber[i]) {
                numA++;
            } else {
                for (j = 0; j < 4; j++) {
                    if (guess[i] == secretNumber[j]) {
                        numB++;
                    }
                }
            }
        }

        printf("%dA%dB\n", numA, numB);

        if (numA == 4) {
            printf("恭喜！你猜對了！\n");
            break;
        }

        numTries++;

        if (numTries >= MAX_TRIES) {
            printf("很抱歉，你未能猜中正確數字。正確數字是: %d%d%d%d\n", secretNumber[0], secretNumber[1], secretNumber[2], secretNumber[3]);
            break;
        }

    } while (1);

    return 0;
}

