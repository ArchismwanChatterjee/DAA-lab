#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

# define V 6
// Function to print the distance array
void printDistance(int dist[])
{
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < V; i++)
    {
        printf("%d\t%d\n", i, dist[i]);
    }
}

// Bellman-Ford algorithm
void bellmanFord(int E, int source, int edge[][3])
{
    int dist[V];

    // Initialize distance array
    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
    }
    dist[source] = 0;

    // Relax all edges V-1 times
    for (int i = 0; i < V - 1; i++)
    {
        for (int j = 0; j < E; j++)
        {
            int u = edge[j][0];
            int v = edge[j][1];
            int weight = edge[j][2];
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
            }
        }
    }

    // Check for negative-weight cycles
    for (int i = 0; i < E; i++)
    {
        int u = edge[i][0];
        int v = edge[i][1];
        int weight = edge[i][2];
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
        {
            printf("Graph contains negative-weight cycle\n");
            return;
        }
    }

    // Print the distance array
    printDistance(dist);
}

int main()
{
    int E = 9;

    int edge[][3] = {{0, 1, 6}, {0, 2, 4}, {0, 3, 5}, {2, 1, -2}, {3, 2, -2}, {1, 4, -1}, {2, 4, 3}, {3, 5, -1}, {4, 5, 3}};

    int source = 0;
    bellmanFord(E, source, edge);

    return 0;
}
