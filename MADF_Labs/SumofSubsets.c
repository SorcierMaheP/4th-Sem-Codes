#include <stdio.h>
#define MAX 100
int w[MAX], x[MAX];
int m, n;
void write(int k)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", x[i]);
    }
    printf(" i.e weights : ");
    for (int i = 0; i <= k; i++)
    {
        if (x[i] == 1)
            printf("%d ", w[i]);
    }
    printf("\n");
}
void SumofSubsets(int s, int k, int r)
{
    if (k > n)
        return;
    x[k] = 1;
    if (s + w[k] == m)
    {
        write(k);
    }
    else if (s + w[k] + w[k + 1] <= m)
    {
        SumofSubsets(s + w[k], k + 1, r - w[k]);
    }
    if ((s + r - w[k] >= m) && (s + w[k + 1] <= m))
    {
        x[k] = 0;
        SumofSubsets(s, k + 1, r - w[k]);
    }
}
int main()
{
    int r = 0;
    printf("Enter number of elements.");
    scanf("%d", &n);
    printf("Enter the elements of the set.\n");
    for (int i = 0; i < n; i++)
    {
        x[i] = 0;
        scanf("%d", &w[i]);
        r += w[i];
    }
    printf("Enter sum.\n");
    scanf("%d", &m);
    printf("The subsets are :-\n");
    SumofSubsets(0, 0, r);
    return 0;
}