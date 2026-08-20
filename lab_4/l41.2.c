#include <stdio.h>
#include <string.h>

#define MAX 100

//Array-Based Stack — Parentheses Matching

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

int isMatching(char open, char close)
{
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

int main2()
{
    char exp[MAX];
    int i, valid = 1;

    printf("Enter an expression: ");
    scanf("%s", exp);

    for (i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
        {
            push(exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}')
        {
            if (top == -1 || !isMatching(pop(), exp[i]))
            {
                valid = 0;
                break;
            }
        }
    }

    if (top != -1)
        valid = 0;

    if (valid)
        printf("Parentheses are balanced\n");
    else
        printf("Parentheses are not balanced\n");

    return 0;
}
