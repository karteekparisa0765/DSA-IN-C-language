#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void traverse(struct node *head);
struct node *createNode(int data);
struct node *reversal(struct node *head);
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
struct node *reversal(struct node *head){
    struct node *ptr1=head;
    struct node *current=head;
    struct node *prev=NULL;
    struct node *next=NULL;
    while(current!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    ptr1=prev;
    return ptr1;
}
void traverse(struct node *head)
{
    struct node *ptr;
    ptr = head;
    while (ptr != NULL)
    {
        if (ptr->next == NULL) {
            printf("%d --> NULL\n", ptr->data);
        }
        else {
            printf("%d --> ", ptr->data);
        }
        ptr = ptr->next;
    }
}

int main()
{
    printf("please enter the size of the number 1:");
    int n1, n2;
    scanf("%d", &n1);
    printf("please enter the size of the number 2:");
    scanf("%d", &n2);
    struct node *ptr1[n1];
    struct node *ptr2[n2];
    printf("enter for the number 1:\n");
    int data;
    for (int i = 0; i < n1; i++)
    {
        printf("please enter the digit into node %d:", i);
        scanf("%d", &data);
        ptr1[i] = createNode(data);
    }
    // linking the nodes in the number 1:
    for (int i = 0; i < n1; i++)
    {
        if (i == (n1 - 1))
        {
            ptr1[i]->next = NULL;
        }
        else
        {
            ptr1[i]->next = ptr1[i + 1];
        }
    }
    printf("enter for number 2:\n");
    for (int i = 0; i < n2; i++)
    {
        printf("please enter the digit into node %d:", i);
        scanf("%d", &data);
        ptr2[i] = createNode(data);
    }
    //linking the nodes in number 2:
    for (int i = 0; i < n2; i++)
    {
        if (i == (n2 - 1))
        {
            ptr2[i]->next = NULL;
        }
        else
        {
            ptr2[i]->next = ptr2[i + 1];
        }
    }
    struct node *NH1,*NH2;
ptr1[0]=reversal(ptr1[0]);
ptr2[0]=reversal(ptr2[0]);
traverse(ptr1[0]);
printf("\n");
traverse(ptr2[0]);


//code for designing the final linked list after adding all the terms
// code for designing the final linked list after adding all the terms
int n3;
if (n1 > n2) {
    n3 = n1;
} else {
    n3 = n2;
}
// Code for designing the final linked list after adding all the terms
struct node *ptr3[n3];
int data3;
struct node *head1;
struct node *head2;
head1 = ptr1[0];
head2 = ptr2[0];
int i = 0;
while (head1 != NULL || head2 != NULL)
{
    if (head1 == NULL)
    {
        data3 = head2->data;
        head2 = head2->next;
    }
    else if (head2 == NULL)
    {
        data3 = head1->data;
        head1 = head1->next;
    }
    else
    {
        data3 = head1->data + head2->data;
        head1 = head1->next;
        head2 = head2->next;
    }
    ptr3[i] = createNode(data3);
    i++;
}

for (int i = 0; i < n3; i++)
{
    if (i == (n3 - 1))
    {
        ptr3[i]->next = NULL;
    }
    else
    {
        ptr3[i]->next = ptr3[i + 1];
    }
}

traverse(ptr3[0]);


  return 0;
}