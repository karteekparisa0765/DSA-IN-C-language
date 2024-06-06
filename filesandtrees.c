#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *createnode(int data)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    return new;
}
struct node *insert(struct node *root, int data)
{
    if (root == NULL)
    {
        root = createnode(data);
    }
    else if (root->data == data)
    {
        printf("duplicate node cant be inserted");
        return NULL;
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }
    else if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    return root;
}
void inordertraverse(struct node *root)
{
    struct node *ptr = root;
    if (ptr != NULL)
    {
        inordertraverse(ptr->left);
        printf("%d ", root->data);
        inordertraverse(root->right);
    }
}
int main()
{
    struct node *root = NULL;
    FILE *ptr;
    ptr = fopen("data.txt", "w");
    int choice;
    do
    {
        printf("\nenter the choice:");
        printf("\n1)data entry\n2)exit\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
        {
            printf("\nenter the data:");
            int data;
            scanf("%d", &data);
            fprintf(ptr, "%d\n", data);
        }
        break;
        case 2:
        {
            printf("exitting the programme successfully...");
        }
        break;
        default:
        {
            printf("please enter the right choice...");
        }
        break;
        }

    } while (choice != 2);
    int data;
    fclose(ptr);
    ptr = fopen("data.txt", "r");
    while (fscanf(ptr, "%d", &data) != EOF)
    {
        root = insert(root, data);
    }
inordertraverse(root);
    return 0;
}