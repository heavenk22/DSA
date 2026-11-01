#include <stdio.h>

void bubbleSort(float a[], int n)
{
    int i, j;
    float temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
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

    bubbleSort(a, n);

    printf("\nTop five scores:\n");

    for (i = n - 1; i >= 0 && i >= n - 5; i--)
        printf("%.2f\n", a[i]);

    return 0;
}
