#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

// Node of linked list
struct Node
{
    int data;
    struct Node *next;
};

struct Node *hashTable[SIZE];

// Insert key into hash table
void insert(int key)
{
    int index = key % SIZE;

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = key;
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

// Display hash table
void display()
{
    int i;
    struct Node *temp;

    printf("\nHash Table:\n");

    for (i = 0; i < SIZE; i++)
    {
        printf("%d : ", i);

        temp = hashTable[i];

        while (temp != NULL)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }

        printf("NULL\n");
    }
}

int main()
{
    int n, key;

    // Initialize hash table
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = NULL;

    printf("Enter number of keys: ");
    scanf("%d", &n);

    printf("Enter keys:\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &key);
        insert(key);
    }

    display();

    return 0;
}
