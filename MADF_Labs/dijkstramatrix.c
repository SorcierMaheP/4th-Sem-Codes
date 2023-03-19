#include <stdio.h>
#include <stdbool.h>
int adj[100][100], cost[100][100], path[100][100];
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
            cost[i][j] = __INT32_MAX__;
    }
}
void init_dist(int dist[], int n)
{
    for (int i = 0; i < n; i++)
        dist[i] = 0;
}
void init_path(int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 1; j++)
            path[i][j] = 0;
    for (int i = 0; i < n; i++)
        for (int j = 1; j < 100; j++)
            path[i][j] = -1;
}
void rec_dijkstra(int v, int dist[], int n, int S[], int counter)
{
    if (counter < n - 1)
    {
        int min = __INT32_MAX__, minj = -1;
        for (int j = 0; j < n; j++)
        {
            if (S[j] != true && dist[j] < min) // Finds vertex corresponding to minimum distance
            {
                min = dist[j];
                minj = j;
            }
        }
        S[minj] = true;
        for (int k = 0; k < n; k++)
        {
            if (adj[minj][k] == 1 && S[k] == false)
            {
                if (dist[k] > (dist[minj] + cost[minj][k])) // Updates distances
                {
                    int l;
                    dist[k] = dist[minj] + cost[minj][k];
                    for (l = 0; path[k][l] != -1; l++)
                        ;
                    if (dist[minj] == cost[v][minj]) // Direct path
                    {
                        path[k][l] = path[k][l - 1];
                        path[k][l - 1] = minj;
                    }
                    else // Indirect path through other nodes
                    {
                        int m;
                        for (m = 1; path[minj][m] != -1; m++)
                            ;
                        int o = l + m - 2;
                        path[k][o] = path[k][l - 1];
                        for (int p = m - 1; p != 0; p--)
                        {
                            path[k][--o] = path[minj][p];
                        }
                        for (int p = 0; path[k][p] != -1; p++) // Removing redundant nodes
                        {
                            for (int q = 1; path[k][q] != -1; q++)
                            {
                                int count = 0;
                                while (path[k][p] == path[k][q] && p != q)
                                {
                                    count++;
                                    p++;
                                    q++;
                                }
                                p -= count;
                                q -= count;
                                if (count > 0)
                                {
                                    int r;
                                    for (r = p; path[k][r] != -1; r++)
                                        path[k][r] = path[k][r + count];
                                    for (int s = r; s < n; s++)
                                        path[k][s] = -1;
                                }
                            }
                        }
                    }
                }
            }
        }
        rec_dijkstra(v, dist, n, S, ++counter);
    }
}
void init_dijkstra(int v, int dist[], int n)
{
    int S[n];
    for (int i = 0; i < n; i++)
    {
        S[i] = false;
        dist[i] = cost[v - 1][i];
    }
    S[v - 1] = true;
    dist[v - 1] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < 2; j++)
        {
            path[i][j] = i;
        }
    }
    rec_dijkstra(v, dist, n, S, 1);
}
int main()
{
    // FILE *fp;
    // fp = fopen("graph2.txt", "r+");
    int n;
    printf("Enter the number of vertices of the graph.\n");
    scanf("%d", &n);
    int dist[n];
    init_cost(n);
    init_dist(dist, n);
    init_path(n);
    accept_graph(n);
    // accept_graph(fp, n);
    // fclose(fp);
    int v;
    printf("Enter the source vertex of the graph.\n");
    scanf("%d", &v);
    init_dijkstra(v, dist, n);
    printf("PATH%44cLENGTH\n", ' ');
    for (int i = 1; i < n; i++)
    {
        int elems = 0;
        for (int j = 0; path[i][j] != -1; j++, elems++)
            printf("%d ", path[i][j] + 1);
        printf("%*d", 50 - (2 * (elems - 1)), dist[i]);
        printf("\n");
    }
    return 0;
}
