#include <stdio.h>

#define SIZE 10

int hashTable[SIZE];

// Initialize hash table
void initialize()
{
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;
}

// Insert using Linear Probing
void insert(int key)
{
    int index = key % SIZE;
    int originalIndex = index;

    while (hashTable[index] != -1)
    {
        index = (index + 1) % SIZE;

        // Table is full
        if (index == originalIndex)
        {
            printf("Hash table is full!\n");
            return;
        }
    }

    hashTable[index] = key;
}

// Display hash table
void display()
{
    printf("\nHash Table:\n");

    for (int i = 0; i < SIZE; i++)
    {
        if (hashTable[i] == -1)
            printf("%d : EMPTY\n", i);
        else
            printf("%d : %d\n", i, hashTable[i]);
    }
}

int main()
{
    int n, key;

    initialize();

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
