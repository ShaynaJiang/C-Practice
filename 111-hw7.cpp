#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertNode(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else if (data > (*head)->data) {
        newNode->next = *head;
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != NULL && data < current->next->data) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void printList(Node* head, const char* sortType) {
    printf("�Ҧ�����ƥ�%s�Ƨǵ��G\n", sortType);
    int count = 1;
    Node* current = head;
    while (current != NULL) {
        printf("#%03d: %d\n", count, current->data);
        current = current->next;
        count++;
    }
}

void freeList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    Node* head = NULL;
    int input;
    char choice;

    do {
        printf("�п�J�@�ӥ����: ");
        scanf("%d", &input);
        if (input > 0 && isdigit(input)) {
            insertNode(&head, input);
        } else {
            printf("��J�D����ơA�A�T�w�n������J�ܡH(Y/N): ");
            scanf(" %c", &choice);
            choice =toupper(choice);
        }
    } while (input > 0 && choice != 'Y');

    printList(head, "�j��p");
    printList(head, "�p��j");

    freeList(head);
    return 0;
}

