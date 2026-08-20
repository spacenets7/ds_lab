#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//Linked List-Based Stack — Infix to Postfix

struct Node
{
    char data;
    struct Node *next;
};

struct Node *top = NULL;

void push(char ch)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = ch;
    newNode->next = top;
    top = newNode;
}

char pop()
{
    struct Node *temp;
    char ch;

    if (top == NULL)
        return '\0';

    temp = top;
    ch = temp->data;
    top = top->next;
    free(temp);

    return ch;
}

char peek()
{
    if (top == NULL)
        return '\0';

    return top->data;
}

int precedence(char ch)
{
    if (ch == '^')
        return 3;
    if (ch == '*' || ch == '/')
        return 2;
    if (ch == '+' || ch == '-')
        return 1;

    return 0;
}

int main4()
{
    char infix[100], postfix[100];
    int i = 0, j = 0;
    char ch;

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    while (infix[i] != '\0')
    {
        ch = infix[i];

        if (isalnum(ch))
        {
            postfix[j++] = ch;
        }
        else if (ch == '(')
        {
            push(ch);
        }
        else if (ch == ')')
        {
            while (top != NULL && peek() != '(')
                postfix[j++] = pop();

            if (top != NULL)
                pop();
        }
        else
        {
            while (top != NULL && peek() != '(' &&
                   precedence(peek()) >= precedence(ch))
            {
                postfix[j++] = pop();
            }

            push(ch);
        }

        i++;
    }

    while (top != NULL)
        postfix[j++] = pop();

    postfix[j] = '\0';

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
