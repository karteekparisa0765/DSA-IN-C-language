#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void merge(int *a, int low, int mid, int high);
void mergesort(int *a, int low, int high);

void mergesort(int *a, int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergesort(a, low, mid);
        mergesort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}
void merge(int *a, int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = 0;
    int t[30];
    while (i <= mid && j <= high)
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

    while (j <= high)
    {
        t[k] = a[j];
        j++;
        k++;
    }
    while (i <= mid)
    {
        t[k] = a[i];
        i++;
        k++;
    }
    for (int i = low; i <= high; i++)
    {
        a[i] = t[i - low];
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

    return 0;
}