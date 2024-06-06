#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct node
{
    int regno;
    char name[1000];
    struct node *next;
};
struct node *createnode(char *name,int regno){
    struct node *nn=(struct node *)malloc(sizeof(struct node));
    strcpy(nn->name,name);
    nn->regno=regno;
    nn->next=NULL;
    return nn;
}
void traverse(struct node *head)
{
    struct node *ptr;
    ptr = head;
    while (ptr != NULL)
    {
        if (ptr->next == NULL) {
            printf("%s-->%d --> NULL\n", ptr->name,ptr->regno);
        }
        else {
            printf("%s-->%d --> ", ptr->name,ptr->regno);
        }
        ptr = ptr->next;
    }
}

int main()
{
    char name[1000];

    FILE *p1, *p2;
    p1 = fopen("names.txt", "w");
    p2 = fopen("regno.txt", "w");
    printf("\n1)enter member\n2)exit\n");
    int regno;
    int choice;
    do
    {
        printf("enter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
            {
            case 1:
                printf("\nplease enter the name of the student:");
                getchar();
                fgets(name, sizeof(name), stdin);
                fputs(name, p1);
                printf("\nplease enter the reg no of the student:");
                scanf("%d", &regno);
                fprintf(p2, "%d\n", regno);

                printf("name and regno of the student addded successfully...");
            }
            break;
        case 2:
        {
            printf("exitting the programme successfully...");
        }
        break;
        default:
        {
            printf("enter the valid choice...");
        }
        break;
        }
    } while (choice != 2);
    struct node *temp = NULL;
    struct node *head = NULL;

    fclose(p1);
    fclose(p2);
    p1 = fopen("names.txt", "r");
    p2 = fopen("regno.txt", "r");
    while (!(feof(p1)) && !(feof(p2)))
    {
        if (fgets(name, sizeof(name), p1) != NULL && (fscanf(p2, "%d", &regno) != EOF))
        {
            name[strlen(name) - 1] = '\0';
            struct node *node = createnode(name, regno);
            if (head == NULL)
            {
                head = temp = node;
            }
            else{
                temp->next=node;
                temp=node;
            }

        }
    }
    fclose(p1);
    fclose(p2);
    traverse(head);

    return 0;
}