#include <stdio.h>
#include <string.h>

#define MAX 20

int main()
{
    int graph[MAX][MAX] = {0};
    char city[MAX][30];
    int n, flights, cost;
    int i, j, src, dest;

    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter city names:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%29s", city[i]);
    }

    printf("Enter number of direct flights: ");
    scanf("%d", &flights);

    for (i = 0; i < flights; i++)
    {
        printf("\nEnter source city index: ");
        scanf("%d", &src);

        printf("Enter destination city index: ");
        scanf("%d", &dest);

        printf("Enter flight cost: ");
        scanf("%d", &cost);

        if (src >= 0 && src < n &&
            dest >= 0 && dest < n && cost > 0)
        {
            graph[src][dest] = cost;
            graph[dest][src] = cost;
        }
        else
        {
            printf("Invalid flight details!\n");
            i--;
        }
    }

    // Display adjacency matrix
    printf("\nWeighted Adjacency Matrix:\n");

    printf("\t");
    for (i = 0; i < n; i++)
        printf("%s\t", city[i]);

    printf("\n");

    for (i = 0; i < n; i++)
    {
        printf("%s\t", city[i]);

        for (j = 0; j < n; j++)
        {
            printf("%d\t", graph[i][j]);
        }

        printf("\n");
    }

    // Display direct flights
    printf("\nDirect Flight Connections:\n");

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (graph[i][j] != 0)
            {
                printf("%s -> %s : Cost = %d\n",
                       city[i], city[j], graph[i][j]);
            }
        }
    }

    return 0;
}
