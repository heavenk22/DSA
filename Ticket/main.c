#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define SEATS 7

struct Node
{
    int seat;
    struct Node *prev;
    struct Node *next;
};

struct Node *head[ROWS];

// Create a new node
struct Node* createNode(int seat)
{
    struct Node *newNode =
        (struct Node*)malloc(sizeof(struct Node));

    newNode->seat = seat;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

// Initialize all seats
void initialize()
{
    for (int i = 0; i < ROWS; i++)
    {
        head[i] = NULL;

        for (int j = 1; j <= SEATS; j++)
        {
            struct Node *newNode = createNode(j);

            if (head[i] == NULL)
                head[i] = newNode;
            else
            {
                struct Node *temp = head[i];

                while (temp->next != NULL)
                    temp = temp->next;

                temp->next = newNode;
                newNode->prev = temp;
            }
        }
    }
}

// Display available seats
void displaySeats()
{
    printf("\nAvailable Seats:\n");

    for (int i = 0; i < ROWS; i++)
    {
        printf("Row %d: ", i + 1);

        struct Node *temp = head[i];

        while (temp != NULL)
        {
            printf("%d ", temp->seat);
            temp = temp->next;
        }

        if (head[i] == NULL)
            printf("No seats available");

        printf("\n");
    }
}

// Book a seat
void bookSeat(int row, int seat)
{
    struct Node *temp = head[row - 1];

    while (temp != NULL && temp->seat != seat)
        temp = temp->next;

    if (temp == NULL)
    {
        printf("Seat already booked or invalid!\n");
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head[row - 1] = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);

    printf("Seat booked successfully!\n");
}

// Cancel booking
void cancelBooking(int row, int seat)
{
    struct Node *temp = head[row - 1];

    while (temp != NULL)
    {
        if (temp->seat == seat)
        {
            printf("Seat is not booked!\n");
            return;
        }

        temp = temp->next;
    }

    struct Node *newNode = createNode(seat);

    temp = head[row - 1];

    if (temp == NULL)
    {
        head[row - 1] = newNode;
    }
    else if (seat < temp->seat)
    {
        newNode->next = temp;
        temp->prev = newNode;
        head[row - 1] = newNode;
    }
    else
    {
        while (temp->next != NULL &&
               temp->next->seat < seat)
            temp = temp->next;

        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next != NULL)
            temp->next->prev = newNode;

        temp->next = newNode;
    }

    printf("Booking cancelled successfully!\n");
}

int main()
{
    int choice, row, seat;

    initialize();

    // Random initial bookings
    bookSeat(2, 3);
    bookSeat(4, 5);
    bookSeat(7, 2);

    while (1)
    {
        printf("\n--- CINEMAX TICKET BOOKING ---\n");
        printf("1. Display Available Seats\n");
        printf("2. Book Seat\n");
        printf("3. Cancel Booking\n");
        printf("4. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                displaySeats();
                break;

            case 2:
                printf("Enter row (1-10): ");
                scanf("%d", &row);

                printf("Enter seat (1-7): ");
                scanf("%d", &seat);

                if (row >= 1 && row <= ROWS &&
                    seat >= 1 && seat <= SEATS)
                    bookSeat(row, seat);
                else
                    printf("Invalid row or seat!\n");

                break;

            case 3:
                printf("Enter row (1-10): ");
                scanf("%d", &row);

                printf("Enter seat (1-7): ");
                scanf("%d", &seat);

                if (row >= 1 && row <= ROWS &&
                    seat >= 1 && seat <= SEATS)
                    cancelBooking(row, seat);
                else
                    printf("Invalid row or seat!\n");

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
