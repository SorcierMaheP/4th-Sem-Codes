#include <stdio.h>
#include <math.h>
#define MAX 100
struct knap
{
    int p;
    int w;
    float rat;
};
int m, n, x[MAX], y[MAX], z[MAX], fp, fw;
int Bound(int k, int cp, int cw, struct knap K[])
{
    int b = cp, c = cw;
    for (int i = k; i < n; i++)
    {
        c += K[i].w;
        if (c < m)
            b += K[i].p;
        else
        {
            return b + (int)ceil((1 - (c - m) / (float)K[i].w) * K[i].p);
        }
    }
    return b;
}
void BKnap(int k, int cp, int cw, struct knap K[])
{
    // Left child
    if (cw + K[k].w <= m)
    {
        y[k] = 1;
        if (k < n - 1)
        {
            printf("Left Child of K:%d CP:%d CW:%d\n", k + 1, cp, cw);
            BKnap(k + 1, cp + K[k].p, cw + K[k].w, K);
        }
        if ((cp + K[k].p > fp) && (k == n - 1))
        {
            printf("Left Child of K:%d P:%d W:%d\n", k + 1, cp, cw);
            fp = cp + K[k].p;
            fw = cw + K[k].w;
            printf("New cost is %d.\n", fp);
            for (int j = 0; j < k; j++)
                x[j] = y[j];
            x[k] = 1;
            printf("Array updated.\n");
            for (int i = 0; i < n; i++)
                printf("%d ", x[i]);
            printf("\n");
        }
    }
    // Right child
    if (Bound(k, cp, cw, K) >= fp)
    {
        y[k] = 0;
        if (k < n - 1)
        {
            printf("Right Child of K:%d P:%d W:%d.\n", k + 1, cp, cw);
            BKnap(k + 1, cp, cw, K);
        }
        if ((cp > fp) && (k == n - 1))
        {
            printf("Right Child of K:%d P:%d W:%d\n", k + 1, cp, cw);
            fp = cp;
            fw = cw;
            printf("New cost is %d.\n", fp);
            for (int j = 0; j < k; j++)
                x[j] = y[j];
            x[k] = 0;
            printf("Array updated.\n");
            for (int i = 0; i < n; i++)
                printf("%d ", x[i]);
            printf("\n");
        }
    }
}
void sort(struct knap K[])
{
    struct knap key;
    for (int i = 1; i < n; i++)
    {
        key = K[i];
        int j = i - 1;
        while (j >= 0 && K[j].rat < key.rat)
        {
            K[j + 1] = K[j];
            j = j - 1;
        }
        K[j + 1] = key;
    }
}
int main()
{
    printf("Enter number of knapsack values and size of knapsack.\n");
    scanf("%d%d", &n, &m);
    struct knap K[n + 1];
    int p_values[MAX], w_values[MAX];
    printf("Enter profits of knapsack.\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &p_values[i]);
    printf("Enter weights of knapsack.\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &w_values[i]);
    for (int i = 0; i < n; i++)
    {
        K[i].p = p_values[i];
        K[i].w = w_values[i];
        K[i].rat = (float)K[i].p / K[i].w;
    }
    sort(K);
    fp = -1;
    BKnap(0, 0, 0, K);
    printf("The final array is:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (p_values[i] == K[j].p && w_values[i] == K[j].w)
            {
                if (x[j])
                    z[i] = 1;
                else
                    z[i] = 0;
            }
        }
    }
    for (int i = 0; i < n; i++)
        printf("%d ", z[i]);
    printf("\nThe max profit is %d.\n", fp);
    return 0;
}