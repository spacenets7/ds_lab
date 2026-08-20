#include <stdio.h>
#include <string.h>

#define MAX 100

//Array-Based Stack — Palindrome

char stack[MAX];
int top = -1;

void push(char ch)
{
    if (top < MAX - 1)
        stack[++top] = ch;
}

char pop()
{
    if (top >= 0)
        return stack[top--];
    return '\0';
}

int main1()
{
    char str[MAX];
    int i, palindrome = 1;

    printf("Enter a string: ");
    scanf("%s", str);

    for (i = 0; str[i] != '\0'; i++)
        push(str[i]);

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != pop())
        {
            palindrome = 0;
            break;
        }
    }

    if (palindrome)
        printf("The string is a palindrome\n");
    else
        printf("The string is not a palindrome\n");

    return 0;
}
