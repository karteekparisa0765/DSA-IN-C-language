#include <stdio.h>
#include <stdlib.h>
int main()
{
    printf("please enter the size of the array:");
    int n;
    scanf("%d", &n);
    printf("please enter the array elements for sorting:\n");
    int array[n];
    for (int i = 0; i < n; i++)
    {
        printf("please enter the element at %d:", i);
        scanf("%d", &array[i]);
    }
    int temp;
//initiating bubble sort:
    // sorted array of the input array:
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (array[j] >array[j+1])
            {
                temp = array[j];
                array[j] = array[j+1]; // swapping the element to put in a increasing order:
                array[j+1] = temp;
            }
        }
    }
    printf("the sorted Array is :");
    for (int i = 0; i < n; i++)
    {if(i==(n-1)){
                printf("%d-->end", array[i]);

    }
    else{

        printf("%d-->", array[i]);
    }
    }

    return 0;
}