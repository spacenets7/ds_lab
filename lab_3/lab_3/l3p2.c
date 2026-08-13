#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int roll;
    char grade;
};

void read1(struct Student s[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Name: ");
        scanf("%s", s[i].name);
        printf("Roll No: ");
        scanf("%d", &s[i].roll);
        printf("Grade: ");
        scanf(" %c", &s[i].grade);
    }
}

void display1(struct Student s[], int n) {
    printf("\nName\tRoll No\tGrade\n");
    for (int i = 0; i < n; i++)
        printf("%s\t%d\t%c\n", s[i].name, s[i].roll, s[i].grade);
}

void sort(struct Student s[], int n) {
    struct Student temp;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (s[i].roll > s[j].roll) {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
}

int main() {
    int n;
    struct Student s[100];

    printf("Enter number of students: ");
    scanf("%d", &n);

    read(s, n);
    sort(s, n);
    printf("\nSorted Student Information:");
    display(s, n);

    return 0;
}
