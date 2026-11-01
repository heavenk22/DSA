#include <stdio.h>

void selectionSort(float a[], int n)
{
    int i, j, min;
    float temp;

    for (i = 0; i < n - 1; i++)
    {
        min = i;

        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
                min = j;
        }

        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}

int main()
{
    float a[100];
    int n, i;

    printf("Enter number of students: ");
    scanf("%d", &n);

    printf("Enter percentages:\n");
    for (i = 0; i < n; i++)
        scanf("%f", &a[i]);

    selectionSort(a, n);

    printf("\nTop five scores:\n");

    for (i = n - 1; i >= 0 && i >= n - 5; i--)
        printf("%.2f\n", a[i]);

    return 0;
}
