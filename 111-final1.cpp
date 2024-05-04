#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    char name[50];
    int sid;
    int gra1;
    int gra2;
    int gra3;
    struct Student* next;
} Student;

Student* createStudent(char name[], int sid, int gra1, int gra2, int gra3) {
    Student* newStudent = (Student*)malloc(sizeof(Student));
    strcpy(newStudent->name, name);
    newStudent->sid = sid;
    newStudent->gra1 = gra1;
    newStudent->gra2 = gra2;
    newStudent->gra3 = gra3;
    newStudent->next = NULL;
    return newStudent;
}

void printStudent(Student* student) {
    printf("Name: %s\n", student->name);
    printf("Student ID: %d\n", student->sid);
    printf("Grade 1: %d\n", student->gra1);
    printf("Grade 2: %d\n", student->gra2);
    printf("Grade 3: %d\n", student->gra3);
    printf("Average Grade: %.2f\n", (student->gra1 + student->gra2 + student->gra3) / 3.0);
    printf("\n");
}
void printMinMaxAverage(Student* head) {
    Student* current = head;
    Student* minStudent = head;
    Student* maxStudent = head;

    while (current != NULL) {
        if ((current->gra1 + current->gra2 + current->gra3) / 3.0 < (minStudent->gra1 + minStudent->gra2 + minStudent->gra3) / 3.0) {
            minStudent = current;
        }

        if ((current->gra1 + current->gra2 + current->gra3) / 3.0 > (maxStudent->gra1 + maxStudent->gra2 + maxStudent->gra3) / 3.0) {
            maxStudent = current;
        }

        current = current->next;
    }

    printf("平均最高的學生:\n");
    printStudent(minStudent);

    printf("平均最低的學生:\n");
    printStudent(maxStudent);
}

int main() {
    FILE* fp = fopen("/tmp/111-1.txt", "r");
    if (fp == NULL) {
        printf("檔案開啟失敗\n");
        return 1;
    }

    Student* head = NULL;
    char line[100];

    while (fgets(line, sizeof(line), fp)) {
        char* name = strtok(line, " \t\n");
        int sid = atoi(strtok(NULL, " \t\n"));
        int gra1 = atoi(strtok(NULL, " \t\n"));
        int gra2 = atoi(strtok(NULL, " \t\n"));
        int gra3 = atoi(strtok(NULL, " \t\n"));

        Student* newStudent = createStudent(name, sid, gra1, gra2, gra3);
        if (head == NULL) {
            head = newStudent;
        } else {
            Student* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newStudent;
        }
    }

    fclose(fp);

    Student* current = head;
    while (current != NULL) {
        printStudent(current);
        current = current->next;
    }
    printMinMaxAverage(head);
    current = head;
    while (current != NULL) {
        Student* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}


