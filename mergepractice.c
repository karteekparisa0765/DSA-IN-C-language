#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void merge(int *a, int l, int mid, int h);
void mergesort(int *a, int l, int h)
{

    if (l < h)
    {
        int mid = (l + h) / 2;
        mergesort(a, l, mid);
        mergesort(a, mid + 1, h);
        merge(a, l, mid, h);
    }
}

void merge(int *a, int l, int mid, int h)
{
    int i = l;
    int j = mid + 1;
    int k = 0;
    int t[30];
    while (i <= mid && j <= h)
    {
        if (a[i] < a[j])
        {
            t[k] = a[i];
            i++;
        }
        else
        {
            t[k] = a[j];
            j++;
        }
        k++;
    }
    while (j <= h)
    {
        t[k] = a[j];
        k++;
        j++;
    }
    while (i <= mid)
    {
        t[k] = a[i];
        k++;
        i++;
    }
    for (int i = l; i <= h; i++) // Corrected the loop here
    {
        a[i] = t[i - l];
    }
}

int main()
{
    int i, n, a[30];
    printf("enter the limit:");
    scanf("%d", &n);
    printf("\n");
    for (i = 0; i < n; i++)
    {
        printf("element at the index %d:", i);
        scanf("%d", &a[i]);
    }
    printf("\n");
    printf("unsorted array:\t");
    for (i = 0; i < n; i++)
    {
        // printf("element at the index %d:",i);
        printf("%d ", a[i]);
    }
    printf("\n");
    mergesort(a, 0, n - 1);
    printf("sorted array:\t");
    for (i = 0; i < n; i++)
    {
        // printf("element at the index %d:",i);
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}