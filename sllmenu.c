#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
//----------------------------------prototypes-------------------------------
struct node *createNode(int data);
void traverse(struct node *head);
struct node *deletebeg(struct node *head);
struct node *deleteindex(struct node *head, int index);
struct node *deletionend(struct node *head);
struct node *insertbeg(struct node *head, int n, int data);
struct node *insertionatindex(struct node *head, int index, int data);
struct node *insertatend(struct node *head, int data);
struct node *reversal(struct node *head);
//----------------------------------nodal creation----------------------------
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
//----------------------------nodal traversal-------------------------------
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
//-----------------------delete the beginning node-------------------------
struct node *deletebeg(struct node *head)
{
    struct node *ptr = head;
    struct node *ptr1;
    ptr1 = ptr->next;
    head = ptr1;
    return head;
}
//------------------------delete the index node---------------------------
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
//---------------------deletion at end----------------------------------------------
struct node *deletionend(struct node *head)
{
    struct node *ptr;
    ptr = head;
    while (ptr->next->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = NULL;
    return head;
}
//----------------------------------insertion at beginnig-----------------------------
struct node *insertbeg(struct node *head, int n, int data)
{
    struct node *ptr = createNode(data);
    ptr->next = head;
    head = ptr;
    return head;
}

//-----------------------------------insertion at index------------------------------
struct node *insertionatindex(struct node *head, int index, int data)
{
    int i = 1;
    struct node *ptr = head;
    struct node *ptrstandby = head;
    struct node *ptr1;
    ptr1 = createNode(data);
    struct node *ptr2;
    while (i != index - 1)
    {
        ptr = ptr->next;
        i++;
    }
    ptr2 = ptr->next;
    ptr->next = ptr1;
    ptr1->next = ptr2;
    return ptrstandby;
}
//-------------------insertion at end code-------------------------------------------
struct node *insertatend(struct node *head, int data)
{
    struct node *ptr = head;
    struct node *ptr2 = createNode(data);
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = ptr2;
    return head;
}
//---------------------------------------------------------------------------------------
struct node *reversal(struct node *head)
{
    struct node *ptr = head;
    struct node *prev = NULL;
    struct node *current = ptr;
    struct node *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    ptr = prev;
    return ptr;
}

int main()
{
    int n;
    int data;
    printf("please enter the number of nodes to insert:");
    scanf("%d", &n);
    struct node *ptr[n];
    for (int i = 0; i < n; i++)
    {
        printf("please enter the data in the node %d:", i);
        scanf("%d", &data);
        ptr[i] = createNode(data);
    }
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
        {
            ptr[i]->next = NULL;
        }
        else
        {
            ptr[i]->next = ptr[i + 1];
        }
    }
    int choice;
    struct node *newhead = NULL;
    printf("please enter the choice among the following to perform the operations:\n");
    do
    {
        printf("1)insert at beginning\n2)insert at index\n3)insert at end\n4)delete first node\n5)delete the node at index\n6)delete end node\n7)traverse the list\n8)reverse list\n9)exit\n");
        printf("enter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {

            printf("please enter the data of the node to be created:");
            int newdata;
            scanf("%d", &newdata);
            struct node *newhead = insertbeg(ptr[0], n, newdata);
        }
        break;

        case 2:
        {

            printf("please enter the index to insert the node at:");
            int index;
            scanf("%d", &index);
            printf("please enter the data to be inserted in the node:");
            int newdata;
            scanf("%d", &newdata);
            struct node *newhead;
            newhead = insertionatindex(ptr[0], index, newdata);
        }
        break;

        case 3:
        {

            printf("please enter the data to be inserted:");
            int newdata;
            scanf("%d", &newdata);
            struct node *newhead = insertatend(ptr[0], newdata);
        }
        break;

        case 4:
        {

            struct node *newhead;
            newhead = deletebeg(ptr[0]);
        }
        break;

        case 5:
        {

            printf("please enter the index to be deleted:");
            int index;
            scanf("%d", &index);
            struct node *newhead;
            newhead = deleteindex(ptr[0], index);
        }
        break;

        case 6:
        {

            struct node *newhead;
            newhead = deletionend(ptr[0]);
        }
        break;

        case 7:
        {
            newhead = ptr[0];
            traverse(newhead);
        }
        break;

        case 8:

        {
            newhead = ptr[0];
            newhead = reversal(newhead);
            traverse(newhead);
        }
        break;

        case 9:
        {
            printf("exitting the rogramme");
        }
        break;

        default:
        {
            printf("enter a valid choice.....");
        }
        break;
        }

    } while (choice != 9);

    return 0;
}