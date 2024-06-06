#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char name[1000];
    struct node *next;
};

struct node *createnode(char *name)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    strcpy(newnode->name, name);
    newnode->next = NULL;
    return newnode;
}

void traverse(struct node *head)
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
        if (ptr->next == NULL)
        {
            printf("%s-->NULL", ptr->name);
        }
        else
        {
            printf("%s-->", ptr->name);
        }
        ptr = ptr->next;
    }
}

int main()
{
    char name[1000];

    FILE *ptr;
    ptr = fopen("sample.txt", "w");
    printf("please enter the items into the list:\n");
    printf("1)add name\n2)exit\n");
    int choice;
    do
    {
        printf("please enter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            getchar();
            printf("please enter the item to be inserted:");
            fgets(name, sizeof(name), stdin);
            fprintf(ptr, "%s", name);
            printf("\nitem added successfully...\n");
            break;
        case 2:
            printf("exiting successfully....\n");
            break;
        default:
            printf("please enter the valid choice...\n");
            break;
        }
    } while (choice != 2);
    fclose(ptr);

    ptr = fopen("sample.txt", "r");
    struct node *head = NULL;
    struct node *temp = NULL;

    while (!(feof(ptr)))
    {
        if (fgets(name, sizeof(name), ptr) != NULL){
            name[strlen(name)-1] = '\0'; // Removing the newline character
        // overwriting the \n with \0 which is our NULL
        struct node *new = createnode(name);
        if (head == NULL)
        {
            head = temp = new;
        }
        else
        {
            temp->next = new;
            temp = new;
        }
    }}
    fclose(ptr);

    traverse(head);
    printf("\n");
    printf("%s", head->name);

    return 0;
}
