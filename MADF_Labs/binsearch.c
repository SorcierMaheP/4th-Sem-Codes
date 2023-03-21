#include <stdio.h>
char a[100];
void bubble(int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int exch = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                char temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                exch++;
            }
        }
        if (!exch)
            break;
    }
}
int binsearch(char a[], int low, int high, char x)
{
    if (low >= high)
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
    char x;
    printf("Enter elem to be searched.\n");
    scanf("%c", &x);
    printf("Enter size of the array.\n");
    int n;
    scanf("%d", &n);
    printf("Enter character array.\n");
    scanf("%s", a);
    bubble(n);
    int pos = binsearch(a, 0, n - 1, x);
    if (pos == -1)
        printf("Elem not found.\n");
    else
        printf("Elem found at index %d.\n", pos);
    return 0;
}