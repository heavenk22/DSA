#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left, *right;
};

// Create a new node
struct Node* createNode(int value)
{
    struct Node* newNode =
        (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Insert a node
struct Node* insert(struct Node* root, int value)
{
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);

    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// Find height of tree
int height(struct Node* root)
{
    if (root == NULL)
        return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + (leftHeight > rightHeight ?
                leftHeight : rightHeight);
}

// Find minimum value
int findMin(struct Node* root)
{
    if (root == NULL)
        return -1;

    while (root->left != NULL)
        root = root->left;

    return root->data;
}

// Mirror the tree
void mirror(struct Node* root)
{
    if (root == NULL)
        return;

    struct Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirror(root->left);
    mirror(root->right);
}

// Search a value
int search(struct Node* root, int key)
{
    if (root == NULL)
        return 0;

    if (root->data == key)
        return 1;

    if (key < root->data)
        return search(root->left, key);

    return search(root->right, key);
}

// Inorder traversal
void inorder(struct Node* root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main()
{
    struct Node* root = NULL;
    int n, value, key, choice;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter values:\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        root = insert(root, value);
    }

    while (1)
    {
        printf("\n\n--- BST OPERATIONS ---\n");
        printf("1. Insert New Node\n");
        printf("2. Longest Path (Height)\n");
        printf("3. Minimum Value\n");
        printf("4. Mirror Image\n");
        printf("5. Search Value\n");
        printf("6. Display Inorder\n");
        printf("0. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("Node inserted successfully!\n");
                break;

            case 2:
                printf("Longest path from root: %d nodes\n",
                       height(root));
                break;

            case 3:
                if (root == NULL)
                    printf("Tree is empty!\n");
                else
                    printf("Minimum value: %d\n",
                           findMin(root));
                break;

            case 4:
                mirror(root);
                printf("Mirror image created successfully!\n");
                break;

            case 5:
                printf("Enter value to search: ");
                scanf("%d", &key);

                if (search(root, key))
                    printf("Value found in BST!\n");
                else
                    printf("Value not found!\n");
                break;

            case 6:
                printf("Inorder traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 0:
                printf("Program terminated.\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
