#include<stdio.h>
//#include<conio.h>

#define MAX 20

int q[MAX], front=-1, rear=-1, i;

void insert()
{
    int x;

    if(rear==MAX-1)
    {
        printf("Queue Overflow\n");
        return;
    }

    printf("Enter element: ");
    scanf("%d",&x);

    if(front==-1)
        front=0;

    q[++rear]=x;
}

void deleteElement()
{
    if(front==-1 || front>rear)
    {
        printf("Queue Underflow\n");
        return;
    }

    printf("Deleted Element: %d\n",q[front++]);

    if(front>rear)
        front=rear=-1;
}

void display()
{
    if(front==-1)
    {
        printf("Queue is Empty\n");
        return;
    }

    printf("Queue: ");

    for(i=front;i<=rear;i++)
        printf("%d ",q[i]);

    printf("\n");
}

int main()
{
    int ch;
    char c;

    //clrscr();

    do
    {
        printf("\n1.Insert\n2.Delete\n3.Display\nChoice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: insert(); break;
            case 2: deleteElement(); break;
            case 3: display(); break;
            default: printf("Invalid Choice\n");
        }

        printf("Continue(y/n): ");
        scanf(" %c",&c);

    }while(c=='y'||c=='Y');

    //getch();
    return 0;
}