/*
Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.
*/


#include <stdio.h>

int visited[100], stack[100], top = -1;

void dfs(int v, int n, int adj[100][100])
{
    visited[v] = 1;

    for(int i = 0; i < n; i++)
    {
        if(adj[v][i] == 1 && visited[i] == 0)
        {
            dfs(i, n, adj);
        }
    }

    top++;
    stack[top] = v;
}

int main()
{
    int n;
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

    for(int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    for(int i = 0; i < n; i++)
    {
        if(visited[i] == 0)
        {
            dfs(i, n, adj);
        }
    }

    printf("Topological Order: ");

    while(top != -1)
    {
        printf("%d ", stack[top]);
        top--;
    }

    return 0;
}