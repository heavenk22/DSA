#include <stdio.h>

int linearSearch(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int arr[100], n, key, result;

    printf("Enter number of students: ");
    scanf("%d", &n);

    printf("Enter roll numbers:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter roll number to search: ");
    scanf("%d", &key);

    result = linearSearch(arr, n, key);

    if (result != -1)
    {
        printf("Student attended the training program.\n");
        printf("Roll number found at position %d.", result + 1);
    }
    else
    {
        printf("Student did not attend the training program.");
    }

    return 0;
}
