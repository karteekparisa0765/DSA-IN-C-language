#include<stdio.h>
#include<stdlib.h>
struct node{
        int data;
        struct node *next;
    };
    void reversal(struct node *ptr){
        int count=1;
        struct node *ptr3;
        ptr3=ptr;
        struct node *ptr1;
        ptr1=ptr;

while(ptr1!=NULL){
    count++;
    ptr1=ptr1->next;
}
int *ptr2=(int *)calloc(count,sizeof(int));
int *p=ptr2;
for(int i=1;i<=count;i++){
    

    
}




    }
int main() 
{
    struct node*head=(struct node *)malloc(sizeof(struct node));
    struct node*first=(struct node *)malloc(sizeof(struct node));
    struct node*second=(struct node *)malloc(sizeof(struct node));
    struct node*third=(struct node *)malloc(sizeof(struct node));
    struct node*fourth=(struct node *)malloc(sizeof(struct node));
    head->data=12;
    head->next=first;
    
    first->data=24;
    first->next=second;

    second->data=36;
    second->next=third;

    third->data=48;
    third->next=fourth;

    fourth->data=47;
    fourth->next=NULL;

    reversal(head);




    
return 0;
}