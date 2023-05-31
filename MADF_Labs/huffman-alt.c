#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 200
int greatest = 0;

struct node
{
    int freq;
    char ch;
    struct node *next, *left, *right;
} *start = NULL;

void add_at_end(char c[], int f[], int n)
{
    for (int i = 0; i < n; i++)
    {

        if (start == NULL)
        {
            start = (struct node *)malloc(sizeof(struct node));
            start->ch = c[i], start->freq = f[i], start->next = NULL, start->left = NULL, start->right = NULL;
        }
        else
        {
            struct node *ptr = start;
            while (ptr->next != NULL)
                ptr = ptr->next;
            struct node *temp = (struct node *)malloc(sizeof(struct node));
            temp->ch = c[i], temp->freq = f[i];
            temp->next = temp->left = temp->right = NULL, ptr->next = temp;
        }
    }
}
void show()
{
    struct node *ptr = start;
    while (ptr != NULL)
    {
        printf("(%c, %d), ", ptr->ch, ptr->freq);
        ptr = ptr->next;
    }
    printf("\n");
}

struct node *del_front()
{
    struct node *temp = start;
    start = start->next;
    return temp;
}

void add_after(struct node *temp)
{
    if (start == NULL)
        start = temp;
    else if (start->next == NULL)
    {
        if (temp->freq < start->freq)
        {
            temp->next = start;
            start = temp;
        }
        else
        {
            temp->next = start->next;
            start->next = temp;
        }
    }
    else
    {
        int found = 0;
        struct node *posn, *ptr = start;
        while (ptr != NULL)
        {
            if (ptr->freq == temp->freq)
            {
                found = 1;
                posn = ptr;
                break;
            }
            ptr = ptr->next;
        }
        ptr = start;
        if (found)
        {
            struct node *ptr = posn;
            while (ptr->next->freq == temp->freq && ptr->next != NULL)
                ptr = ptr->next;
            temp->next = ptr->next;
            ptr->next = temp;
        }
        else
        {
            ptr = start;
            while (ptr->next->freq <= temp->freq && ptr != NULL)
                ptr = ptr->next;
            if (ptr != NULL)
            {
                temp->next = ptr->next;
                ptr->next = temp;
            }
            else
            {
                ptr = start;
                while (ptr->next != NULL)
                    ptr = ptr->next;
                temp->next = ptr->next;
                ptr->next = temp;
            }
        }
    }
}

void insert_end(struct node *temp)
{
    if (start == NULL)
        temp->next = NULL, start = temp;
    else
    {
        struct node *ptr = start;
        while (ptr->next != NULL)
            ptr = ptr->next;
        temp->next = ptr->next;
        ptr->next = temp;
    }
}

void greatest_freq()
{
    struct node *ptr = start;
    while (ptr->next != NULL)
        ptr = ptr->next;
    greatest = ptr->freq;
}

void Huffman()
{
    if (!start)
        return;
    while (start->next != NULL)
    {
        struct node *a = del_front(), *b = del_front(), *temp;
        temp = (struct node *)malloc(sizeof(struct node));
        temp->ch = '$';
        temp->freq = a->freq + b->freq;
        temp->left = a, temp->right = b, temp->next = NULL;
        if (temp->freq >= greatest)
        {
            greatest = temp->freq;
            insert_end(temp);
        }
        else
            add_after(temp);
        show();
        printf("\n");
    }
}

void printcodes(struct node *root, int path[], int stringlen)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
    {
        for (int i = 0; i < stringlen; i++)
            printf("%d", path[i]);
        printf("\t%c\n", root->ch);
    }
    // left child
    path[stringlen] = 0;
    printcodes(root->left, path, stringlen + 1);
    // right child
    path[stringlen] = 1;
    printcodes(root->right, path, stringlen + 1);
}

int main()
{
    char arr[17] = {'j', 'f', 'a', 'r', 'g', 'l', 'm', 's', 'h', 'p', 'o', 'n', 'e', 'i', 't', ' '};
    int freq[17] = {1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 4, 4, 5, 6, 6, 7};
    printf("The string is:\n");
    printf("j is the position of the partitioning element");
    printf("\n\n");
    add_at_end(arr, freq, strlen(arr));
    show();
    greatest_freq();
    Huffman();
    int path[MAX];
    printf("Huffman Codes:\n");
    printcodes(start, path, 0);
    return 0;
}
