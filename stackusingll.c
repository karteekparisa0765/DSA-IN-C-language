#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *push(struct node **top, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = *top;
    *top = ptr;
    return ptr;
}

int pop(struct node **top)
{
    int x = (*top)->data;
    *top = (*top)->next;
    return x;
}

int peek(struct node *top)
{
    int x = top->data;
    return x;
}

void display(struct node *top)
{
    struct node *temp = top;
    while (temp != NULL)
    {
        if (temp->next == NULL)
        {
            printf("%d-->NULL", temp->data);
        }
        else
        {
            printf("%d-->", temp->data);
        }
        temp = temp->next;
    }
}

int main()
{
    struct node *top = NULL;

    printf("----stack----\n");

    int choice;
    do
    {
        printf("\n");
        printf("1)push\n2)pop\n3)peek\n4)display\n");
        printf("please enter the choice you want to perform:");
        scanf("%d", &choice);
        switch (choice)
        {

        case 1:
        {
            int data;
            printf("enter the data to push:");
            scanf("%d", &data);
            push(&top, data);
        }
        break;
        case 2:
        {
            int x = pop(&top);
            printf("popped element is %d", x);
        }
        break;
        case 3:
        {
            int x = peek(top);
            printf("element at the top is %d", x);
        }
        break;
        case 4:
        {
            display(top);
        }
        break;
        case 5:
        {
            printf("exitting the programme");
        }
        break;
        default:
        {
            printf("enter the valid choice...");
        }
        }
    } while (choice != 5);

    return 0;
}