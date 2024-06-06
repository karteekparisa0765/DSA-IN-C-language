#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    int regno;
    char section;
    char name[1000];
    struct node *next;
};

struct node *createnode(char *name, int reg, char section)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    strcpy(node->name, name);
    node->regno = reg;
    node->section = section;
    return node;
}

void traverse(struct node *head)
{
    struct node *ptr;
    ptr = head;
    while (ptr != NULL)
    {
        if (ptr->next == NULL)
        {
            printf("%s --> NULL\n", ptr->name);
        }
        else
        {
            printf("%s --> ", ptr->name);
        }
        ptr = ptr->next;
    }
}

int main()
{
    char name[1000];
    char section;
    int regno;
    FILE *p1, *p2, *p3;
    p1 = fopen("reg.txt", "w");
    p2 = fopen("names.txt", "w");
    p3 = fopen("section.txt", "w");
    printf("please choose what to happen:");
    printf("\n1)add member\n2)skip adding\n");
    int choice;
    do
    {
        printf("please enter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            printf("\nplease enter the name of the student:");
            getchar();
            fgets(name, sizeof(name), stdin);
            fputs(name, p2);
            printf("\nplease enter the section of the student:");
            scanf("%c", &section);
            fputc(section, p3);
            getchar();
            printf("\nplease enter the registration number of the student:");
            scanf("%d", &regno);
            fprintf(p1, "%d\n", regno);
        }
        break;
        case 2:
        {
            printf("\nexitting the programme successfully...");
        }
        break;
        default:
        {
            printf("please enter the valid choice....");
        }
        break;
        }
    } while (choice != 2);

    fclose(p1);
    fclose(p2);
    fclose(p3);
    struct node *head = NULL;
    struct node *temp = NULL;

    p1 = fopen("reg.txt", "r");
    p2 = fopen("names.txt", "r");
    p3 = fopen("section.txt", "r");
    while (fgets(name, sizeof(name), p2) != NULL && fscanf(p1, "%d", &regno) != EOF && fscanf(p3, "%c", &section) != EOF)
    {
        name[strlen(name) - 1] = '\0';

        struct node *nn = createnode(name, regno, section);
        if (head == NULL)
        {
            head = temp = nn;
        }
        else
        {
            temp->next = nn;
            temp = nn;
        }
    }
    traverse(head);
    fclose(p1);
    fclose(p2);
    fclose(p3);

    return 0;
}