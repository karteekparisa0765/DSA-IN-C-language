#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
//------------------prototypes-----------------------------------------------------------------------------------------
struct node * reversal(struct node*head);
struct node *createnode(int data);
void traverse(struct node *head);
//---------------------------------------------------------------------------------------------------------------------


//-----------------------------nodes creating function------------------------------------------------------------------
struct node *createnode(int data){
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=NULL;
    return ptr;
}
//----------------------------------------------------------------------------------------------------------------------
//------------------------------traversal function----------------------------------------------------------------------
void traverse(struct node *head){
    struct node *ptr=head;
    while (ptr!=NULL)
    {
        if(ptr->next==NULL){
            printf("%d-->NULL",ptr->data);
        }
        else{
            printf("%d--> ",ptr->data);
        }
        ptr=ptr->next;
    }

    }
//-----------------------------------------------------------------------------------------------------------------------
    //reversal function
//-----------------------------------------------------------------------------------------------------------------------

struct node * reversal(struct node*head){
    struct node *ptr=head;
    struct node *prev=NULL;
    struct node *current=ptr;
    struct node *next=NULL;
    while (current!=NULL)
    {
next=current->next;
current->next=prev;
prev=current;
current=next;


    }
    ptr=prev;
    return ptr;
}



//--------------------------------------------------------------------------------------------------------------------



int main()
{
int n;
int data;
printf("please enter the number of nodes to be inserted:");
scanf("%d",&n);
struct node *ptr[n];
for (int  i = 0; i < n; i++)
{printf("please enter th   ilhkuhyje data of the node:");
scanf("%d",&data);
ptr[i]=createnode(data);   
}

for (int  i = 0; i < n; i++)
{
if(i==(n-1)){
    ptr[i]->next=NULL;
}
else{
    ptr[i]->next=ptr[i+1];
}

}
printf("normal list:\n");
traverse(ptr[0]);
printf("\n");
struct node *newhead=reversal(ptr[0]);
printf("reversed list:\n");
traverse(newhead);













return 0;
}