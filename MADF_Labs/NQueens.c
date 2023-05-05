#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int M[MAX];
int Place(int k, int i)
{
    for (int j = 0; j < k; j++)
    {
        if (M[j] == i)
            return 0;
        else if (abs(i - M[j]) == abs(k - j))
            return 0;
    }
    return 1;
}
void write(int n)
{
    printf("\n\n");
    for (int i = 0; i < n; i++)
    {
        printf("\t%d", i + 1);
    }
    for (int i = 0; i < n; i++)
    {
        printf("\n\n%d", i + 1);
        for (int j = 0; j < n; j++)
        {
            if (M[i] == j)
                printf("\tQ");
            else
                printf("\tX");
        }
    };
    printf("\n\n");
}
void NQueen(int k, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (Place(k, i))
        {
            M[k] = i;
            if (k == n - 1)
            {
                write(n);
                return;
            }
            else
                NQueen(k + 1, n);
        }
    }
}
int main()
{
    int n;
    printf("Enter value of n:");
    scanf("%d", &n);
    NQueen(0, n);
    return 0;
}