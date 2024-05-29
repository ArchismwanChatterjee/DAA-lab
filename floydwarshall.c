#include <stdio.h>

#define V 4
#define INF 99999

void display(int dist[][V]);

void floyd(int dist[][V])
{
    int i, j, k;
    for (k = 0; k < V; k++)
    {
        for (i = 0; i < V; i++)
        {
            for (j = 0; j < V; j++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    display(dist);
}

void display(int dist[][V])
{
    printf(
        "The output is \n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int graph[V][V] = {{0, INF, 3, INF},
                       {2, 0, INF, INF},
                       {INF, 7, 0, 1},
                       {INF, INF, INF, 0}};

    floyd(graph);
    return 0;
}
