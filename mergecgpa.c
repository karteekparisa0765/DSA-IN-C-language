#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node
{
    char name[30];
} NODE;

void mergesort(NODE a[], int low, int high);
void merge(NODE a[], int low, int mid, int high);

int main()
{
    int n;
    printf("enter the no of elements:");
    scanf("%d", &n);
    NODE a[n];
    for (int i = 0; i < n; i++)
    {
        getchar();
        printf("Enter the name:");
        scanf("%s", &a[i].name);
    }
    printf("\nUnsorted array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d.", i + 1);
        printf("%s\n", a[i].name);
    }
    mergesort(a, 0, n - 1);
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d.", i + 1);
        printf("%s\n", a[i].name);
    }
}

void mergesort(NODE a[], int low, int high)
{
    if (low < high)
    {
        int mid = (high + low) / 2;
        mergesort(a, 0, mid);
        mergesort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

void merge(NODE a[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = low;
    NODE t[30];
    while (i <= mid && j <= high)
    {
        if (strlen(a[i].name) >= strlen(a[j].name))
        {
            strcpy(t[k].name, a[j].name);
            j++;
        }
        else
        {
            strcpy(t[k].name, a[i].name);
            i++;
        }
        k++;
    }
    while (i <= mid)
    {
        strcpy(t[k].name, a[i].name);
        i++, k++;
    }
    while (j <= high)
    {
        strcpy(t[k].name, a[j].name);
        j++, k++;
    }
    for (int i = low; i <= high; i++)
    {
        strcpy(a[i].name, t[i].name);
    }
}