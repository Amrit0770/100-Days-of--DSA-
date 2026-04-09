/*
Problem: Perform DFS starting from a given source vertex using recursion.

Input:
- n
- adjacency list
- starting vertex s

Output:
- DFS traversal order
*/

#include <stdio.h>

int visited[100];

void dfs(int v, int n, int adj[100][100])
{
    visited[v] = 1;
    printf("%d ", v);

    for(int i = 0; i < n; i++)
    {
        if(adj[v][i] == 1 && visited[i] == 0)
        {
            dfs(i, n, adj);
        }
    }
}

int main()
{
    int n, s;
    int adj[100][100];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter starting vertex: ");
    scanf("%d", &s);

    for(int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    printf("DFS Traversal: ");
    dfs(s, n, adj);

    return 0;
}