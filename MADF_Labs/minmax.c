#include <stdio.h>
int a[100];
void minmax(int i, int j, int *max, int *min)
{
    if (i == j)
        *max = *min = a[i];
    else if (i == j - 1)
    {
        if (a[i] > a[j])
        {
            *max = a[i];
            *min = a[j];
        }
        else
        {
            *max = a[j];
            *min = a[i];
        }
    }
    else
    {
        int mid = (i + j) / 2;
        int min1, max1;
        minmax(i, mid, max, min);
        minmax(mid + 1, j, &max1, &min1);
        if (max1 > *max)
            *max = max1;
        if (min1 < *min)
            *min = min1;
    }
}
int main()
{
    int n, min, max;
    printf("Enter the size of the array.\n");
    scanf("%d", &n);
    printf("Enter the elements.\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    minmax(0, n - 1, &max, &min);
    printf("The min and max is %d and %d.\n", min, max);
    return 0;
}