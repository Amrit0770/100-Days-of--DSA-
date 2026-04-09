/*
Problem: Using DFS and parent tracking, detect if undirected graph has a cycle.

Output:
- YES or NO
*/


#include <stdio.h>

int visited[100];

int dfs(int v, int parent, int n, int adj[100][100])
{
    visited[v] = 1;

    for(int i = 0; i < n; i++)
    {
        if(adj[v][i] == 1)
        {
            if(visited[i] == 0)
            {
                if(dfs(i, v, n, adj))
                    return 1;
            }
            else if(i != parent)
            {
                return 1;
            }
        }
    }

    return 0;
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

    int hasCycle = 0;

    for(int i = 0; i < n; i++)
    {
        if(visited[i] == 0)
        {
            if(dfs(i, -1, n, adj))
            {
                hasCycle = 1;
                break;
            }
        }
    }

    if(hasCycle)
        printf("YES");
    else
        printf("NO");

    return 0;
}