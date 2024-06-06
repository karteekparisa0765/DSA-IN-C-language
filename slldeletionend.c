#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *createnode(int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=NULL;
    return ptr;
}
struct node *deletionend(struct node *head){
    struct node *ptr;
    ptr=head;
    while(ptr->next->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=NULL;
    return head;

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
    int n;
    int data;
    printf("please enter the number of nodes:");
    scanf("%d", &n);
    struct node *ptr[n];
    for (int i = 0; i < n; i++)
    {
        printf("please enter the data:");
        scanf("%d", &data);
        ptr[i] = createnode(data);
    }
    //linking nodes
    for (int i = 0; i < n; i++)
    {
        if(i==(n-1)){
            ptr[i]->next=NULL;
        }
        else{
            ptr[i]->next=ptr[i+1];

        }
    }
    struct node *newhead;
    newhead=deletionend(ptr[0]);
    traverse(newhead);

    return 0;
}