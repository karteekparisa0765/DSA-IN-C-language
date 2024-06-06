#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct node
{
    char name[1000];
    struct node *next;
};
struct node *createnode(char *name){
    struct node *node=(struct node *)malloc(sizeof(struct node));
    strcpy(node->name,name);
    node->next=NULL;
    return node;
}
 void traverse(struct node *head)
{
    struct node *ptr;
    ptr = head;
    while (ptr != NULL)
    {
        if (ptr->next == NULL) {
            printf("%s --> NULL\n", ptr->name);
        }
        else {
            printf("%s --> ", ptr->name);
        }
        ptr = ptr->next;
    }
}

int main()
{
    char name[1000];
    FILE *ptr;
    struct node *head = NULL;
    struct node *temp = NULL;
    ptr = fopen("list.txt", "r");
    while (!(feof(ptr)))
    {
        if (fgets(name, sizeof(name), ptr) != NULL)
        {
            name[strlen(name) - 1] = 0;
            struct node *node = createnode(name);
            if (head == NULL)
            {
                head = temp = node;
            }
            else
            {
                temp->next = node;
                temp = node;
            }
        }
    }
traverse(head);
    return 0;
}