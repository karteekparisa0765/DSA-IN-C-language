#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    char name[100];
    int price;
    struct node *next;
};
void push(struct node **f, struct node **r, char *name, int price)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    strcpy(ptr->name, name);
    ptr->price = price;
    ptr->next = NULL;

    if (*f == NULL && *r == NULL)
    {
        *f = *r = ptr;
    }
    else
    {
        (*r)->next = ptr;
        (*r) = ptr;
    }
}
void deque(struct node **f, struct node **r)
{
    if (*f == NULL && *r == NULL)
    {
        printf("empty...\n");
    }
    else
    {
        printf("dequed book is %s\n", (*f)->name);
        printf("price of book is %d\n", (*f)->price);

        // If there's only one element, set both *f and *r to NULL
        if (*f == *r)
        {
            free(*f);
            *f = *r = NULL;
        }
        else
        {
            struct node *temp = *f;
            *f = (*f)->next;
            free(temp);
        }
    }
}


void display(struct node *f, struct node *r)
{
    struct node *temp = f;
    while (temp != NULL)
    {
        if (temp->next == NULL)
        {
            printf("%s--%d-->NULL\n", temp->name, temp->price);
        }
        else
        {
            printf("%s--%d-->", temp->name, temp->price);
        }
        temp = temp->next;
    }
}

int main()
{
    printf("please enter a valid choice:");
    char name[100];
    int price;
    struct node *f = NULL;
    struct node *r = NULL;
    int choice;
    do
    {
        printf("1)enque\n2)deque\n3)display\n4)exit\n");
        printf("please enter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            printf("please enter the name of the book:");
            scanf("%s", name);
            printf("please enter the price of the book:");
            scanf("%d", price);
            push(&f, &r, name, price);
        }
        break;
        case 2:
        {
            deque(&f, &r);
        }
        break;
        case 3:
        {
            display(f, r);
        }
        break;
        case 4:
        {
            printf("exitting the programme...");
        }
        break;
        default:
        {
            printf("enter a valid choice...");
        }
        break;
        }
    } while (choice != 4);
    return 0;
}