#include <stdio.h>
//#include <conio.h>

#define MAX 100

int stack[MAX], top = -1, i;

void push()
{
    int ele;

    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }

    printf("Enter element: ");
    scanf("%d", &ele);

    stack[++top] = ele;
}

void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return;
    }

    printf("Deleted element: %d\n", stack[top--]);
}

void display()
{
    if (top == -1)
    {
        printf("Stack is Empty\n");
        return;
    }

    printf("Stack Elements:\n");
    for (i = top; i >= 0; i--)
        printf("%d\n", stack[i]);
}

int main()
{
    int ch;
    char c;

    //clrscr();

    do
    {
        printf("\n1.Push\n2.Pop\n3.Display\nEnter Choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            default:
                printf("Invalid Choice\n");
        }

        printf("Continue (y/n): ");
        scanf(" %c", &c);

    } while (c == 'y' || c == 'Y');

    //getch();
    return 0;
}