#include <stdio.h>

struct Student {
    char name[50];
    int roll_no;
    float marks;
};

void read(struct Student *s, int n) {
    for (int i = 0; i < n; i++) {
        scanf("%s%d%f", s[i].name, &s[i].roll_no, &s[i].marks);
    }
}

void display(struct Student s[], int n) {
    for (int i = 0; i < n; i++)
        printf("%s\t%d\t%.2f\n", s[i].name, s[i].roll_no, s[i].marks);
}

void highest(struct Student *s, int n) {
    struct Student *max = s;
    for (int i = 1; i < n; i++)
        if ((s + i)->marks > max->marks)
            max = s + i;
    printf("\nHighest Marks:\n%s\t%d\t%.2f\n", max->name, max->roll_no, max->marks);
}

int main3() {
    int n;
    struct Student s[100];

    scanf("%d", &n);
    read(s, n);
    display(s, n);
    highest(s, n);

    return 0;
}

