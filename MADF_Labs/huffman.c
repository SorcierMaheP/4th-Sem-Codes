#include <stdio.h>
#include <stdlib.h>
#define MAX 100
struct minnode
{
    char item;
    int freq;
    struct minnode *left, *right;
};

struct minheap
{
    int size;
    int capacity;
    struct minnode **array;
};

struct minnode *newnode(char item, int freq)
{
    struct minnode *temp = (struct minnode *)malloc(sizeof(struct minnode));
    temp->left = temp->right = NULL;
    temp->item = item;
    temp->freq = freq;
    return temp;
}

struct minheap *createminheap(int capacity)
{
    struct minheap *heap = (struct minheap *)malloc(sizeof(struct minheap));
    heap->size = 0;
    heap->capacity = capacity;
    heap->array = (struct minnode **)malloc(heap->capacity * sizeof(struct minnode *));
    return heap;
}

void swap(struct minnode **a, struct minnode **b)
{
    struct minnode *t = *a;
    *a = *b;
    *b = t;
}

void heapify(struct minheap *heap, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < heap->size && heap->array[left]->freq < heap->array[smallest]->freq)
        smallest = left;
    if (right < heap->size && heap->array[right]->freq < heap->array[smallest]->freq)
        smallest = right;
    if (smallest != i)
    {
        swap(&heap->array[smallest], &heap->array[i]);
        heapify(heap, smallest);
    }
}

struct minnode *extractmin(struct minheap *heap)
{
    struct minnode *temp = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;
    heapify(heap, 0);
    return temp;
}

void insertminheap(struct minheap *heap, struct minnode *minhnode)
{
    heap->size++;
    int i = heap->size - 1;
    while (i && minhnode->freq < heap->array[(i - 1) / 2]->freq)
    {
        heap->array[i] = heap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    heap->array[i] = minhnode;
}

void buildminheap(struct minheap *heap)
{
    int n = heap->size - 1;
    int i;
    for (i = (n - 1) / 2; i >= 0; i--)
        heapify(heap, i);
}

int isLeaf(struct minnode *root)
{
    return !(root->left) && !(root->right);
}

struct minheap *constructminheap(char item[], int freq[], int size)
{
    struct minheap *heap = createminheap(size);
    for (int i = 0; i < size; ++i)
        heap->array[i] = newnode(item[i], freq[i]);
    heap->size = size;
    buildminheap(heap);
    return heap;
}

struct minnode *buildHuffman(char item[], int freq[], int size)
{
    struct minnode *left, *right, *top;
    struct minheap *heap = constructminheap(item, freq, size);
    while (!(heap->size == 1))
    {
        left = extractmin(heap);
        right = extractmin(heap);
        top = newnode('!', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertminheap(heap, top);
    }
    return extractmin(heap);
}

void printarr(int arr[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
        printf("%d", arr[i]);
    printf("\n");
}

void printhuffcodes(struct minnode *root, int arr[], int top)
{
    // Assigning 0 or 1 based on left child or right child.
    if (root->left)
    {
        arr[top] = 0;
        printhuffcodes(root->left, arr, top + 1);
    }
    if (root->right)
    {
        arr[top] = 1;
        printhuffcodes(root->right, arr, top + 1);
    }
    if (isLeaf(root))
    {
        printf("  %c  : ", root->item);
        printarr(arr, top);
    }
}

void Huffman(char item[], int freq[], int size)
{
    struct minnode *root = buildHuffman(item, freq, size);
    int arr[MAX], top = 0;
    printhuffcodes(root, arr, top);
}

int main()
{
    char str[] = {'A', 'B', 'C', 'D', 'E'};
    int freq[] = {1, 2, 3, 4, 5};
    int size = sizeof(str) / sizeof(str[0]);
    Huffman(str, freq, size);
    return 0;
}