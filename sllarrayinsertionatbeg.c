#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node *createnode(int data){
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=NULL;
    return ptr;
}
struct node *insertbeg(struct node *head,int n,int data){
   struct node *ptr=createnode(data);
   ptr->next=head;
   
   head=ptr;

return ptr;

}
void traverse(struct node *head){
    struct node *ptr=head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}
int main()
{
    int data;
int n;
printf("please enter the number of nodes to create:");
scanf("%d",&n);
struct node*array[n];
for(int i=0;i<n;i++){
    printf("please enter the data to enter :");
    scanf("%d",&data);
    array[i]=createnode(data);
}
for(int i=0;i<n;i++){
    if(i==(n-1)){
        array[i]->next=NULL;
    }
    else{
        array[i]->next=array[i+1];
    }
}

printf("please enter the data of the node to be created:");
int newdata;
scanf("%d",&newdata);
struct node *newhead;
newhead=insertbeg(array[0],n,newdata);
traverse(newhead);
return 0;
}