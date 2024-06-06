#include<stdio.h>
#include<stdlib.h>


struct node{
int data;
struct node *next;
};

struct node *createnode(int data)
{
struct node *ptr=(struct node *)malloc(sizeof(struct node));
ptr->data=data;
ptr->next=NULL;
return ptr;
}
void traverse(struct node *array[], int n) {
        struct node *current = array[0];  // Start at the beginning of each list
    for (int i = 0; i < n; i++) {

        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }

        printf("\n");  // Print a newline after each list
    }
}


int main()
{   
    
int data; 
int n;
printf("please enter the number of nodes:");
scanf("%d",&n);
struct node *array[n];
for(int i=0;i<n;i++){

    printf(" please enter the data to enter into node '%d' : ",i);
    scanf("%d",&data);
   array[i]=createnode(data);

}


for(int i=0;i<n;i++){
    if(i==(n-1))
       {
        array[i]->next=NULL;
       }

    else{
        array[i]->next=array[i+1];
        }
}
traverse(array,n);

return 0;
}