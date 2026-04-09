/*
Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).
*/

#include <stdio.h>

int main()
{
    int n;
    int adj[100][100];
    int indegree[100] = {0};
    int queue[100];
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

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(adj[i][j] == 1)
            {
                indegree[j]++;
            }
        }
    }

    printf("Initial indegrees:\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", indegree[i]);
    }

    for(int i = 0; i < n; i++)
    {
        if(indegree[i] == 0)
        {
            rear++;
            queue[rear] = i;
        }
    }

    printf("\nTopological Order: ");

    while(front <= rear)
    {
        int v = queue[front];
        front++;

        printf("%d ", v);

        for(int i = 0; i < n; i++)
        {
            if(adj[v][i] == 1)
            {
                indegree[i]--;

                if(indegree[i] == 0)
                {
                    rear++;
                    queue[rear] = i;
                }
            }
        }
    }

    return 0;
}