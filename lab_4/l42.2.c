#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//Linked List-Based Stack — Postfix Evaluation

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void push(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

int pop()
{
    struct Node *temp;
    int value;

    if (top == NULL)
        return 0;

    temp = top;
    value = temp->data;
    top = top->next;
    free(temp);

    return value;
}

int main3()
{
    char postfix[100];
    int i;
    int a, b, result;

    printf("Enter a postfix expression: ");
    scanf("%s", postfix);

    for (i = 0; postfix[i] != '\0'; i++)
    {
        if (isdigit(postfix[i]))
        {
            push(postfix[i] - '0');
        }
        else
        {
            b = pop();
            a = pop();

            switch (postfix[i])
            {
                case '+':
                    result = a + b;
                    break;

                case '-':
                    result = a - b;
                    break;

                case '*':
                    result = a * b;
                    break;

                case '/':
                    result = a / b;
                    break;

                case '%':
                    result = a % b;
                    break;

                default:
                    printf("Invalid operator\n");
                    return 1;
            }

            push(result);
        }
    }

    printf("Result: %d\n", pop());

    return 0;
}
