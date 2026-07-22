#include <stdio.h>
//#include <conio.h>

int a[100], n = 0, i;

void insert()
{
    int ele, pos = 0;

    printf("Enter element: ");
    scanf("%d", &ele);

    while (pos < n && a[pos] < ele)
        pos++;

    for (i = n; i > pos; i--)
        a[i] = a[i - 1];

    a[pos] = ele;
    n++;
}

void deleteElement()
{
    int ele, pos = -1;

    if (n == 0)
    {
        printf("Array is Empty\n");
        return;
    }

    printf("Enter element to delete: ");
    scanf("%d", &ele);

    for (i = 0; i < n; i++)
    {
        if (a[i] == ele)
        {
            pos = i;
            break;
        }
    }

    if (pos == -1)
    {
        printf("Element not found\n");
        return;
    }

    for (i = pos; i < n - 1; i++)
        a[i] = a[i + 1];

    n--;
}

void display()
{
    if (n == 0)
    {
        printf("Array is Empty\n");
        return;
    }

    printf("Array: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main()
{
    int ch;
    char c;

    //clrscr();

    do
    {
        printf("\n1.Insert\n2.Delete\n3.Display\nEnter Choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                insert();
                break;

            case 2:
                deleteElement();
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