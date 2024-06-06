#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
struct node *inorderpredecessor(struct node *root)
{
    struct node *temp = root->left;
    if (root == NULL)
    {
        return NULL;
    }
    else
    {
        while (temp->right != NULL)
        {
            temp = temp->right;
        }
    }
    return temp;
}

struct node *delete(struct node *root, int key)
{
    struct node *ipre;
    if (root == NULL)
    {
        return NULL;
    }
    // search for the node to be deleted..
    if (key < root->data)
    {
        root->left = delete (root->left, key);
    }

    else if (key > root->data)
    {
        root->right = delete (root->right, key);
    }
    // deletion strategy

    else
    { if(root->left==NULL){
        struct node *temp=root;
        free(temp);
        return NULL;
    }
    else if(root->right==NULL){
        struct node *temp=root;
        free(temp);
        return NULL;
    }
    else {
        ipre = inorderpredecessor(root);
        root->data = ipre->data;
        root->left=delete (root->left, ipre->data);
    }}
}

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
        printf("duplicate element cant be inserted");
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

int main()
{
    struct node *root = NULL;
    int choice;
    do
    {
        printf("\nplease enter the preferred choice:\n");
        printf("\n1)insert\n2)delete\n3)exit\n");
        printf("enter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            printf("enter the data of the node to be inserted:");
            int data;
            scanf("%d", &data);
            root = insert(root, data);
        }
        break;
        case 2:
        {
            printf("please enter the key to delete:");
            int key;
            scanf("%d", &key);
            root = delete (root, key);
        }
        break;
        case 3:
        {
            printf("exitting the programme...");
        }
        break;
        default:
        {printf("please enter a valid choice......");
        }
        break;
        }
    } while (choice != 3);
    inorder(root);
    return 0;
}
