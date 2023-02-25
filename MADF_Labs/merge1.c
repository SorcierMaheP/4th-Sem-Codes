#include <stdio.h>
char a[100], b[100];
void merge(int low, int mid, int high)
{
    int h = low, i = low, j = mid + 1;
    while ((h <= mid) && (j <= high))
    {
        if (a[h] < a[j])
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
        {
            b[i++] = a[k];
        }
    }
    for (int k = low; k <= high; k++)
        a[k] = b[k];
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
    getchar();
    printf("Enter the characters to be sorted.\n");
    fgets(a, n + 1, stdin);
    mergesort(0, n - 1);
    printf("The sorted array is:\n");
    puts(a);
    return 0;
}