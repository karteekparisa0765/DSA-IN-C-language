#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 10
int top = -1;
struct student
{
    char name[100];
    char branch[100];
};
struct student stack[size];

void push(char *name, char *branch)
{
    if (top == size - 1)
    {
        printf("stack is overflowing..");
    }
    else if (top == -1)
    {
        top++;
        strcpy(stack[top].name, name);
        strcpy(stack[top].branch, branch);
    }
    else
    {
        top++;
        strcpy(stack[top].name, name);
        strcpy(stack[top].branch, branch);
    }
}
void pop()
{
    if (top == -1)
    {
        printf("stack is empty...");
    }
    else
    {
        printf("deleted student:%s\nstudent branch:%s", stack[top].name, stack[top].branch);
        top--;
    }
}
void peek()
{
    printf("top student:%s\nstudent branch:%s", stack[top].name, stack[top].branch);
}

void display()
{
    int x = top;
    for (int i = x; i >= 0; i--)
    {
        printf("student name:%s\nstudent branch:%s", stack[i].name, stack[i].branch);
    }
}

int main()
{
    char name[100];
    char branch[100];
    int choice;
    do
    {
        printf("---stack---\n");
        printf("please enter among the choice:\n");
        printf("\n1)push\n2)pop\n3)peek\n4)display\n5)exit\n");
        printf("please enter the choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            printf("please enter the name of the student:");
            scanf("%s", name);
            printf("please enter the branch of the student:");
            scanf("%s", branch);
            push(name, branch);
        }
        break;
        case 2:
        {
            pop();
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
            printf("exitting the programme");
        }
        break;
        default:
        {
            printf("please enter the valid choice");
        }
        break;
        }
    } while (choice != 5);
    return 0;
}