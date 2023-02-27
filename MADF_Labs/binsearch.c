#include <stdio.h>
char a[100];
int binsearch(char a[], int low, int high, char x)
{
    if (low == high)
    {
        if (a[low] == x)
            return low;
        else
            return -1;
    }
    else
    {
        int mid = (low + high) / 2;
        if (a[mid] == x)
            return mid;
        else if (x > a[mid])
            return binsearch(a, mid + 1, high, x);
        else
            return binsearch(a, low, mid - 1, x);
    }
}
int main()
{
    int x;
    printf("Enter elem to be search.\n");
    scanf("%c", &x);
    printf("Enter size of the array.\n");
    int n;
    scanf("%d", &n);
    printf("Enter character array.\n");
    scanf("%s", a);
    int pos = binsearch(a, 0, n - 1, x);
    if (pos == -1)
        printf("Elem not found.\n");
    else
        printf("Elem found at index %d.\n", pos);
    return 0;
}