#include <stdio.h>
#define N 20
int G[N][N], count = 0;
char C[8] = {'X', 'V', 'I', 'B', 'G', 'Y', 'O', 'R'};
void accept_graph(int n)
{
    int max_edges = n * n;
    int origin, destin;
    printf("Enter the edges of the graph.\n");
    printf("Enter the edge;( 0 0 ) to quit :\n");
    for (int i = 0; i < max_edges; i++)
    {
        scanf("%d %d", &origin, &destin);
        if ((origin == 0) && (destin == 0))
            break;
        if (origin > n || destin > n || origin <= 0 || destin <= 0)
        {
            printf("Invalid edge.\n");
            i--;
        }
        else
        {
            G[origin - 1][destin - 1] = 1;
            G[destin - 1][origin - 1] = 1;
        }
    }
}
void show(int x[N], int nodes)
{
    printf("%d.\t", ++count);
    for (int i = 0; i < nodes; i++)
        printf("%c ", C[x[i]]);
    printf("\t");
}
void nextvalue(int x[N], int nodes, int colours, int k)
{
    do
    {
        x[k] = (x[k] + 1) % (colours + 1);
        if (!x[k])
            return;
        int j;
        for (j = 0; j < nodes; j++)
        {
            if ((G[k][j] != 0) && (x[k] == x[j]))
                break;
        }
        if (j == nodes)
            return;
    } while (1);
}
void colour(int x[N], int nodes, int colours, int k)
{
    do
    {
        nextvalue(x, nodes, colours, k);
        if (!x[k])
            return;
        if (k == nodes - 1)
            show(x, nodes);
        else
            colour(x, nodes, colours, k + 1);

    } while (1);
}
int main()
{
    int nodes, colours, x[N];
    printf("Enter the number of nodes:");
    scanf("%d", &nodes);
    for (int i = 0; i < nodes; i++)
        for (int j = 0; j < nodes; j++)
            G[i][j] = 0;
    accept_graph(nodes);
    printf("Enter the number of colors:");
    scanf("%d", &colours);
    for (int i = 0; i < nodes; i++)
        x[i] = 0;
    printf("\nGraph colouring possibilities are:\n");
    colour(x, nodes, colours, 0);
    return 0;
}