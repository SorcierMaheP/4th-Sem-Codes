#include <stdio.h>
#include <string.h>
#define MAX 100

int max(int a, int b)
{
    return a > b ? a : b;
}

int LCS(char s1[], char s2[], int m, int n, int matrix[m + 1][n + 1])
{
    for (int i = 0; i <= m; i++)
        matrix[i][0] = 0;
    for (int j = 0; j <= n; j++)
        matrix[0][j] = 0;
    for (int j = 1; j <= m; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (s1[i - 1] == s2[j - 1])
                matrix[j][i] = matrix[j - 1][i - 1] + 1;
            else
                matrix[j][i] = max(matrix[j][i - 1], matrix[j - 1][i]);
        }
    }
    for (int i = 0; i <= n + 1; i++)
    {
        printf("%.2d\t", i);
    }
    printf("\n--------------------------------------------------------------------------------------------------\n");

    for (int j = 0; j <= m; j++)
    {
        printf("%.2d|\t", j);
        for (int i = 0; i <= n; i++)
        {
            printf("%d\t", matrix[j][i]);
        }
        printf("\n");
    }
    return matrix[m][n];
}

void sequence(int ss[], int m, int n, int matrix[m + 1][n + 1])
{
    int i = m, j = n, k = m;
    while (i > 0)
    {
        if (matrix[i][j] == matrix[i - 1][j])
            ss[k] = 0, k--, i--;
        else
            ss[k] = 1, i--, j--, k--;
    }
}

void print(char str[], int ss[], int m)
{
    for (int i = 1, j = 0; i <= m, j < m; i++, j++)
    {
        if (ss[i])
            printf("%c", str[j]);
    }
    printf("\n");
}

int main()
{
    int matrix[MAX][MAX];
    char str1[] = "KLOKMKNKLOK";
    char str2[] = "KLLKNKLLKNYY";
    int n = strlen(str1);
    int m = strlen(str2);
    int ss[m];
    int k = LCS(str1, str2, m, n, matrix);
    printf("String 1: %s\n", str1);
    printf("String 2: %s\n", str2);
    printf("Answer: %d\n", k);
    sequence(ss, m, n, matrix);
    printf("The subsequence is: ");
    print(str2, ss, m);
    return 0;
}