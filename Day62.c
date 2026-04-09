/*
Problem: Build a graph with adjacency list representation. Use linked lists or dynamic arrays.

Input:
- n (vertices)
- m (edges)
- edges (u, v)

Output:
- List of adjacency lists for each vertex
*/

#include <stdio.h>

int main()
{
    int J, K, Q = 0, nextQ;

    printf("Initial Q = %d\n", Q);

    printf("Enter number of inputs: ");
    int n;
    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
    {
        printf("\nEnter J and K: ");
        scanf("%d %d", &J, &K);

        if(J == 0 && K == 0)
            nextQ = Q;
        else if(J == 0 && K == 1)
            nextQ = 0;
        else if(J == 1 && K == 0)
            nextQ = 1;
        else
            nextQ = !Q;

        printf("Previous Q = %d\n", Q);
        printf("Next Q = %d\n", nextQ);

        Q = nextQ;
    }

    return 0;
}