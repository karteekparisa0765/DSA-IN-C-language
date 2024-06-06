#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
// function prototypes
void traverse(struct node *head);
struct node *createnode(int data);
struct node *insertionatend(struct node *head, int index, int data);

//---------------------------------------------nodal creation-----------------------------------------------------------
struct node *createnode(int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = NULL;
    return ptr;
}
//--------------------------insertion at index---------------------------------------------------------------------------
struct node *insertionatindex(struct node *head, int index, int data)
{
    int i = 1;
    struct node *ptr = head;
    struct node *ptrstandby = head;
    struct node *ptr1;
    ptr1 = createnode(data);
    struct node *ptr2;
    while (i != index - 1)
    {
        ptr = ptr->next;
        i++;
    }
    ptr2=ptr->next;
    ptr->next=ptr1;
    ptr1->next=ptr2;
    return ptrstandby;
}

//---------traversal function-------------------------------------------------------------------
void traverse(struct node *head)
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
        if (ptr->next == NULL)
        {
            printf("%d-->NULL", ptr->data);
        }
        else
        {
            printf("%d-->", ptr->data);
        }

        ptr = ptr->next;
    }
}
//-------------------------------------------------------------------------------
int main()
{
    int n;
    int data;
    printf("please enter the number of nodes to create:");
    scanf("%d", &n);
    struct node *ptr[n];
    //-------------------------data entering into nodes--------------
    for (int i = 0; i < n; i++)
    {
        printf("please enter the data of the node '%d':", i);
        scanf("%d", &data);
        ptr[i] = createnode(data);
    }
    //---------------------linking the nodes------------------------
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
    printf("please enter the index to insert the node at:");
    int index;
    scanf("%d", &index);
    printf("please enter the data to be inserted in the node:");
    int newdata;
    scanf("%d", &newdata);
    struct node *newhead;
    newhead = insertionatindex(ptr[0], index, newdata);
    traverse(newhead);
    return 0;
}