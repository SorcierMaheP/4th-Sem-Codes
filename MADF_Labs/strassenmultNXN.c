#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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
void display(int **a, int rows, int columns, int width)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("%*d ", width, *(*(a + i) + j));
        }
        printf("\n");
    }
}
void padding(int **a, int m, int n)
{
    if (m != n)
    {
        for (int i = m; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                *(*(a + i) + j) = 0;
        }
        for (int j = m; j < n; j++)
        {
            for (int i = 0; i < n; i++)
                *(*(a + i) + j) = 0;
        }
    }
}
int **sum(int **a, int **b, int **c, int r1, int c1, int r2, int c2, int incr)
{
    for (int i = r1, l = 0, p = r2; i < r1 + incr; i++, l++, p++)
    {
        for (int j = c1, m = 0, q = c2; j < c1 + incr; j++, m++, q++)
            *(*(c + l) + m) = *(*(a + i) + j) + *(*(b + p) + q);
    }
    return c;
}
int **sub(int **a, int **b, int **c, int r1, int c1, int r2, int c2, int incr)
{
    for (int i = r1, l = 0, p = r2; i < r1 + incr; i++, l++, p++)
    {
        for (int j = c1, m = 0, q = c2; j < c1 + incr; j++, m++, q++)
            *(*(c + l) + m) = *(*(a + i) + j) - *(*(b + p) + q);
    }
    return c;
}
int **part(int **a, int **b, int r1, int c1, int incr)
{
    for (int i = r1, l = 0; i < r1 + incr; i++, l++)
    {
        for (int j = c1, m = 0; j < c1 + incr; j++, m++)
            *(*(b + l) + m) = *(*(a + i) + j);
    }
    return b;
}
void strassen(int **a, int **b, int **c, int rows, int columns)
{
    if (rows == 1 && columns == 1)
        c[0][0] = a[0][0] * b[0][0];
    else if (rows == 2 && columns == 2)
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
        temp1 = matralloc(temp1, rows / 2, columns / 2);
        temp2 = matralloc(temp2, rows / 2, columns / 2);
        int **p = NULL, **q = NULL, **r = NULL, **s = NULL, **t = NULL, **u = NULL, **v = NULL;
        p = matralloc(p, rows / 2, columns / 2);
        q = matralloc(q, rows / 2, columns / 2);
        r = matralloc(r, rows / 2, columns / 2);
        s = matralloc(s, rows / 2, columns / 2);
        t = matralloc(t, rows / 2, columns / 2);
        u = matralloc(u, rows / 2, columns / 2);
        v = matralloc(v, rows / 2, columns / 2);
        strassen((temp1 = sum(a, a, temp1, 0, 0, rows / 2, columns / 2, rows / 2)), (temp2 = sum(b, b, temp2, 0, 0, rows / 2, columns / 2, rows / 2)), p, rows / 2, columns / 2);
        strassen((temp1 = sum(a, a, temp1, rows / 2, 0, rows / 2, columns / 2, rows / 2)), (temp2 = part(b, temp2, 0, 0, rows / 2)), q, rows / 2, columns / 2);
        strassen((temp1 = part(a, temp1, 0, 0, rows / 2)), (temp2 = sub(b, b, temp2, 0, columns / 2, rows / 2, columns / 2, rows / 2)), r, rows / 2, columns / 2);
        strassen((temp1 = part(a, temp1, rows / 2, columns / 2, rows / 2)), (temp2 = sub(b, b, temp2, rows / 2, 0, 0, 0, rows / 2)), s, rows / 2, columns / 2);
        strassen((temp1 = sum(a, a, temp1, 0, 0, 0, columns / 2, rows / 2)), (temp2 = part(b, temp2, rows / 2, columns / 2, rows / 2)), t, rows / 2, columns / 2);
        strassen((temp1 = sub(a, a, temp1, rows / 2, 0, 0, 0, rows / 2)), (temp2 = sum(b, b, temp2, 0, 0, 0, columns / 2, rows / 2)), u, rows / 2, columns / 2);
        strassen((temp1 = sub(a, a, temp1, 0, columns / 2, rows / 2, columns / 2, rows / 2)), (temp2 = sum(b, b, temp2, rows / 2, 0, rows / 2, columns / 2, rows / 2)), v, rows / 2, columns / 2);
        int **c00 = NULL, **c01 = NULL, **c10 = NULL, **c11 = NULL;
        c00 = matralloc(c00, rows / 2, columns / 2);
        c01 = matralloc(c01, rows / 2, columns / 2);
        c10 = matralloc(c10, rows / 2, columns / 2);
        c11 = matralloc(c11, rows / 2, columns / 2);
        c00 = sum(temp2 = sub(temp1 = (sum(p, s, temp1, 0, 0, 0, 0, rows / 2)), t, temp2, 0, 0, 0, 0, rows / 2), v, c00, 0, 0, 0, 0, rows / 2);
        c01 = sum(r, t, c01, 0, 0, 0, 0, rows / 2);
        c10 = sum(q, s, c10, 0, 0, 0, 0, rows / 2);
        c11 = sum(temp2 = sub(temp1 = (sum(p, r, temp1, 0, 0, 0, 0, rows / 2)), q, temp2, 0, 0, 0, 0, rows / 2), u, c11, 0, 0, 0, 0, rows / 2);
        free(p);
        free(q);
        free(r);
        free(s);
        free(t);
        free(u);
        free(v);
        free(temp1);
        free(temp2);
        for (int i = 0; i < rows / 2; i++)
        {
            for (int j = 0; j < columns / 2; j++)
            {
                *(*(c + i) + j) = *(*(c00 + i) + j);
                *(*(c + i) + j + columns / 2) = *(*(c01 + i) + j);
                *(*(c + i + rows / 2) + j) = *(*(c10 + i) + j);
                *(*(c + i + rows / 2) + j + columns / 2) = *(*(c11 + i) + j);
            }
        }
        free(c00);
        free(c01);
        free(c10);
        free(c11);
    }
}
int main()
{
    int m, n;
    printf("Enter the order of the matrices.\n");
    scanf("%d", &m);
    int **a = NULL, **b = NULL, **c = NULL;
    if (ceil(log2(m)) == floor(log2(m)))
        n = m;
    else
        n = pow(2, ceil(log2(m)));
    a = matralloc(a, n, n);
    b = matralloc(b, n, n);
    c = matralloc(c, n, n);
    printf("Enter the elements of m1.\n");
    accept(a, m, m);
    printf("Enter the elements of m2.\n");
    accept(b, m, m);
    padding(a, m, n);
    padding(b, m, n);
    strassen(a, b, c, n, n);
    int w;
    printf("Enter the display width for the resultant matrix elements.\n");
    scanf("%d", &w);
    printf("The elements of multiplied matrix are:\n");
    display(c, n, n, w);
    free(a);
    free(b);
    free(c);
    return 0;
}