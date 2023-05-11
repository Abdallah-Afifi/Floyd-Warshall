#include <iostream>
#include <climits>

#define INF INT_MAX // Infinity

// Function to implement Floyd Warshall algorithm
void floydWarshall(int graph[][4], int V) {
    int dist[V][V];

    // Initialize the solution matrix
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    // Update the solution matrix by considering all vertices as intermediate vertices
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                // If vertex k is an intermediate vertex in the shortest path from i to j
                // and it reduces the path distance, then update dist[i][j]
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the shortest distances between every pair of vertices
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF) {
                std::cout << "INF\t";
            } else {
                std::cout << dist[i][j] << "\t";
            }
        }
        std::cout << std::endl;
    }
}

int main() {
    int graph[][4] = { {0, 5, INF, 10},
                       {INF, 0, 3, INF},
                       {INF, INF, 0, 1},
                       {INF, INF, INF, 0}
                     };

    int V = 4; // Number of vertices in the graph

    floydWarshall(graph, V);

    return 0;
}
