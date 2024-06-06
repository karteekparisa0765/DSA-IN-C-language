#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// book name
// book price
struct node
{
    char name[100];
    int price;
    struct node *next;
};

struct node *push(struct node **top, char *name, int price)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    strcpy(ptr->name, name);
    ptr->price = price;
    ptr->next = *top;//giving the top address to the last node
    *top = ptr;//updating the top pointer to store the whole node address
    return ptr;
}

void *pop(struct node **top)
{
    char name1[100];
    strcpy(name1, (*top)->name);
    int x = (*top)->price;
    *top = (*top)->next;
    printf("popped book is :(%s)", name1);
    printf("price of the book is: %d", x);
}

void peek(struct node *top)
{
    char name[100];
    strcpy(name, top->name);
    int x = top->price;
    printf("book at top is:(%s)", name);
    printf("price of the book is: %d", x);
}

void display(struct node *top)
{
    struct node *temp;
    temp = top;
    while (temp != NULL)
    {
        if (temp->next == NULL)
        {
            printf("%s:%d-->NULL", temp->name, temp->price);
        }
        else
        {
            printf("%s:%d-->", temp->name, temp->price);
        }
        temp = temp->next;
    }
}

int main()
{
    char name[100];
    int price;
    struct node *top = NULL;
    int choice;
    do
    {
        printf("\n");
        printf("----stack----\n");
        printf("welcome to library\n");
        printf("1)push book\n2)pop book\n3)peek book\n4)display books\n5)exit\n");
        printf("enter a valid choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            printf("please enter the name of the book:");
            scanf("%s", name);
            printf("please enter the price of the book:");
            scanf("%d", &price);
            push(&top, name, price);
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
            display(top);
        }
        break;
        case 5:
        {
            printf("exitting the programme....");
        }
        break;
        default:
        {
            printf("please enter a valid choice");
        }
        break;
        }
    } while (choice != 5);

    return 0;
}