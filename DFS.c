#include <stdio.h>
#include <stdlib.h>

void dfs(int matrix[][100], int visited[], int s_node, int n)
{
    printf("%d ", s_node);
    visited[s_node] = 1;
    for (int i = 0; i < n; i++)
    {
        if (matrix[s_node][i] == 1 && visited[i] == 0)
        {
            dfs(matrix, visited, i, n);
        }
    }
}

void main()
{
    int A[100][100], n, s_node;
    printf("\nEnter the no.of nodes: ");
    scanf("%d", &n);
    int visited[n];

    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("\nEnter the value of A[%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    printf("\nEnter the starting node: ");
    scanf("%d", &s_node);
    printf("\nDFS-> ");
    dfs(A, visited, s_node, n);
}