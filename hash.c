#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define n 11
struct node
{
    int data;
    struct node *next;
};
struct node *table[n];
void createtable()
{
    for (int i = 0; i < n; i++)
    {
        table[i] = NULL;
    }
}
struct node *createnode(int data)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = data;
    new->next = NULL;
    return new;
}

void insert(int data)
{
    int hv = data % n;
    struct node *new = createnode(data);
    if (table[hv] == NULL)
    {
        table[hv] = new;
    }
    else
    {
        struct node *temp = table[hv];
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new;
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
    else
    {
        struct node *temp = table[hv];
        while (temp != NULL)
        {
            if (temp->data == data)
            {
                printf("element found!!");
                return;
            }
            temp = temp->next;
        }
    }
}
void display()
{
    struct node *temp;
    for (int i = 0; i < n; i++)
    {
        printf("%d", i);
        temp = table[i];
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
int main()
{
    int choice;
    do{
    printf("please enter the choice to perform in the hash table");
    
    printf("1)insert\n2)search\n3)display\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
    {
        printf("enter the data to be inserted");
        int data;
        scanf("%d", &data);
        insert(data);
    }
    break;
    case 2:
    {
        printf("enter the data to be searched...");
        int data;
        scanf("%d",&data);
        search(data);
    }
    break;
    case 3:
    {
        display();
    }
    break;
    case 4:
    {
        printf("exitting the programme...");
    }
    break;
    default:
    {
        printf("enter a valid choice..");
    }
    break;
    }}while(choice !=4);

    return 0;
}