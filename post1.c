#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push operation
void push(char ch)
{
    stack[++top] = ch;
}

// Pop operation
char pop()
{
    return stack[top--];
}

// Return precedence of operators
int precedence(char ch)
{
    switch(ch)
    {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

int main()
{
    char infix[MAX], postfix[MAX];
    int i, j = 0;

    printf("Enter Infix Expression: ");
    scanf("%s", infix);

    for(i = 0; infix[i] != '\0'; i++)
    {
        char ch = infix[i];

        // Operand
        if(isalnum(ch))
        {
            postfix[j++] = ch;
        }
        // Left Parenthesis
        else if(ch == '(')
        {
            push(ch);
        }
        // Right Parenthesis
        else if(ch == ')')
        {
            while(top != -1 && stack[top] != '(')
            {
                postfix[j++] = pop();
            }
            pop(); // Remove '('
        }
        // Operator
        else
        {
            while(top != -1 && precedence(stack[top]) >= precedence(ch))
            {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }

    // Pop remaining operators
    while(top != -1)
    {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("Postfix Expression: %s\n", postfix);

    return 0;
}