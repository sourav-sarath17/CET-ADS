#include <stdlib.h>
#include <stdio.h>

int queue[100];
int front = -1, rear = -1, n;

int deque();
void enque(int value);

void bfs(int matrix[][100], int n, int visited[], int s_node)
{
    enque(s_node);
    visited[s_node] = 1;
    printf("%d", s_node);
    while (front != -1 && rear != -1)
    {
        int node = deque();
        for (int i = 0; i < n; i++)
        {
            if (matrix[node][i] == 1 && visited[i] == 0)
            {
                enque(i);
                visited[i] = 1;
                printf(" %d", i);
            }
        }
    }
    return;
}

void main()
{
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    int v[n];
    for (int i = 0; i < n; i++)
    {
        v[i] = 0;
    }

    int A[100][100];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("A[%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    int s_node;
    printf("\nEnter the starting node: ");
    scanf("%d", &s_node);
    if (s_node < 0 || s_node >= n)
    {
        printf("\nInvalid");
        return;
    }
    printf("BFS ->");
    bfs(A, n, v, s_node);
    printf("\n");
}

void enque(int value)
{
    if (rear == n - 1)
        return;
    if (front == -1)
    {
        front = 0;
    }
    rear++;
    queue[rear] = value;
}

int deque()
{
    if (front == -1)
        return -1;
    int value = queue[front];
    if (front == rear)
    {
        front--;
    }
    else
        front++;
    return value;
}