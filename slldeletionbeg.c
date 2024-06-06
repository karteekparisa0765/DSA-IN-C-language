#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;

};
struct node *createnode(int data){
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=NULL;
    return ptr;
}
struct node *deletebeg(struct node *head){
    struct node *ptr=head;
    struct node *ptr1;
    ptr1=ptr->next;
    head=ptr1;
    return head;
}
void traverse(struct node *head){
    struct node *ptr;
    ptr=head;
    while (ptr!=NULL)
    {if(ptr->next==NULL){
        printf("%d--> NULL",ptr->data);
    }
    else{
        printf("%d--> ",ptr->data);
    }
    ptr=ptr->next;
    }
    
}
int main()
{
    int n;
    printf("please enter the number of nodes to insert:");
    scanf("%d",&n);
    int data;
    struct node *ptr[n];
    for(int i=0;i<n;i++){
        printf("please enter the data to be inserted in node '%d':",i);
        scanf("%d",&data);
        ptr[i]=createnode(data);
    }
    //loop for linking all the nodes
for (int i = 0; i < n; i++)
{
if(i==(n-1)){
    ptr[i]->next=NULL;
}
else
{
    ptr[i]->next=ptr[i+1];
}


}

struct node *newhead;
newhead=deletebeg(ptr[0]);
traverse(newhead);

    
return 0;
}