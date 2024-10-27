#include <stdio.h>

#define MAX_NODES 10

int a[MAX_NODES][MAX_NODES], n;

// Function prototypes
void adj(int k);

int main() {
    int i, j, root;

    // Clear screen (only works in some environments)
    // clrscr(); // Uncomment if using Turbo C/C++

    // Input number of nodes
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // Input adjacency matrix
    printf("Enter adjacency matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            printf("Enter connection of %d --> %d (0 or 1): ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    // Input root node
    printf("Enter root node: ");
    scanf("%d", &root);

    // Call adjacency function
    adj(root);

    return 0;
}

void adj(int k) {
    int j;

    // Print adjacent nodes of the root node
    printf("Adjacent nodes of root node %d:\n", k);
    for (j = 1; j <= n; j++) {
        if (a[k][j] == 1 || a[j][k] == 1) {
            printf("%d\t", j);
        }
    }
    printf("\n");

    // Print nodes not connected to the root node
    printf("Nodes not connected to root node %d:\n", k);
    for (int i = 1; i <= n; i++) {
        if (a[k][i] == 0 && a[i][k] == 0 && i != k) {
            printf("%d\t", i);
        }
    }
    printf("\n");
}
// output 
/* 
Enter number of nodes: 5
Enter adjacency matrix:
Enter connection of 1 --> 1 (0 or 1): 0
Enter connection of 1 --> 2 (0 or 1): 1
Enter connection of 1 --> 3 (0 or 1): 1
Enter connection of 1 --> 4 (0 or 1): 0
Enter connection of 1 --> 5 (0 or 1): 1
Enter connection of 2 --> 1 (0 or 1): 0
Enter connection of 2 --> 2 (0 or 1): 1
Enter connection of 2 --> 3 (0 or 1): 0
Enter connection of 2 --> 4 (0 or 1): 1
Enter connection of 2 --> 5 (0 or 1): 1
Enter connection of 3 --> 1 (0 or 1): 1
Enter connection of 3 --> 2 (0 or 1): 0
Enter connection of 3 --> 3 (0 or 1): 1
Enter connection of 3 --> 4 (0 or 1): 0
Enter connection of 3 --> 5 (0 or 1): 1
Enter connection of 4 --> 1 (0 or 1): 
0
Enter connection of 4 --> 2 (0 or 1): 1
Enter connection of 4 --> 3 (0 or 1): 0
Enter connection of 4 --> 4 (0 or 1): 1
Enter connection of 4 --> 5 (0 or 1): 1
Enter connection of 5 --> 1 (0 or 1): 0
Enter connection of 5 --> 2 (0 or 1): 0
Enter connection of 5 --> 3 (0 or 1): 1
Enter connection of 5 --> 4 (0 or 1): 1
Enter connection of 5 --> 5 (0 or 1): 0
Enter root node: 2
Adjacent nodes of root node 2:
1	2	4	5	
Nodes not connected to root node 2:
3
*/
