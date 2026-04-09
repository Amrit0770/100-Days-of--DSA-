/*
Problem: Perform BFS from a given source using queue.

Input:
- n
- adjacency list
- source s

Output:
- BFS traversal order
*/

#include <stdio.h>

int visited[100], queue[100];

int main()
{
    int n, s;
    int adj[100][100];
    int front = 0, rear = -1;

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

    visited[s] = 1;
    rear++;
    queue[rear] = s;

    printf("BFS Traversal: ");

    while(front <= rear)
    {
        int v = queue[front];
        front++;

        printf("%d ", v);

        for(int i = 0; i < n; i++)
        {
            if(adj[v][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                rear++;
                queue[rear] = i;
            }
        }
    }

    return 0;
}