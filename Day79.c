/*
Problem Statement
Find shortest distances from source vertex in a weighted graph with non-negative weights.

Input Format
n m
u v w
source

Output Format
Distances to all vertices.

Sample Input
5 6
1 2 2
1 3 4
2 3 1
2 4 7
3 5 3
4 5 1
1

Sample Output
0 2 3 9 6

Explanation
Shortest distances computed via priority queue.
*/

#include<stdio.h>
#include<stdlib.h>
#define INF 1000000000

int n,m;
int g[105][105],dist[105],vis[105];

int main(){
    int i,j,u,v,w,s,min,idx;

    scanf("%d%d",&n,&m);

    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            g[i][j]=INF;

    for(i=0;i<m;i++){
        scanf("%d%d%d",&u,&v,&w);
        g[u][v]=w;
        g[v][u]=w;
    }

    scanf("%d",&s);

    for(i=1;i<=n;i++){
        dist[i]=INF;
        vis[i]=0;
    }

    dist[s]=0;

    for(i=1;i<=n;i++){
        min=INF;
        idx=-1;

        for(j=1;j<=n;j++)
            if(!vis[j] && dist[j]<min)
                min=dist[j],idx=j;

        if(idx==-1) break;

        vis[idx]=1;

        for(j=1;j<=n;j++)
            if(!vis[j] && g[idx][j]!=INF && dist[idx]+g[idx][j]<dist[j])
                dist[j]=dist[idx]+g[idx][j];
    }

    for(i=1;i<=n;i++)
        printf("%d ",dist[i]);

    return 0;
}