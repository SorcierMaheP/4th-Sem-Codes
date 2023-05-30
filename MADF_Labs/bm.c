#include <stdio.h>
#include <string.h>
#define MAX 256
int lastarr[MAX];

int min(int a, int b)
{
    return a < b ? a : b;
}

void last(char p[MAX], int m)
{
    // Index of the last (right most) occurrence of c in P.
    // Otherwise we define last(c) = -1.
    for (int i = 0; i < MAX; i++)
        lastarr[i] = -1;
    for (int i = 0; i < m; i++)
        lastarr[(int)p[i]] = i;
}

void BM(char test[], char pattern[], int n, int m)
{
    last(pattern, m);
    int i, j;
    i = m - 1;
    j = m - 1;
    do
    {
        if (pattern[j] == test[i])
        {
            printf("%d of test matches with %d of pattern.\n", i, j);
            if (!j)
            {
                printf("Pattern %s found at index %d in string %s.\n", pattern, i, test);
                return;
            }
            else
            {
                i--;
                j--;
            }
        }
        else
        {
            printf("%d of test mismatches with %d of pattern.\n", i, j);
            i = i + m - min(j, 1 + lastarr[(int)test[i]]);
            j = m - 1;
        }

    } while (i <= n - 1);
    printf("Pattern %s not present in string %s!\n", pattern, test);
}

int main()
{
    char test[] = "112311423411";
    char pattern[] = "4112113";
    BM(test, pattern, strlen(test), strlen(pattern));
    return 0;
}