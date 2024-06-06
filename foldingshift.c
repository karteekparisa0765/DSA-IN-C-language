#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    int data;
    struct node *next;
};
void traverse(struct node *head)
;
struct node *createnode(int data){
    struct node *nn=(struct node *)malloc(sizeof(struct node));
    nn->data=data;
    nn->next=NULL;
    return nn;
}
int hashfunction(struct node *head, int n)
{int sum=0;
    while (n != 0)
    {
        int rem = n % 10;
        n=n/10;
        sum=sum+rem;
        struct node*nn=createnode(rem);
        if(head==NULL){
            head=nn;
        }
        else{
            struct node *temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=nn;
        }

    }
    traverse(head)  ;
    return sum;
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
    struct node *head = NULL;
    printf("enter the number:");
    int n;
    scanf("%d", &n);
    int x = hashfunction(head, n);
    printf("%d",x);
    return 0;
}