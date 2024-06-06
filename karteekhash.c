#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    int data;
    struct node *next;
};
#define n 10
struct node *table[n];
struct node *createnode(int data)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = data;
    new->next = NULL;
    return new;
}
void createtable()
{
    for (int i = 0; i < n; i++)
    {
        table[i] = NULL;
    }
}

void insert(int data)
{
    struct node *new = createnode(data);
    int hv = data % n;
    if (table[hv] == NULL)
    {
        table[hv] = new;
        return;
    }
    else
    {
        struct node *temp = table[hv];
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new;
        return;
    }
}

void display()
{
    struct node *temp;
    for (int i = 0; i < n; i++)
    {
        printf("%d ", i);
        temp = table[i];
        while (temp != NULL)
        {
            printf("%d", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void search(int data)
{
    int hv = data % n;
    if (table[hv] == NULL)
    {
        printf("element not found!!");
        return;
    }
    struct node *temp = table[hv];
    while (temp != NULL)
    {
        if (temp->data == data)
        {
            printf("elemnet found/...");
            return ;
        }

        else
        {
            temp = temp->next;
        }
    }
}

int main()
{
    int choice, x;
    createtable();
    do
    {
        printf("1.insert\t2.display\t3.search\n");
        printf("your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("element to be inserted:\n");
            scanf("%d", &x);
            insert(x);
            break;
        case 2:
            display();
            break;
        case 3:
            printf("element to search:\n");
            scanf("%d", &x);
            search(x);
            break; // Added break statement here
        default:
            printf("invalid input\n");
            break;
        }
    } while (choice < 3);
    printf("the enddd.....");

    return 0;
}