#include <stdio.h>
//#include <conio.h>

int a[100], n = 0, i;

void insert()
{
    int pos, ele;

    printf("Enter position and element: ");
    scanf("%d%d", &pos, &ele);

    if (pos < 1 || pos > n + 1)
    {
        printf("Invalid Position\n");
        return;
    }

    for (i = n; i >= pos; i--)
        a[i] = a[i - 1];

    a[pos - 1] = ele;
    n++;
}

void deleteElement()
{
    int pos;

    if (n == 0)
    {
        printf("Array is Empty\n");
        return;
    }

    printf("Enter position to delete: ");
    scanf("%d", &pos);

    if (pos < 1 || pos > n)
    {
        printf("Invalid Position\n");
        return;
    }

    for (i = pos - 1; i < n - 1; i++)
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