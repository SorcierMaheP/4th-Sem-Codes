#include <stdio.h>
int adj[100][100], C[100][100], p[100], cost[100], d[100];
// void accept_graph(FILE *fp, int n, int k)
void accept_graph(int n, int k)
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
            C[origin - 1][destin - 1] = edgecost;
        }
    }
}
void init_cost(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            C[i][j] = __INT32_MAX__;
    }
}
void fgraph(int n, int k, int v)
{
    for (int i = 0; i < n; i++)
    {
        cost[i] = __INT32_MAX__;
        d[i] = 0;
    }
    cost[n - 1] = 0;
    for (int j = n - 1; j >= 0; j--)
    {
        int min = __INT32_MAX__, minr;
        for (int r = j + 1; r < n; r++)
        {
            if (adj[j][r] == 1 && (C[j][r] + cost[r]) < min)
            {
                min = C[j][r] + cost[r];
                minr = r;
            }
        }
        if (min != __INT32_MAX__)
            cost[j] = min;
        d[j] = minr;
    }
    p[0] = v - 1;
    p[k - 1] = n - 1;
    for (int j = 1; j < k - 1; j++)
        p[j] = d[p[j - 1]];
}
int main()
{
    // FILE *fp;
    // fp = fopen("graph3.txt", "r+");
    int n, k;
    printf("Enter the number of vertices of the graph, and the stages.\n");
    scanf("%d%d", &n, &k);
    init_cost(n);
    accept_graph(n, k);
    // accept_graph(fp, n, k);
    // fclose(fp);
    int v;
    printf("Enter the source vertex of the graph.\n");
    scanf("%d", &v);
    fgraph(n, k, v);
    printf("VERTEX   COST   CHOICE VERTEX\n");
    printf("%2d         %2d        \n", n, cost[n - 1]);
    for (int i = n - 2; i >= 0; i--)
    {
        printf("%2d         %2d        %2d", i + 1, cost[i], d[i] + 1);
        printf("\n");
    }
    printf("The chosen minimun cost path is: ");
    for (int i = 0; i < k; i++)
        printf("%d ", p[i] + 1);
    printf("\n");
    return 0;
}