#include <stdio.h>
int a[100], b[100];
void merge(int low, int mid, int high)
{
    int h = low, i = low, j = mid + 1;
    while ((h <= mid) && (j <= high))
    {
        if (a[h] > a[j])
        {
            b[i++] = a[h++];
        }
        else
        {
            b[i++] = a[j++];
        }
    }
    if (h > mid)
    {
        for (int k = j; k <= high; k++)
            b[i++] = a[k];
    }
    else
    {
        for (int k = h; k <= mid; k++)
            b[i++] = a[k];
    }
    for (int k = low; k <= high; k++)
    {
        a[k] = b[k];
    }
}
void mergesort(int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergesort(low, mid);
        mergesort(mid + 1, high);
        merge(low, mid, high);
    }
}
int main()
{
    int n;
    printf("Enter the size of the array.\n");
    scanf("%d", &n);
    printf("Enter elements of the array.\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    mergesort(0, n - 1);
    printf("The sorted array is:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}