#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *enque(struct node **front, struct node **rear, int data)
{

    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = NULL;
    if (*front == NULL && *rear == NULL)
    {
        *front = *rear = ptr;
    }
    else
    {
        (*rear)->next=ptr;
        (*rear)=ptr;
    }
    return ptr;
}



void deque(struct node **front ,struct node **rear){
    if(*front==NULL&& *rear==NULL){
        printf("que is empty");
    }
    else{
        int x=(*front)->data;
        (*front)=(*front)->next;
        printf("popped element is %d",x);
        
    }

}

void display(struct node *front, struct node *rear) {
    struct node *temp = front;
    if (temp == NULL && rear == NULL) {
        printf("Queue is empty\n");
    } else {
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }                                                 //creating two pointers initiated to null later for enquing the first node 
        //enqued it and upgraded the pointers to the first node
        //later when another node is to be added upgraded the rear address and updated the rear pointers keeping the front constant
        //when popped upgraded the front pointer until it becomes equal to that of rear;
        //in display we cerated another pointer initialised with front pointer and traversed it until we witness NULL
        printf("\n");
    }
}


int main()
{
    printf("--que--");
    struct node *front = NULL;
    struct node *rear = NULL;
    int choice;
    do{
        printf("\n");
    printf("welcome to que operations:\n");
    printf("1)enque\n2)deque\n3)display\n4)exit\n");
    printf("please enter the valid choice:");+
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
    {
        printf("please enter the data to enter:");
        int data;
        scanf("%d", &data);
        enque(&front, &rear, data);
    }
    break;
    case 2:
    {
        deque(&front,&rear);
    }
    break;
    case 3:
    {
        display(front,rear);
    }
    break;
    case 4:
    {
        printf("exitting the programme...");
    }
    break;
    }}while(choice!=4);
    return 0;
}