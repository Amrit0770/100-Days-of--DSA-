/*
Problem Statement
Using BFS or DFS, check if the entire graph is connected.

Input Format
n m
edges

Output Format
CONNECTED
NOT CONNECTED

Sample Input
4 2
1 2
3 4

Sample Output
NOT CONNECTED
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int n, m;

void dfs(int node) {
    printf("Visiting node %d\n", node);
    visited[node] = 1;

    for (int i = 1; i <= n; i++) {
        if (adj[node][i] == 1 && visited[i] == 0) {
            printf("Going to node %d from node %d\n", i, node);
            dfs(i);
        }
    }
}

int main() {
    printf("Enter number of nodes and edges:\n");
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        visited[i] = 0;
        for (int j = 1; j <= n; j++) {
            adj[i][j] = 0;
        }
    }

    printf("Enter edges (u v):\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    printf("\nStarting DFS from node 1...\n");
    dfs(1);

    int connected = 1;
    for (int i = 1; i <= n; i++) {
        if (visited[i] == 0) {
            printf("Node %d was NOT visited\n", i);
            connected = 0;
        }
    }

    if (connected)
        printf("\nCONNECTED\n");
    else
        printf("\nNOT CONNECTED\n");

    return 0;
}