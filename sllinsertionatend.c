#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node *createnode(int data);
struct node *insertatend(struct node *head,int data)
{
    struct node *ptr=head;
struct node * ptr2=createnode(data);    
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=ptr2;
    return head;

}
struct node *createnode(int data){
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=NULL;
    return ptr;
}
void traverse(struct node *head){
    struct node *ptr=head;
    while(ptr!=NULL){
     if(ptr->next==NULL){
        printf("%d-->NULL",ptr->data);
     }
     else{
        printf("%d-->",ptr->data);
     }
        ptr=ptr->next;
    }
}

int main()
{
    int n;
    int data;
    printf("please enter the number of nodes to insert:");
    scanf("%d",&n);
    struct node *array[n];
    for(int i=0;i<n;i++){
        printf("please enter the data in the node %d:",i);
        scanf("%d",&data);
        array[i]=createnode(data);
    }
for (int  i = 0; i < n; i++)
{
    if(i==n-1){
        array[i]->next=NULL;
    }
    else{
        array[i]->next=array[i+1];
    }
}
printf("please enter the data to be inserted:");
int newdata;
scanf("%d",&newdata);
struct node *newhead;
newhead=insertatend(array[0],newdata);
traverse(newhead);


return 0;
}