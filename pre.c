#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push
void push(char ch)
{
    stack[++top] = ch;
}

// Pop
char pop()
{
    return stack[top--];
}

// Peek
char peek()
{
    return stack[top];
}

// Precedence
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

// Reverse string
void reverse(char str[])
{
    int i, j;
    char temp;
    j = strlen(str) - 1;

    for(i = 0; i < j; i++, j--)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

// Swap '(' and ')'
void swapParentheses(char str[])
{
    int i;

    for(i = 0; str[i] != '\0'; i++)
    {
        if(str[i] == '(')
            str[i] = ')';
        else if(str[i] == ')')
            str[i] = '(';
    }
}

int main()
{
    char infix[MAX], postfix[MAX], prefix[MAX];
    int i, j = 0;

    printf("Enter Infix Expression: ");
    scanf("%s", infix);

    // Step 1: Reverse
    reverse(infix);

    // Step 2: Swap Parentheses
    swapParentheses(infix);

    // Step 3: Infix to Postfix
    for(i = 0; infix[i] != '\0'; i++)
    {
        char ch = infix[i];

        if(isalnum(ch))
        {
            postfix[j++] = ch;
        }
        else if(ch == '(')
        {
            push(ch);
        }
        else if(ch == ')')
        {
            while(top != -1 && peek() != '(')
            {
                postfix[j++] = pop();
            }
            pop(); // Remove '('
        }
        else
        {
            while(top != -1 && precedence(peek()) >= precedence(ch))
            {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }

    while(top != -1)
    {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    // Step 4: Reverse Postfix
    strcpy(prefix, postfix);
    reverse(prefix);

    // Step 5: Print Prefix
    printf("Prefix Expression: %s\n", prefix);

    return 0;
}