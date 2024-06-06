#include <stdio.h> //using array approach
#include <stdlib.h>
#include <string.h>
#define size 10
int top = -1;
struct book
{
    char name[100];
    int price;
};
struct book stack[size];

void push(char *name, int price)
{
    if (top == size - 1)
    {
        printf("sorry stack is full...");
    }
    if (top == -1)
    {
        top++;
        strcpy(stack[top].name, name);
        stack[top].price = price;
    }
    else
    {
        strcpy(stack[top].name, name);
        stack[top].price = price;
        top++;
    }
}

void pop(struct node **top)
{
    if (top == -1)
    {
        printf("stack is empty...");
    }
    else
    {
        printf("popped book is:%s", stack[*top].name);
        printf("popped book price is:%d", stack[*top].price);
        top--;
    }
}
void peek()
{
    printf("top book is:%s", stack[top].name);
    printf("top book price is:%d", stack[top].price);
}

void display()
{
    int x = top;
    for (int i = x; i >= 0; i--)
    {
        printf("book:%s;price:%d", stack[i].name, stack[i].price);
    }
}

struct book stack[size];
int main()
{
    char name[100];
    int price;
    int choice;
    do
    {
        printf("please enter the valid choice:\n");
        printf("----stack----\n");
        printf("\n1)push\n2)pop\n3)peek\n4)display\n5)exit\n");
        printf("please enter a valid choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            printf("please enter the name of the book:");
            scanf("%s", name);
            printf("enter the cost of the book:");
            scanf("%d", &price);
            push(name, price);
        }
        break;
        case 2:
        {
            pop(&top);
        }
        break;
        case 3:
        {
            peek();
        }
        break;
        case 4:
        {
            display();
        }
        break;
        case 5:
        {
            printf("exitting the programme....");
        }
        break;
        default:
        {
            printf("enter a valid choice");
        }
        break;
        }
    } while (choice != 5);

    return 0;
}