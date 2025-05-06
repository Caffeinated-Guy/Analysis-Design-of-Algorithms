#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

#define MAX 20
#define INF 999

int dist[MAX];     // Array to store Min Distance
int visited[MAX];  // Array to keep track of visited nodes
int path[MAX];     // Array to keep track of shortest path from source node to all other nodes
int source;

// Function Prototypes
int minDistance(int n);
void printShortest(int n);
void printPath(int path[], int j);

void dijkstra(int n, int graph[MAX][MAX]) {
    int i, u, v;

    // Initially set all the nodes as unvisited
    for (i = 1; i <= n; i++) {
        visited[i] = 0;
    }

    // Set the source node as visited
    visited[source] = 1;

    for (i = 1; i <= n; i++) {
        dist[i] = graph[source][i];
    }

    // Initially set the shortest path from source node to all other nodes through source
    for (i = 1; i <= n; i++) {
        path[i] = source;
    }

    // Set the shortest path to the source node as -1
    path[source] = -1;

    for (i = 1; i < n; i++) {
        u = minDistance(n);
        visited[u] = 1;

        for (v = 1; v <= n; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                path[v] = u;
            }
        }
    }
}

int minDistance(int n) {
    int min = INF, minIndex = -1, i;

    for (i = 1; i <= n; i++) {
        if (visited[i] == 0 && dist[i] <= min) {
            min = dist[i];
            minIndex = i;
        }
    }

    return minIndex;
}

void printShortest(int n) {
    int i;

    for (i = 1; i <= n; i++) {
        if (i != source) {
            printf("The shortest distance from node %d to %d = %d\n", source, i, dist[i]);
            printf("The shortest path from node %d to %d is: ", source, i);
            printf("%d", source);
            printPath(path, i);
            printf("\n");
        }
    }
}

void printPath(int path[], int j) {
    if (path[j] == -1) {
        return;
    }

    printPath(path, path[j]);
    printf(" ---> %d", j);
}

int main() {
    int n, i, j;
    int graph[MAX][MAX]; // 2D-array to read the values of weighted graph

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the weight matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the source vertex: ");
    scanf("%d", &source);

    dijkstra(n, graph);
    printShortest(n);

    return 0;
}
