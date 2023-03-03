#include<stdio.h>
#include<stdlib.h>
void accept(int a[][10],int rows,int columns)
{
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
            scanf("%d",&a[i][j]);
    }
}
void display(int a[][10],int rows,int columns)
{
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}
void strassen(int a[][10],int b[][10],int c[][10],int rows,int columns)
{
    int p,q,r,s,t,u,v;
    p=(a[0][0]+a[1][1])*(b[0][0]+b[1][1]);
    q=(a[1][0]+a[1][1])*(b[0][0]);
    r=(a[0][0])*(b[0][1]-b[1][1]);
    s=(a[1][1])*(b[1][0]-b[0][0]);
    t=(a[0][0]+a[0][1])*(b[1][1]);
    u=(a[1][0]-a[0][0])*(b[0][0]+b[0][1]);
    v=(a[0][1]-a[1][1])*(b[1][0]+b[1][1]);
    c[0][0]=p+s-t+v;
    c[0][1]=r+t;
    c[1][0]=q+s;
    c[1][1]=p+r-q+u;
}
int main()
{
    int a[10][10],b[10][10],c[10][10];
    printf("Enter the elements of m1.\n");
    accept(a,2,2);
    printf("Enter the elements of m2.\n");
    accept(b,2,2);
    strassen(a,b,c,2,2);
    printf("The elements of multiplied matrix are:\n");
    display(c,2,2);
    return 0;
}