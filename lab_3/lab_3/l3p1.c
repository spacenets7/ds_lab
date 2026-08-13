#include <stdio.h>

int str_len(char s[]) {
    int i = 0;
    while (s[i] != '\0') i++;
    return i;
}

void str_concat(char s1[], char s2[], char res[]) {
    int i = 0, j = 0;
    while (s1[i] != '\0') { res[i] = s1[i]; i++; }
    while (s2[j] != '\0') { res[i] = s2[j]; i++; j++; }
    res[i] = '\0';
}

int str_cmp(char s1[], char s2[]) {
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i]) return s1[i] - s2[i];
        i++;
    }
    return s1[i] - s2[i];
}

void str_insert(char text[], char sub[], int pos, char res[]) {
    int i = 0, j = 0, k = 0;
    while (i < pos && text[i] != '\0') { res[k++] = text[i++]; }
    while (sub[j] != '\0') { res[k++] = sub[j++]; }
    while (text[i] != '\0') { res[k++] = text[i++]; }
    res[k] = '\0';
}

void str_delete(char text[], int pos, int len, char res[]) {
    int i = 0, k = 0;
    while (text[i] != '\0') {
        if (i < pos || i >= pos + len) {
            res[k++] = text[i];
        }
        i++;
    }
    res[k] = '\0';
}

int main1() {
    char s1[100] = "Hello", s2[100] = "World", sub[50] = "Beautiful ";
    char res[200];
    printf("Length of s1: %d\n", str_len(s1));
    str_concat(s1, s2, res);
    printf("Concatenation: %s\n", res);
    printf("Comparison: %d\n", str_cmp(s1, s2));
    str_insert(s1, sub, 5, res);
    printf("Insertion: %s\n", res);
    str_delete(res, 5, 10, s1);
    printf("Deletion: %s\n", s1);
    return 0;
}

