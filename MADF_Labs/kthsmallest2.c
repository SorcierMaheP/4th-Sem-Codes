#include <stdio.h>
char a[100];
void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}
int Partition(int m, int p)
{
    char v = a[m], i = m, j = p;
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
char kthsmallest(int n, int k)
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
    getchar();
    printf("Enter the elements.\n");
    fgets(a, n + 1, stdin);
    a[n] = '~';
    a[n + 1] = '\0';
    int sel;
    printf("Enter the order of smallest elem you want to display.\n");
    scanf("%d", &sel);
    char ch = kthsmallest(n, sel - 1);
    printf("The %dth smallest element is %c.\n", sel, ch);
    return 0;
}