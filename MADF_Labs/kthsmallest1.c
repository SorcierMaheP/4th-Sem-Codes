#include <stdio.h>
int a[100];
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int Partition(int m, int p)
{
    int v = a[m], i = m, j = p;
    while (i < j)
    {
        do
        {
            i++;
        } while (a[i] <= v);
        do
        {
            j--;
        } while (a[j] > v);
        if (i < j)
        {
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[m], &a[j]);
    return j;
}
int kthsmallest(int n, int k)
{
    int low = 0;
    int up = n;
    do
    {
        int j = Partition(low, up);
        if (k == j)
            return a[j];
        else if (k > j)
            low = j + 1;
        else
            up = j;
    } while (1);
}
int main()
{
    int n;
    printf("Enter the size of the array.\n");
    scanf("%d", &n);
    printf("Enter the elements.\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    a[n] = __INT32_MAX__;
    int sel;
    printf("Enter the order of smallest elem you want to display.\n");
    scanf("%d", &sel);
    int num = kthsmallest(n, sel - 1);
    printf("The %dth smallest element is %d.\n", sel, num);
    return 0;
}