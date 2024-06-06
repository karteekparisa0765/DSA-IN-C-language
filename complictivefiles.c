#include <stdio.h>
#include <stdlib.h>
struct node
{
    int reg;
    char name[1000];
    struct node *next;
};
int main()
{
    char name[1000];
    int regno;

    FILE *ptr1, *ptr2;
    // ptr1 for writing all the names of the students
    // ptr2 for writing all the registration numbers of the students into it
    ptr1 = fopen("names.txt", "w");
    ptr2 = fopen("reg.txt", "w");
    printf("\n1)add member\n2)skip\n");
    int choice;
    printf("please enter your choice:");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
    {
        getchar();
        printf("\nplease enter the name of the student:");
        fgets(name, sizeof(name), stdin);
        fprintf(ptr1, "%s", name);
        printf("\nplease enter the regno of the student:");
        scanf("%d", &regno);
        fprintf(ptr2, "%d", regno);
    }

    break;
    case 2:
    {
        printf("exitting the programme...");
    }
    break;

    default:
    {
        printf("enter the valid choice...");
    }
    break;
    }
    fclose(ptr1);
    fclose(ptr2);
    ptr1 = fopen("names.txt", "r");
    ptr2 = fopen("reg.txt", "r");
    while (!feof(ptr1) && !feof(ptr2))
    {
        if (fgets(name, sizeof(name), ptr1) != NULL && fscanf(ptr2, "%d", ptr2) != NULL)
        {
        name[strlen(name)-1]='\0';
        
        }
    }

    return 0;
}