#include<stdio.h>

void dfs(int);
int n, i, j, a[10][10], vis[10];

void main()
{
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for(i = 0; i < n; i++)  // 0-based indexing
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
        vis[i] = 0;  // Initialize visited array
    }

    printf("DFS Traversal:\n");
    for(i = 0; i < n; i++)  // 0-based indexing
    {
        if(vis[i] == 0)
            dfs(i);
    }
}

void dfs(int v)
{
    vis[v] = 1;
    printf("%d ", v + 1);  // Print vertices as 1-based indexing
    for(j = 0; j < n; j++)  // 0-based indexing
    {
        if(a[v][j] == 1 && vis[j] == 0)
        {
            dfs(j);
        }
    }
}
