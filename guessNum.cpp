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

    printf("�w��Ө�q�Ʀr�C���I\n");
    printf("�вq�@�ӥ|��Ʀr�]0-9�����^�A�C�ӼƦr�����ơC\n");

    do {
        printf("�п�J�A���q���]�Ҧp: 1234�^�G");
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
            printf("���ߡI�A�q��F�I\n");
            break;
        }

        numTries++;

        if (numTries >= MAX_TRIES) {
            printf("�ܩ�p�A�A����q�����T�Ʀr�C���T�Ʀr�O: %d%d%d%d\n", secretNumber[0], secretNumber[1], secretNumber[2], secretNumber[3]);
            break;
        }

    } while (1);

    return 0;
}

