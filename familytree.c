#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{

    char name[1000];
    struct node *left;
    struct node *right;
};
struct node *createnode(char *name)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->left = NULL;
    new->right = NULL;
    strcpy(new->name, name);
    return new;
}
void inordertraverse(struct node *root)
{
    struct node *ptr = root;
    if (ptr != NULL)
    {
        inordertraverse(ptr->left);
        printf("%s ", ptr->name);
        inordertraverse(ptr->right);
    }
}
struct node *insert(struct node *root, char *name)
{
    if (root == NULL)
    {
        root = createnode(name);
    }
    else if (strlen(name) == strlen(root->name))
    {
        return NULL;
    }
    else if (strlen(name) > strlen(root->name))
    {
        root->right = insert(root->right, name);
    }
    else if (strlen(name) < strlen(root->name))
    {
        root->left = insert(root->left, name);
    }
    return root;
}

int main()

{
    struct node *root = NULL;

    FILE *p;
    char name[1000];
    p = fopen("names.txt", "w");
    int choice;
    do
    {
        printf("\n1)add member\n2)exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            getchar();
            fgets(name, sizeof(name), stdin);
            fputs(name, p);
        }
        break;
        case 2:
        {
            printf("exitting the programme.....");
        }
        break;
        default:
        {
            printf("please make a valid choice....");
        }
        break;
        }
    } while (choice != 2);
    fclose(p);
    p = fopen("names.txt", "r");
    while (fgets(name, sizeof(name), p) != NULL)
    {
        name[strlen(name) - 1] = '\0';

        root = insert(root, name);
    }
    inordertraverse(root);
    return 0;
}