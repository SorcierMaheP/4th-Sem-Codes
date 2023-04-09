#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAX 100
char iden[MAX][MAX];
int p[MAX], q[MAX];
int printlchild(int r[MAX][MAX], int i, int j, int level)
{
    if (r[i][r[i][j] - 1] != 0)
    {
        if (level == 0)
            printf("%d = %s ", r[i][r[i][j] - 1], iden[r[i][r[i][j] - 1]]);
        return 1;
    }
    return 0;
}
int printrchild(int r[MAX][MAX], int i, int j, int level)
{
    if (r[r[i][j]][j] != 0)
    {
        if (level == 0)
            printf("%d = %s ", r[r[i][j]][j], iden[r[r[i][j]][j]]);
        return 1;
    }
    return 0;
}
void printchild(int r[MAX][MAX], int i, int j, int n, int level)
{
    int a, b;
    a = printlchild(r, i, j, level);
    b = printrchild(r, i, j, level);
    if (a != 0 && level > 0)
        printchild(r, i, r[i][j] - 1, n, level - 1);
    if (b != 0 && level > 0)
        printchild(r, r[i][j], j, n, level - 1);
}
void levelorder(int r[MAX][MAX], int i, int j, int n)
{
    for (int level = 0; level < n - 1; level++)
    {
        printchild(r, i, j, n, level);
        printf("\n");
    }
}
void OBST(int w[MAX][MAX], int c[MAX][MAX], int r[MAX][MAX], int n)
{
    int temp = 0, min, min1;
    for (int i = 0; i < n; i++)
    {
        w[i][i] = q[i];
        r[i][i] = 0;
        c[i][i] = 0;
        w[i][i + 1] = q[i] + q[i + 1] + p[i + 1];
        r[i][i + 1] = i + 1;
        c[i][i + 1] = q[i] + q[i + 1] + p[i + 1];
        printf("%d %d\t%d\t%d\t%d\n", i, i, w[i][i], c[i][i], r[i][i]);
    }
    w[n][n] = q[n];
    r[n][n] = 0;
    c[n][n] = 0;
    printf("%d %d\t%d\t%d\t%d\n", n, n, w[n][n], c[n][n], r[n][n]);
    for (int k = 1; k <= n; k++)
    {
        for (int i = 0, j = k; j <= n; i++, j++) // Since table is of upper left triangular format
        {
            if (i != j && j - i != 1)
            {
                w[i][j] = p[j] + q[j] + w[i][j - 1];
                min = __INT32_MAX__;
                for (int l = i + 1; l <= j; l++)
                {
                    min1 = c[i][l - 1] + c[l][j];
                    if (min1 < min)
                    {
                        min = min1;
                        temp = l;
                    }
                }
                c[i][j] = min + w[i][j];
                r[i][j] = temp;
            }
            printf("%d %d\t%d\t%d\t%d\n", i, j, w[i][j], c[i][j], r[i][j]);
        }
    }
    printf("The minimum cost is %d.\n", c[0][n]);
    printf("The level order traversal is:\n");
    printf("Root = %d = %s.\n", r[0][n], iden[r[0][n]]);
    levelorder(r, 0, n, n);
}
int main()
{
    int w[MAX][MAX], c[MAX][MAX], r[MAX][MAX];
    int n;
    int i, j, k, b;
    printf("Enter the number of elements: \n");
    scanf("%d", &n);
    printf("Enter %d identifiers.\n", n);
    for (i = 1; i <= n; i++)
        scanf("%s", iden[i]);
    printf("Enter %d success probabilities.\n", n);
    for (i = 1; i <= n; i++)
        scanf("%d", &p[i]);
    printf("Enter %d failure probabilities.\n", n + 1);
    for (i = 0; i <= n; i++)
        scanf("%d", &q[i]);
    OBST(w, c, r, n);
    printf("\n");
    return 0;
}