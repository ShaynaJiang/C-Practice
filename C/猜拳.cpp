#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int playerChoice, computerChoice;
    int playerWins = 0, computerWins = 0;
    char playAgain;

    printf("�w��Ө�q���C���I\n");

    do {
        printf("�п�ܮ��Y�]1�^�B�ŤM�]2�^�Υ��]3�^�G");
        scanf("%d", &playerChoice);

        // ���͹q���H�����
        srand(time(0));
        computerChoice = rand() % 3 + 1;

        printf("�A��ܤF ");
        switch (playerChoice) {
            case 1:
                printf("���Y");
                break;
            case 2:
                printf("�ŤM");
                break;
            case 3:
                printf("��");
                break;
            default:
                printf("�L�Ī����");
                break;
        }

        printf("�A�q����ܤF ");
        switch (computerChoice) {
            case 1:
                printf("���Y");
                break;
            case 2:
                printf("�ŤM");
                break;
            case 3:
                printf("��");
                break;
        }

        // �P�_�ӭt
        if (playerChoice == computerChoice) {
            printf("\n����I\n");
        } else if ((playerChoice == 1 && computerChoice == 2) ||
                   (playerChoice == 2 && computerChoice == 3) ||
                   (playerChoice == 3 && computerChoice == 1)) {
            printf("\n�AĹ�F�I\n");
            playerWins++;
        } else {
            printf("\n�A��F�I\n");
            computerWins++;
        }

        printf("�ثe�ӳ��ơG�A %d �ӡA�q�� %d ��\n", playerWins, computerWins);

        printf("�O�_�n�A���C���H�]Y/N�^�G");
        scanf(" %c", &playAgain);
    } while (playAgain == 'Y' || playAgain == 'y');

    printf("�C�������A���°ѻP�I\n");

    return 0;
}

