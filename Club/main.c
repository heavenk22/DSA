#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int prn;
    char name[50];
    struct Node *next;
};

struct Node *head1 = NULL;
struct Node *head2 = NULL;

struct Node* createNode(int prn, char name[])
{
    struct Node *newNode =
        (struct Node*)malloc(sizeof(struct Node));

    newNode->prn = prn;
    strcpy(newNode->name, name);
    newNode->next = NULL;

    return newNode;
}

// Add president
void addPresident(struct Node **head, int prn, char name[])
{
    struct Node *newNode = createNode(prn, name);

    newNode->next = *head;
    *head = newNode;
}

// Add secretary
void addSecretary(struct Node **head, int prn, char name[])
{
    struct Node *newNode = createNode(prn, name);

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    struct Node *temp = *head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Add member after president
void addMember(struct Node *head, int prn, char name[])
{
    if (head == NULL)
    {
        printf("Add president first!\n");
        return;
    }

    struct Node *newNode = createNode(prn, name);
    newNode->next = head->next;
    head->next = newNode;
}

// Delete president
void deletePresident(struct Node **head)
{
    if (*head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    struct Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Delete secretary
void deleteSecretary(struct Node **head)
{
    if (*head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    struct Node *temp = *head;

    if (temp->next == NULL)
    {
        free(temp);
        *head = NULL;
        return;
    }

    while (temp->next->next != NULL)
        temp = temp->next;

    free(temp->next);
    temp->next = NULL;
}

// Delete member using PRN
void deleteMember(struct Node **head, int prn)
{
    struct Node *temp = *head;
    struct Node *prev = NULL;

    while (temp != NULL && temp->prn != prn)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Member not found!\n");
        return;
    }

    if (prev == NULL)
        *head = temp->next;
    else
        prev->next = temp->next;

    free(temp);
}

// Count members
int countMembers(struct Node *head)
{
    int count = 0;

    while (head != NULL)
    {
        count++;
        head = head->next;
    }

    return count;
}

// Display members
void display(struct Node *head)
{
    if (head == NULL)
    {
        printf("No members in the club.\n");
        return;
    }

    printf("\nPRN\tName\t\tPosition\n");

    int count = countMembers(head);

    for (int i = 1; head != NULL; i++)
    {
        printf("%d\t%s\t\t", head->prn, head->name);

        if (i == 1)
            printf("President");
        else if (i == count)
            printf("Secretary");
        else
            printf("Member");

        printf("\n");
        head = head->next;
    }
}

// Concatenate two lists
void concatenate()
{
    if (head1 == NULL)
    {
        head1 = head2;
        head2 = NULL;
        return;
    }

    struct Node *temp = head1;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = head2;
    head2 = NULL;

    printf("Lists concatenated successfully!\n");
}

int main()
{
    int choice, prn, n;
    char name[50];

    while (1)
    {
        printf("\n--- PINNACLE CLUB ---\n");
        printf("1. Add President\n");
        printf("2. Add Member\n");
        printf("3. Add Secretary\n");
        printf("4. Delete President\n");
        printf("5. Delete Member\n");
        printf("6. Delete Secretary\n");
        printf("7. Count Members\n");
        printf("8. Display Members\n");
        printf("9. Add Member to Division 2\n");
        printf("10. Concatenate Lists\n");
        printf("11. Display Division 2\n");
        printf("0. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter PRN and Name: ");
                scanf("%d %49s", &prn, name);
                addPresident(&head1, prn, name);
                break;

            case 2:
                printf("Enter PRN and Name: ");
                scanf("%d %49s", &prn, name);
                addMember(head1, prn, name);
                break;

            case 3:
                printf("Enter PRN and Name: ");
                scanf("%d %49s", &prn, name);
                addSecretary(&head1, prn, name);
                break;

            case 4:
                deletePresident(&head1);
                printf("President deleted.\n");
                break;

            case 5:
                printf("Enter PRN to delete: ");
                scanf("%d", &prn);
                deleteMember(&head1, prn);
                break;

            case 6:
                deleteSecretary(&head1);
                printf("Secretary deleted.\n");
                break;

            case 7:
                printf("Total members: %d\n",
                       countMembers(head1));
                break;

            case 8:
                display(head1);
                break;

            case 9:
                printf("Enter PRN and Name: ");
                scanf("%d %49s", &prn, name);
                addSecretary(&head2, prn, name);
                break;

            case 10:
                concatenate();
                break;

            case 11:
                display(head2);
                break;

            case 0:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
