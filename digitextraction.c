#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    int data;
    struct node *next;
};
void traverse(struct node *head);
struct node *createnode(int data)
{
    struct node *nn = (struct node *)malloc(sizeof(struct node));
    nn->data = data;
    nn->next = NULL;
    return nn;
}
int hashfunction(int number)
{
    int rem = 0;
    int count = 0;
    int array[10];
    int i = 0;
    while (number != 0)
    {
        rem = number % 10;
        number = number / 10;
        count++;
        array[i] = rem;
        i++;
    }
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < count; j++)
        {
            // Swap if the element found is greater than the next element
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    int result = 0;
    for (int i = 0; i < count; i = i + 2)
    {
        result = result * 10 + array[i];
    }
    return result;
}
void traverse(struct node *head)
{
    struct node *ptr;
    ptr = head;
    while (ptr != NULL)
    {
        if (ptr->next == NULL)
        {
            printf("%d --> NULL\n", ptr->data);
        }
        else
        {
            printf("%d --> ", ptr->data);
        }
        ptr = ptr->next;
    }
}

int main()
{
    struct node *head = NULL;
    printf("enter the number:");
    int n;
    scanf("%d", &n);
    int x = hashfunction(n);
    printf("%d", x);
    return 0;
}