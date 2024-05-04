#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int playerChoice, computerChoice;
    int playerWins = 0, computerWins = 0;
    char playAgain;

    printf("歡迎來到猜拳遊戲！\n");

    do {
        printf("請選擇拳頭（1）、剪刀（2）或布（3）：");
        scanf("%d", &playerChoice);

        // 產生電腦隨機選擇
        srand(time(0));
        computerChoice = rand() % 3 + 1;

        printf("你選擇了 ");
        switch (playerChoice) {
            case 1:
                printf("拳頭");
                break;
            case 2:
                printf("剪刀");
                break;
            case 3:
                printf("布");
                break;
            default:
                printf("無效的選擇");
                break;
        }

        printf("，電腦選擇了 ");
        switch (computerChoice) {
            case 1:
                printf("拳頭");
                break;
            case 2:
                printf("剪刀");
                break;
            case 3:
                printf("布");
                break;
        }

        // 判斷勝負
        if (playerChoice == computerChoice) {
            printf("\n平手！\n");
        } else if ((playerChoice == 1 && computerChoice == 2) ||
                   (playerChoice == 2 && computerChoice == 3) ||
                   (playerChoice == 3 && computerChoice == 1)) {
            printf("\n你贏了！\n");
            playerWins++;
        } else {
            printf("\n你輸了！\n");
            computerWins++;
        }

        printf("目前勝場數：你 %d 勝，電腦 %d 勝\n", playerWins, computerWins);

        printf("是否要再次遊戲？（Y/N）：");
        scanf(" %c", &playAgain);
    } while (playAgain == 'Y' || playAgain == 'y');

    printf("遊戲結束，謝謝參與！\n");

    return 0;
}

