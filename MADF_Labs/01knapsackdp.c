#include <stdio.h>
#define MAX 1000
struct knap
{
    int p;
    int w;
    int obj[MAX];
};
void PurgeKnap(struct knap S[MAX], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (S[i].p < S[j].p && S[i].w >= S[j].w)
                S[i].p = S[i].w = -1;
            else if (S[j].p < S[i].p && S[j].w >= S[i].w)
                S[j].p = S[j].w = -1;
        }
        for (int j = i + 1; j < size; j++)
        {
            if (S[i].p == S[j].p && S[i].w == S[j].w)
                S[j].p = S[j].w = -1;
        }
    }
}
void DKnap(int m, int n, int p[n], int w[n])
{
    struct knap S[MAX];
    S[0].w = 0, S[0].p = 0;
    printf("(%d,%d)\n", S[0].p, S[0].w);
    int i, j, k, l;
    for (i = 0; i < n; i++)
        S[0].obj[i] = 0;
    int size = 1;
    for (i = 0; i < n; i++)
    {
        for (j = 0, k = size; j < size; j++, k++)
        {
            if (S[j].w == -1)
            {
                continue;
            }
            S[k].w = S[j].w + w[i];
            if (S[k].w > m)
            {
                S[k].w = S[k].p = -1;
                continue;
            }
            S[k].p = S[j].p + p[i];
            for (l = 0; l < n; l++)
                S[k].obj[l] = S[j].obj[l];
            S[k].obj[i] += 1;
        }
        printf("\n");
        size = size * 2;
        PurgeKnap(S, size);
        for (int i = 0; i < size; i++)
        {
            if (S[i].w != -1 && S[i].p != -1)
                printf("(%d,%d) ", S[i].p, S[i].w);
        }
        printf("\n");
    }
    printf("\n");
    int maxp = -1, maxw = -1, index;
    for (i = 0; i < size; i++)
    {
        if (S[i].w < maxw)
            continue;
        else if (S[i].w > maxw)
        {
            maxw = S[i].w, maxp = S[i].p;
            index = i;
        }
        else
        {
            if (S[i].p > maxp)
            {
                maxp = S[i].p, index = i;
            }
        }
    }
    printf("\n\nMax profit: %d\nBag filled: %d\nObjects chosen: ", maxp, maxw);
    for (i = 0; i < n; i++)
        printf("x[%d]  ", i + 1);
    printf(" : ");
    for (i = 0; i < n; i++)
    {
        if (S[index].obj[i] != 1)
            printf("%d  ", 0);
        else
            printf("%d  ", S[index].obj[i]);
    }
}

int main()
{
    int n, m, i;
    printf("Enter number of elements:");
    scanf("%d", &n);
    printf("Enter max weight capacity of knapsack bag:");
    scanf("%d", &m);
    int p[n], w[n];
    printf("Enter profits :");
    for (i = 0; i < n; i++)
        scanf("%d", &p[i]);
    printf("Enter weights :");
    for (i = 0; i < n; i++)
        scanf("%d", &w[i]);
    DKnap(m, n, p, w);
    printf("\n");
    return 0;
}