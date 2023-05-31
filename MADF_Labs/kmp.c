#include <stdio.h>
#include <string.h>
#define MAX 256
int f[MAX];

int Failure(char pattern[], int m)
{
    int i = 1, j = 0;
    f[0] = 0;
    while (i < m)
    {
        if (pattern[j] == pattern[i])
        {
            f[i] = j + 1;
            i++, j++;
        }
        else if (j > 0)
            j = f[j - 1];
        else
        {
            f[i] = 0;
            i++;
        }
    }
}

void KMP(char test[], char pattern[], int n, int m)
{
    Failure(pattern, m);
    int i, j;
    i = j = 0;
    while (i < n)
    {
        if (pattern[j] == test[i])
        {
            printf("%d of test matches with %d of pattern.\n", i, j);
            if (j == m - 1)
            {
                printf("Pattern %s found at index %d in %s.\n", pattern, i - m + 1, test);
                return;
            }
            i++, j++;
        }
        else
        {
            printf("%d of test mismatches with %d of pattern.\n", i, j);
            if (j > 0)
                j = f[j - 1];
            else
                i++;
        }
    }
    printf("Pattern %s not present in string %s!\n", pattern, test);
    return;
}

int main()
{
    char test[50], pattern[50];
    printf("Enter test string.\n");
    scanf("%s", test);
    printf("Enter pattern string.\n");
    scanf("%s", pattern);
    KMP(test, pattern, strlen(test), strlen(pattern));
    return 0;
}