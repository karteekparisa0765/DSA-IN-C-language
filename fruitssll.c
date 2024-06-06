#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    char fruit[100];
    char colour[100];
    char vitamin[1];
    int number;
    struct node *next;
};
struct node *createnode(char *fruit, char *colour, char *vitamin, int number)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    strcpy(ptr->colour, colour);
    strcpy(ptr->fruit, fruit);
    strcpy(ptr->vitamin, vitamin);
    ptr->number = number;
    ptr->next = NULL;
    return ptr;
}
void traverse(struct node *head)
{
    struct node *ptr;
    ptr = head;
    while (ptr != NULL)
    {
        if (ptr->next == NULL)
        {
            printf("name:%s--colour:%s--vit:%s--%d-->NULL", ptr->fruit, ptr->colour, ptr->vitamin, ptr->number);
        }
        else
        {
            printf("name:%s--colour:%s--vit:%s--%d-->", ptr->fruit, ptr->colour, ptr->vitamin, ptr->number);
        }
        ptr = ptr->next;
    }
}

int main()
{
    int n;
    printf("please enter the types of fruits you have:");
    scanf("%d", &n);
    char fruit[100];
    char colour[100];
    char vitamin[1];
    int number;
    struct node *fruits[n];
    for (int i = 0; i < n; i++)
    {
        printf("please enter the name of the fruit:");
        scanf("%s", fruit);
        printf("please enter the colour of the fruit:");
        scanf("%s", colour);
        printf("please enter the vitamin found in fruit:");
        scanf("%s", &vitamin);
        printf("please enter the number of fruits you have:");
        scanf("%d", &number);
        fruits[i] = createnode(fruit, colour, vitamin, number);
    }

    // linking the nodes
    for (int i = 0; i < n; i++)
    {
        if (i == (n - 1))
        {
            fruits[i]->next = NULL;
        }
        else
        {
            fruits[i]->next = fruits[i + 1];
        }
    }
    struct node *head = fruits[0];
    char fruitsearch[100];
    printf("please enter the fruit you want to search:");
    scanf("%s", fruitsearch);
    struct node *ptr = head;
    while (ptr != NULL)
    {
        if (strcmp(ptr->fruit,fruitsearch)==0)
        {
            printf("fruit is found inside the basket...");
            printf("fruit qty:%d", ptr->number);
            printf("fruit colour:%s", ptr->colour);
            printf("vit found:%s", ptr->vitamin);
        }
        else if (ptr == NULL)
        {
            printf("fruit is not found in the basket...");
        }
        
            ptr = ptr->next;
        }
        return 0;
    }