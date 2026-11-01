#include <stdio.h>

int binarySearch(int arr[], int n, int key)
{
    int low = 0, high = n - 1, mid;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;

        else if (key < arr[mid])
            high = mid - 1;

        else
            low = mid + 1;
    }

    return -1;
}

int main()
{
    int arr[100], n, key, result;

    printf("Enter number of students: ");
    scanf("%d", &n);

    printf("Enter roll numbers in sorted order:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter roll number to search: ");
    scanf("%d", &key);

    result = binarySearch(arr, n, key);

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
