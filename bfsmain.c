#include <stdio.h>

void merge(int a[], int low, int high);
void mergesort(int a[], int low, int mid, int high);
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
    merge(a, 0, n - 1);
    printf("sorted array:\t");
    for (i = 0; i < n; i++)
    {
        // printf("element at the index %d:",i);
        printf("%d ", a[i]);
    }
    printf("\n");
}

void merge(int a[], int low, int high)
{
    if (low < high)
    {
        int mid = (high + low) / 2;
        merge(a, low, mid);
        merge(a, mid + 1, high);
        mergesort(a, low, mid, high);
    }
}

void mergesort(int a[], int low, int mid, int high)
{
    int i, j, k;
    int t[30];
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
        if (a[i] <= a[j])
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

    while (i <= mid)
    {
        t[k] = a[i];
        k++;
        i++;
    }

    while (j <= high)
    {
        t[k] = a[j];
        k++;
        j++;
    }

    for (i = low; i <= high; i++)
    {
        a[i] = t[i];
    }
}
