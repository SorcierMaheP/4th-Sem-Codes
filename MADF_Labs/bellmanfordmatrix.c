#include <stdio.h>
#include <stdbool.h>
int adj[100][100], cost[100][100], dist[100], newdist[100];
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
void init_cost(int n, int v)
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
bool incoming_check(int u, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (adj[i][u] == 1)
            return true;
    }
    return false;
}
void printarr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == __INT32_MAX__)
            printf(" ∞ ");
        else
            printf("%2d ", arr[i]);
    }
    printf("\n");
}
void recpathprint(int parent[], int j)
{
    if (parent[j] == -1)
    {
        printf("%d ", j + 1);
        return;
    }
    recpathprint(parent, parent[j]);
    printf("%d ", j + 1);
}
void allpathprint(int parent[], int n, int v)
{
    for (int i = 0; i < n; i++)
    {
        if (i == v - 1)
            continue;
        else
        {
            printf("%d ", v);
            recpathprint(parent, i);
            printf("\n");
        }
    }
    printf("\n");
}
void bellmanford(int n, int v)
{
    int parent[n];
    for (int i = 0; i < n; i++)
    {
        dist[i] = newdist[i] = cost[v - 1][i];
        parent[i] = -1;
    }
    printarr(dist, n);
    for (int k = 1; k < n - 1; k++)
    {
        for (int u = 0; u < n; u++)
        {
            int l, i, m;
            if (u != v - 1 && incoming_check(u, n) == true)
            {
                for (i = 0; i < n; i++)
                {
                    if (newdist[u] > dist[i] + cost[i][u] && adj[i][u] == 1 && dist[i] != __INT32_MAX__)
                    {
                        newdist[u] = dist[i] + cost[i][u];
                        parent[u] = i;
                    }
                }
            }
        }
        for (int i = 0; i < n; i++)
            dist[i] = newdist[i];
        printarr(dist, n);
    }
    printf("The shortest paths are: \n");
    allpathprint(parent, n, v);
}
int main()
{
    // FILE *fp;
    // fp = fopen("graph2.txt", "r+");
    int n;
    printf("Enter the number of vertices of the graph.\n");
    scanf("%d", &n);
    int v;
    printf("Enter the source vertex of the graph.\n");
    scanf("%d", &v);
    init_cost(n, v);
    accept_graph(n);
    // accept_graph(fp, n);
    // fclose(fp);
    bellmanford(n, v);
    printf("The distances of source vertex to other vertices are:\nVERTICES:  ");
    for (int i = 0; i < n; i++)
        printf("%2d ", i + 1);
    printf("\nDISTARRAY: ");
    printarr(dist, n);
    return 0;
}