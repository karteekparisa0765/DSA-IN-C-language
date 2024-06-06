#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void traverse(struct node *head);
struct node *createNode(int data);
struct node *deletend(struct node *head, int index);

struct node *createNode(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (!newNode)
    {
        // Handle memory allocation failure
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
struct node *deleteindex(struct node *head, int index)
{
    struct node *ptr = head;
    int i = 1;
    while (i != index - 1)
    {
        ptr = ptr->next;
        i++;
    }
    struct node *ptr1;
    struct node *ptr2;
    ptr1 = ptr->next;
    ptr2 = ptr1->next;
    ptr->next = ptr2;
    return head;
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
    int n;
    int data;
    printf("please enter the number of nodes to be inserted:");
    scanf("%d", &n);
    struct node *ptr[n];
    for (int i = 0; i < n; i++)
    {
        printf("please enter the data to be inserted in node '%d':", i);
        scanf("%d", &data);
        ptr[i] = createNode(data);
    }
    for (int i = 0; i < n; i++)
    {
        if (i == (n - 1))
        {
            ptr[i]->next = NULL;
        }

        else
        {
            ptr[i]->next = ptr[i + 1];
        }
    }
    printf("please enter the index to be deleted:");
    int index;
    scanf("%d", &index);
    struct node *newhead;
    newhead = deleteindex(ptr[0],index);
    traverse(newhead);

    return 0;
}