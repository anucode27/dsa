#include<stdio.h>
//#include<conio.h>

#define MAX 5

int q[MAX], front=-1, rear=-1, i;

void insert()
{
    int x;

    if((front==0 && rear==MAX-1) || (rear+1==front))
    {
        printf("Queue Overflow\n");
        return;
    }

    printf("Enter element: ");
    scanf("%d",&x);

    if(front==-1)
        front=rear=0;
    else if(rear==MAX-1)
        rear=0;
    else
        rear++;

    q[rear]=x;
}

void deleteElement()
{
    if(front==-1)
    {
        printf("Queue Underflow\n");
        return;
    }

    printf("Deleted Element: %d\n",q[front]);

    if(front==rear)
        front=rear=-1;
    else if(front==MAX-1)
        front=0;
    else
        front++;
}

void display()
{
    if(front==-1)
    {
        printf("Queue is Empty\n");
        return;
    }

    printf("Queue: ");

    if(front<=rear)
    {
        for(i=front;i<=rear;i++)
            printf("%d ",q[i]);
    }
    else
    {
        for(i=front;i<MAX;i++)
            printf("%d ",q[i]);

        for(i=0;i<=rear;i++)
            printf("%d ",q[i]);
    }

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