#include <stdio.h>
#define MAX_NODES 20
#define INF 9999 // Represent infinity for non-connected nodes

// struct to define routing table for each node
struct Node {
    int dist[MAX_NODES];
    int from[MAX_NODES];
};

struct Node route[MAX_NODES];

int main() {
    int dm[MAX_NODES][MAX_NODES];
    int n;
    int i, j, k;
    int flag;

    // Get the input of number of nodes
    printf("Enter the number of nodes:\n");
    scanf("%d", &n);

    // Get the cost matrix 
    printf("Enter the cost matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &dm[i][j]);
            if (i != j && dm[i][j] == 0) {
                dm[i][j] = INF; // Set infinity for non-connected nodes
            }
            route[i].dist[j] = dm[i][j];
            route[i].from[j] = j;
        }
    }

    // Distance vector algorithm loop
    do {
        flag = 0; // Reset the flag to check for changes
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                for (k = 0; k < n; k++) {
                    // Check if a shorter path exists
                    if (route[i].dist[j] > route[i].dist[k] + route[k].dist[j]) {
                        route[i].dist[j] = route[i].dist[k] + route[k].dist[j];
                        route[i].from[j] = k;
                        flag = 1; // Set flag to indicate a change
                    }
                }
            }
        }
    } while (flag);

    // Print the routing tables for each node
    for (i = 0; i < n; i++) {
        printf("Routing table for router %d\n", i + 1);
        printf("Dest\tnext-Hop\tDist\n");
        for (j = 0; j < n; j++) {
            if (route[i].dist[j] == INF) {
                printf("%d\t-\t\tINF\n", j + 1); // Display 'INF' for unreachable nodes
            } else {
                printf("%d\t%d\t\t%d\n", j + 1, route[i].from[j] + 1, route[i].dist[j]);
            }
        }
    }
    return 0;
}
