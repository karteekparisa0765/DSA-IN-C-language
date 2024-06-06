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
int hashfunction(int n)
{
    int rem = 0;
    int count = 0;
    int array[10];
    int i = 0;
    while (n != 0)
    {
        rem = n % 100;
        n = n / 100;
        array[i] = rem;
        count++;
        i++;
    }
    int result = 0;
    for (int j = 0; i < count; i++)
    {
        result = result * 100 + array[i];
    }
    n = result;
    rem = 0;
    i = 0;
    int newarray[count];
    while (n != 0&&i<count)
    {
        rem = n % 100;
        n = n / 100;
        newarray[i] = rem;
        count++;
        i++;
    }
    int sum = 0;
    
    int newarray1[10];
    for (int i = 0; i < count; i++)
    {
        if (i != (count / 2))
        {
            int n = newarray[i];
            int rem = 0;
            int ncount = 0;
            int i = 0;

            while (n != 0)
            {
                rem = n % 10;
                n = n / 10;
                newarray1[i] = rem;
                ncount++;
                i++;
            }
            int result = 0;
            for (int j = 0; i < ncount; i++)
            {
                result = result * 10 + newarray1[i];
            }
            n = result;
            array[i] = n;
            sum = sum + n;
            
        }
        sum = sum + array[count / 2];
    }
    return sum;
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