#include <stdio.h>
#include <limits.h>

#define MAX_NODES 10

// Function to find the node with the minimum distance that has not been included yet
int minDistance(int dist[], int included[], int n) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < n; v++)
        if (included[v] == 0 && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}

// Function to print the shortest path from the source node
void printSolution(int dist[], int n, int source) {
    for (int i = 0; i < n; i++) {
        if (i != source) {
            printf("node %d via %d the shortest distance is : %d \n", source + 1, i + 1, dist[i]);
        }
    }
}

// Function to find shortest paths from source to all other nodes
void dijkstra(int graph[MAX_NODES][MAX_NODES], int n, int source) {
    int dist[MAX_NODES]; // Array to store shortest distance from source to i
    int included[MAX_NODES]; // Array to indicate if node i is included in shortest path tree
    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX, included[i] = 0;
    dist[source] = 0; // Distance of source node from itself is always 0

    // Find shortest path for all nodes
    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(dist, included, n);
        included[u] = 1; // Include node u in shortest path tree

        // Update dist value of adjacent nodes of the included node
        for (int v = 0; v < n; v++)
            if (!included[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    // Print the calculated shortest paths
    printSolution(dist, n, source);
}

int main() {
    int n;
    printf("ENTER THE NUMBER OF HOST IN THE GRAPH\n");
    scanf("%d", &n);
    int graph[MAX_NODES][MAX_NODES];

    printf("IF THERE IS NO DIRECT PATH ASSIGN THE HIGHEST DISTANCE VALUE %d\n", INT_MAX);

    // Reading the cost matrix for the path from each node to another node
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("ENTER THE DISTANCE BETWEEN (%d,%d): ", i + 1, j + 1);
            scanf("%d", &graph[i][j]);
        }
    }

    // Compute shortest paths from each node to all other nodes
    for (int i = 0; i < n; i++) {
        printf("\n");
        dijkstra(graph, n, i);
    }

    return 0;
}