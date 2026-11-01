#include <stdio.h>
#include <string.h>

#define SIZE 101

struct Client
{
    char name[50];
    char phone[15];
    int occupied;
};

typedef struct Client Client;

unsigned long long hashFunction(char name[])
{
    unsigned long long hash = 0;

    for (int i = 0; name[i] != '\0'; i++)
        hash = hash * 31 + (unsigned char)name[i];

    return hash;
}

int getIndex(unsigned long long key, int i, int method)
{
    int h1 = key % SIZE;

    if (method == 1)
        return (h1 + i) % SIZE;

    else if (method == 2)
        return (h1 + i * i) % SIZE;

    else
    {
        int h2 = 1 + (key % (SIZE - 1));
        return (h1 + i * h2) % SIZE;
    }
}

void insert(Client table[], Client c, int method)
{
    unsigned long long key = hashFunction(c.name);

    for (int i = 0; i < SIZE; i++)
    {
        int index = getIndex(key, i, method);

        if (!table[index].occupied)
        {
            table[index] = c;
            table[index].occupied = 1;
            return;
        }

        if (strcmp(table[index].name, c.name) == 0)
        {
            strcpy(table[index].phone, c.phone);
            return;
        }
    }

    printf("Hash table is full!\n");
}

void search(Client table[], char name[], int method)
{
    unsigned long long key = hashFunction(name);

    for (int i = 0; i < SIZE; i++)
    {
        int index = getIndex(key, i, method);

        if (!table[index].occupied)
            break;

        if (strcmp(table[index].name, name) == 0)
        {
            printf("Name: %s\n", table[index].name);
            printf("Phone Number: %s\n", table[index].phone);
            return;
        }
    }

    printf("Client not found!\n");
}

int main()
{
    Client linear[SIZE] = {0};
    Client quadratic[SIZE] = {0};
    Client doubleHash[SIZE] = {0};

    Client c;
    int n, choice;
    char name[50];

    printf("Enter number of clients : ");
    scanf("%d", &n);

    if (n < 1 || n > 50)
    {
        printf("Invalid number of clients!\n");
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        printf("\nEnter client name: ");
        scanf("%49s", c.name);

        printf("Enter phone number: ");
        scanf("%14s", c.phone);

        c.occupied = 1;

        insert(linear, c, 1);
        insert(quadratic, c, 2);
        insert(doubleHash, c, 3);
    }

    printf("\nEnter client name to search: ");
    scanf("%49s", name);

    printf("\n1. Linear Probing");
    printf("\n2. Quadratic Probing");
    printf("\n3. Double Hashing");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    printf("\nSearch Result:\n");

    switch (choice)
    {
        case 1:
            search(linear, name, 1);
            break;

        case 2:
            search(quadratic, name, 2);
            break;

        case 3:
            search(doubleHash, name, 3);
            break;

        default:
            printf("Invalid choice!\n");
    }

    return 0;
}
