#include <stdio.h>
int adj[100][100], cost[100][100], near[100];
void init_cost(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cost[i][j] = __INT32_MAX__;
    }
}
void accept_graph(int n)
{
    int max_edges = n * (n - 1) / 2;
    int origin, destin, edgecost;
    printf("Enter the edges of the graph and their respective cost.\n");
    for (int i = 0; i < max_edges; i++)
    {
        printf("Enter the edge,( 0 0 randval) to quit :");
        scanf("%d %d %d", &origin, &destin, &edgecost);
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
            adj[destin - 1][origin - 1] = 1;
            cost[destin - 1][origin - 1] = edgecost;
        }
    }
}
void minedge(int *k, int *l, int n)
{
    int mincost = cost[0][0];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (cost[i][j] < mincost)
            {
                mincost = cost[i][j];
                *k = i >= j ? j : i;
                *l = i >= j ? i : j;
            }
        }
    }
}
void display_arr(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i] + 1);
    printf("\n");
}
int prims(int n, int t[n - 1][2])
{
    int k, l;
    minedge(&k, &l, n);
    t[0][0] = k;
    t[0][1] = l;
    int mincost = cost[k][l];
    for (int i = 0; i < n; i++)
    {
        if (cost[i][k] < cost[i][l])
            near[i] = k;
        else
            near[i] = l;
    }
    near[k] = -1;
    near[l] = -1;
    printf("Edge considered is %d %d.\n", k + 1, l + 1);
    int j;
    for (int i = 1; i < n - 1; i++)
    {
        int min = __INT32_MAX__;
        int minj = -1;
        printf("Near array: ");
        display_arr(near, n);
        printf("Mincost: %d\n", mincost);
        for (j = 0; j < n; j++)
        {
            if (near[j] != -1 && cost[j][near[j]] < min)
            {
                min = cost[j][near[j]];
                minj = j;
            }
        }
        printf("Edge considered is %d %d.\n", near[minj] + 1, minj + 1);
        t[i][0] = minj;
        t[i][1] = near[minj];
        mincost += cost[minj][near[minj]];
        near[minj] = -1;
        for (int k = 0; k < n; k++)
        {
            if (near[k] != -1 && cost[k][near[k]] > cost[k][minj])
                near[k] = minj;
        }
    }
    return mincost;
}
int main()
{
    int n;
    printf("Enter the number of vertices of the graph.\n");
    scanf("%d", &n);
    int t[n - 1][2];
    init_cost(n);
    accept_graph(n);
    int ans = prims(n, t);
    printf("Final Mincost: ");
    printf("%d\n", ans);
    return 0;
}