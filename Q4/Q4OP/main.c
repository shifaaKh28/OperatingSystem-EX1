#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int minDistance(int dist[], bool sptSet[], int n) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < n; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void printSolution(int dist[], int n) {
    printf("Vertex \t\t Distance from Source\n");
    for (int i = 0; i < n; i++)
        printf("%d \t\t\t\t %d\n", i, dist[i]);
}

void dijkstra(int **graph, int src, int n) {
    int *dist = (int *)malloc(n * sizeof(int));
    bool *sptSet = (bool *)malloc(n * sizeof(bool));

    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    dist[src] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(dist, sptSet, n);

        sptSet[u] = true;

        for (int v = 0; v < n; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    // print the constructed distance array
    printSolution(dist, n);

    free(dist);
    free(sptSet);
}

int main() {
    int rows, cols;
    scanf("%d %d", &rows, &cols);

    if(rows != cols){
        fprintf(stderr,"Invalid number of rows and columns");
        exit(1);
    }

    int **graph = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        graph[i] = (int *)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] < 0) {
                fprintf(stderr, "Invalid input: Negative arc weight detected.\n");
                exit(1);
            }
        }
    }

    dijkstra(graph, 0, rows);

    // Free memory for the graph
    for (int i = 0; i < rows; i++)
        free(graph[i]);
    free(graph);

    return 0;
}
