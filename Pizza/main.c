#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

// Add order (Enqueue)
void enqueue(int order)
{
    if (rear == MAX - 1)
    {
        printf("Queue Overflow! Cannot accept more orders.\n");
    }
    else
    {
        if (front == -1)
            front = 0;

        rear++;
        queue[rear] = order;

        printf("Order %d added successfully!\n", order);
    }
}

// Serve order (Dequeue)
void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue Underflow! No orders to serve.\n");
    }
    else
    {
        printf("Order %d served successfully!\n", queue[front]);
        front++;

        if (front > rear)
        {
            front = rear = -1;
        }
    }
}

// Display queue
void display()
{
    if (front == -1)
    {
        printf("Queue is empty!\n");
    }
    else
    {
        printf("\nPending Orders:\n");

        for (int i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }

        printf("\n");
    }
}

int main()
{
    int choice, order;

    while (1)
    {
        printf("\n--- PIZZA ORDER SYSTEM ---\n");
        printf("1. Add Order (Enqueue)\n");
        printf("2. Serve Order (Dequeue)\n");
        printf("3. Display Orders\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter Order ID: ");
                scanf("%d", &order);
                enqueue(order);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Thank you!\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
