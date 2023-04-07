#include <stdio.h>
int adj[100][100], cost[100][100], A[100][100];
// void accept_graph(FILE *fp, int n)
void accept_graph(int n)
{
    int max_edges = n * (n - 1);
    int origin, destin, edgecost;
    printf("Enter the edges of the graph and their respective cost.\n");
    for (int i = 0; i < max_edges; i++)
    {
        printf("Enter the edge,( 0 0 randval) to quit :");
        scanf("%d %d %d", &origin, &destin, &edgecost);
        // fscanf(fp, "%d %d %d", &origin, &destin, &edgecost);
        if ((origin == 0) && (destin == 0))
            break;
        if (origin > n || destin > n || origin <= 0 || destin <= 0)
        {
            printf("Invalid edge.\n");
            i--;
        }
        else
        {
            adj[origin - 1][destin - 1] = 1;
            cost[origin - 1][destin - 1] = edgecost;
        }
    }
}
void init_cost(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                cost[i][j] = 0;
            else
                cost[i][j] = __INT32_MAX__;
        }
    }
}
void printm(int n, int mat[][100])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] >= __INT32_MAX__)
                printf("∞ ");
            else
                printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void allpair(int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            A[i][j] = cost[i][j];
    printm(n, A);
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (adj[i][k] == 1 && adj[k][j] == 1)
                    A[i][j] = A[i][j] < A[i][k] + A[k][j] ? A[i][j] : A[i][k] + A[k][j];
            }
        }
        if (k != n - 1)
            printm(n, A);
    }
}
int main()
{
    // FILE *fp;
    // fp = fopen("graph4.txt", "r+");
    int n;
    printf("Enter the number of vertices of the graph.\n");
    scanf("%d", &n);
    init_cost(n);
    accept_graph(n);
    // accept_graph(fp, n);
    // fclose(fp);
    allpair(n);
    printf("The final all pairs shortest path matrix is: \n");
    printm(n, A);
    return 0;
}