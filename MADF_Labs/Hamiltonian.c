#include <stdio.h>
#define N 20
char G[N][N], count = 0;
void accept_graph(int n)
{
    int max_edges = n * n;
    char origin, destin;
    printf("Enter the edges of the graph.\n");
    printf("Enter the edge;( ~ ~ ) to quit :\n");
    for (int i = 0; i < max_edges; i++)
    {
        scanf(" %c %c", &origin, &destin);
        if ((origin == '~') && (destin == '~'))
            break;
        if (origin > 'A' + n || destin > 'A' + n || origin < 'A' || destin < 'A')
        {
            printf("Invalid edge.\n");
            i--;
        }
        else
        {
            G[(int)origin - 64][(int)destin - 64] = 1;
            G[(int)destin - 64][(int)origin - 64] = 1;
        }
    }
}
void show(char x[N], int nodes)
{
    printf("%d.\t", ++count);
    for (int i = 0; i < nodes; i++)
        printf("%c - ", x[i + 1] + 64);
    printf(" %c", x[1] + 64);
    printf("\n");
}
void nextvalue(char x[N], int nodes, int k)
{
    do
    {
        x[k] = (x[k] + 1) % (nodes + 1);
        if (!x[k])
            return;
        if (G[x[k - 1]][x[k]] != 0)
        {
            int j;
            for (j = 1; j <= k; j++)
                if (x[j] == x[k])
                    break;
            if (j == k)
                if ((k < nodes) || ((k == nodes && G[x[nodes]][x[1]] != 0)))
                    return;
        }
    } while (1);
}
void Hamiltonian(char x[N], int nodes, int k)
{
    do
    {
        nextvalue(x, nodes, k);
        if (!x[k])
            return;
        if (k == nodes)
            show(x, nodes);
        else
            Hamiltonian(x, nodes, k + 1);
    } while (1);
}
int main()
{
    int nodes;
    char x[N];
    printf("Enter the number of nodes: ");
    scanf("%d", &nodes);
    for (int i = 1; i <= nodes; i++)
        for (int j = 1; j <= nodes; j++)
            G[i][j] = 0;
    accept_graph(nodes);
    x[1] = (int)'A' - 64;
    for (int i = 2; i <= nodes; i++)
        x[i] = 0;
    printf("\nHamiltonian Cycles starting from node %d are : \n", x[1]);
    Hamiltonian(x, nodes, x[1] + 1);
    return 0;
}