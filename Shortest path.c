#include <stdio.h>
#define INF 9999
#define MAX 20

int main() {
    int i, j, k, n, start, end;
    int graph[MAX][MAX];

    // Input number of vertices
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Input weighted graph (0 means no edge except diagonal)
    printf("Enter the weighted adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
            if (i != j && graph[i][j] == 0)
                graph[i][j] = INF;
        }

    // Floyd-Warshall algorithm
    for (k = 0; k < n; k++)
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                if (graph[i][k] + graph[k][j] < graph[i][j])
                    graph[i][j] = graph[i][k] + graph[k][j];

    // Output shortest path matrix
    printf("\nShortest path matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (graph[i][j] == INF)
                printf("INF ");
            else
                printf("%3d ", graph[i][j]);
        }
        printf("\n");
    }

    // Input to find shortest path between two specific vertices
    printf("Enter start vertex (0 to %d): ", n - 1);
    scanf("%d", &start);
    printf("Enter end vertex (0 to %d): ", n - 1);
    scanf("%d", &end);

    if (graph[start][end] == INF)
        printf("No path exists between %d and %d.\n", start, end);
    else
        printf("Shortest path from %d to %d is: %d\n", start, end, graph[start][end]);

    return 0;
}
