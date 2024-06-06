#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *createnode(struct node *root, int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void inordertraversal(struct node *root)
{
    if (root != NULL)
    {
        inordertraversal(root->left);
        printf("%d  ", root->data);
        inordertraversal(root->right);
    }
}

void preordertraversal(struct node *root)
{
    if (root != NULL)
    {
        printf("%d  ", root->data); // Print current node
        preordertraversal(root->left); // Traverse left subtree
        preordertraversal(root->right); // Traverse right subtree
    }
}

struct node *insertion(struct node *root, int data)
{
    if (root == NULL)
    {
        root = createnode(root, data);
    }
    else if (root->data == data)
    {
        printf("duplicate elements...");
    }
    else if (data > root->data)
    {
        root->right = insertion(root->right, data);
    }
    else if (data < root->data)
    {
        root->left = insertion(root->left, data);
    }
    return root;
}

void search(struct node *root, int key)
{
    if (root == NULL)
    {
        printf("element not found...");
    }
    if (root->data == key)
    {
        printf("element found");
    }
    else if (key > root->data)
    {
        search(root->right, key);
    }
    else if (key < root->data)
    {
        search(root->left, key);
    }
}

int main()
{
    struct node *root = NULL;
    int choice;
    do
    {
        printf("please enter the choice!!");
        printf("\n1)yes\n2)no\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            printf("enter the data to be inserted:");
            int data;
            scanf("%d", &data);
            root = insertion(root, data);
        }
        break;
        case 2:
        {
            printf("exitting the programme....");
        }
        break;
        default:
        {
            printf("please enter the valid choice...");
        }
        break;
        }
    } while (choice != 2);
    inordertraversal(root);
    printf("\npreorder traversal");
    preordertraversal(root);
    printf("enter the element to search:");
    int key;
    scanf("%d", &key);
    search(root, key);

    return 0;
}