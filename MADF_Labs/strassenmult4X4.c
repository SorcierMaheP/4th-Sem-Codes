#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
int **zero = NULL;
int **matralloc(int **a, int rows, int columns)
{
    a = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
        *(a + i) = (int *)malloc(columns * sizeof(int));
    return a;
}
void accept(int **a, int rows, int columns)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
            scanf("%d", (*(a + i) + j));
    }
}
void display(int **a, int rows, int columns)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("%d ", *(*(a + i) + j));
        }
        printf("\n");
    }
}
int **sum(int **a, int **b, int **c, int r1, int c1, int r2, int c2)
{
    for (int i = r1, l = 0, p = r2; i < r1 + 2; i++, l++, p++)
    {
        int m = 0;
        for (int j = c1, m = 0, q = c2; j < c1 + 2; j++, m++, q++)
            *(*(c + l) + m) = *(*(a + i) + j) + *(*(b + p) + q);
    }
    return c;
}
int **sub(int **a, int **b, int **c, int r1, int c1, int r2, int c2)
{
    for (int i = r1, l = 0, p = r2; i < r1 + 2; i++, l++, p++)
    {
        int m = 0;
        for (int j = c1, m = 0, q = c2; j < c1 + 2; j++, m++, q++)
            *(*(c + l) + m) = *(*(a + i) + j) - *(*(b + p) + q);
    }
    return c;
}
void strassen(int **a, int **b, int **c, int rows, int columns)
{
    if (rows == 2 && columns == 2)
    {
        int p, q, r, s, t, u, v;
        p = (a[0][0] + a[1][1]) * (b[0][0] + b[1][1]);
        q = (a[1][0] + a[1][1]) * (b[0][0]);
        r = (a[0][0]) * (b[0][1] - b[1][1]);
        s = (a[1][1]) * (b[1][0] - b[0][0]);
        t = (a[0][0] + a[0][1]) * (b[1][1]);
        u = (a[1][0] - a[0][0]) * (b[0][0] + b[0][1]);
        v = (a[0][1] - a[1][1]) * (b[1][0] + b[1][1]);
        c[0][0] = p + s - t + v;
        c[0][1] = r + t;
        c[1][0] = q + s;
        c[1][1] = p + r - q + u;
    }
    else
    {
        int **temp1 = NULL, **temp2 = NULL;
        temp1 = matralloc(temp1, 2, 2);
        temp2 = matralloc(temp2, 2, 2);
        int **p = NULL, **q = NULL, **r = NULL, **s = NULL, **t = NULL, **u = NULL, **v = NULL;
        p = matralloc(p, 2, 2);
        q = matralloc(q, 2, 2);
        r = matralloc(r, 2, 2);
        s = matralloc(s, 2, 2);
        t = matralloc(t, 2, 2);
        u = matralloc(u, 2, 2);
        v = matralloc(v, 2, 2);
        strassen((temp1 = sum(a, a, temp1, 0, 0, 2, 2)), (temp2 = sum(b, b, temp2, 0, 0, 2, 2)), p, 2, 2);
        strassen((temp1 = sum(a, a, temp1, 2, 0, 2, 2)), (temp2 = sum(b, zero, temp2, 0, 0, 0, 0)), q, 2, 2);
        strassen((temp1 = sum(a, zero, temp1, 0, 0, 0, 0)), (temp2 = sub(b, b, temp2, 0, 2, 2, 2)), r, 2, 2);
        strassen((temp1 = sum(a, zero, temp1, 2, 2, 0, 0)), (temp2 = sub(b, b, temp2, 2, 0, 0, 0)), s, 2, 2);
        strassen((temp1 = sum(a, a, temp1, 0, 0, 0, 2)), (temp2 = sum(b, zero, temp2, 2, 2, 0, 0)), t, 2, 2);
        strassen((temp1 = sub(a, a, temp1, 2, 0, 0, 0)), (temp2 = sum(b, b, temp2, 0, 0, 0, 2)), u, 2, 2);
        strassen((temp1 = sub(a, a, temp1, 0, 2, 2, 2)), (temp2 = sum(b, b, temp2, 2, 0, 2, 2)), v, 2, 2);
        int **c00 = NULL, **c01 = NULL, **c10 = NULL, **c11 = NULL;
        c00 = matralloc(c00, 2, 2);
        c01 = matralloc(c01, 2, 2);
        c10 = matralloc(c10, 2, 2);
        c11 = matralloc(c11, 2, 2);
        c00 = sum(temp2 = sub(temp1 = (sum(p, s, temp1, 0, 0, 0, 0)), t, temp2, 0, 0, 0, 0), v, c00, 0, 0, 0, 0);
        c01 = sum(r, t, c01, 0, 0, 0, 0);
        c10 = sum(q, s, c10, 0, 0, 0, 0);
        c11 = sum(temp2 = sub(temp1 = (sum(p, r, temp1, 0, 0, 0, 0)), q, temp2, 0, 0, 0, 0), u, c11, 0, 0, 0, 0);
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                *(*(c + i) + j) = *(*(c00 + i) + j);
                *(*(c + i) + j + 2) = *(*(c01 + i) + j);
                *(*(c + i + 2) + j) = *(*(c10 + i) + j);
                *(*(c + i + 2) + j + 2) = *(*(c11 + i) + j);
            }
        }
    }
}
int main()
{
    int **a = NULL, **b = NULL, **c = NULL;
    a = matralloc(a, 4, 4);
    b = matralloc(b, 4, 4);
    c = matralloc(c, 4, 4);
    zero = matralloc(zero, 4, 4);
    printf("Enter the elements of m1.\n");
    accept(a, 4, 4);
    printf("Enter the elements of m2.\n");
    accept(b, 4, 4);
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
            *(*(zero + i) + j) = 0;
    }
    strassen(a, b, c, 4, 4);
    printf("The elements of multiplied matrix are:\n");
    display(c, 4, 4);
    return 0;
}