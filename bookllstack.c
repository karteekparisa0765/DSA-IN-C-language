#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    char name[100];
    struct node *next;
};

void push(char *name, struct node **top)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    strcpy(ptr->name, name);
    ptr->next = *top;
    *top = ptr;
}

void pop(struct node **top)
{
    printf("%s is popped", (*top)->name);
    (*top) = (*top)->next;
}

void peek(struct node *top)
{
    printf("%s is at top", (*top).name);
}

void display(struct node *top)
{
    struct node *temp = top;
    while (temp != NULL)
    {
        if (temp->next == NULL)
        {
            printf("%s-->NULL", temp->name);
        }
        else
        {
            printf("%s--> ", temp->name);
        }
        temp = temp->next;
    }
}

int main()
{
    char name[100];

    struct node *top = NULL;
    int choice;
    do{
    printf("1)push\n2)pop\n3)peek\n4)exit\n");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
    {
        printf("please enter the name of the book:");
        scanf("%s", name);
        push(name, &top);
    }
    break;
    case 2:
    {
        pop(&top);
    }
    break;
    case 3:
    {
        peek(top);
    }
    break;
    case 4:
    {
        printf("exitting the programme..");
    }
    break;
    default:
    {
        printf("enter a valid choice");
    }
    break;
    }}while(choice!=4);
    return 0;
}