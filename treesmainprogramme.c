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
struct node *inorderpredecessor(struct node *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    else
    {
        root = root->left;
        while (root->right != NULL)
        {
            root = root->right;
        }
    }
    return root;
}
struct node *delete(struct node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (key < root->data)
    {
        root->left = delete(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = delete(root->right, key);
    }
    else
    {
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        struct node *ipre = inorderpredecessor(root);
        root->data = ipre->data;
        root->left = delete(root->left, ipre->data);
    }
    return root;
}

struct node *insert(struct node *root, int data)
{
    if (root == NULL)
    {
        root = createnode(data);
    }
    else if (root->data == data)
    {
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
void minimum(struct node *root)
{
    struct node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    printf("minimum:%d", temp->data);
}
void maximum(struct node *root)
{
    struct node *temp = root;
    while (temp->right != NULL)
    {
        temp=temp->right;
    }
    printf("maximum:%d", temp->data);
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
    FILE *p;
    int choice;
    p = fopen("main.txt", "w");
    do
    {
        printf("\n1)add data to file\n2)exit\n");
        printf("please enter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            printf("please enter the member to add:");
            int data;
            scanf("%d", &data);
            fprintf(p, "%d\n", data);
        }
        break;
        case 2:
        {
            printf("exitting the programme successfully...");
        }
        break;
        default:
        {
            printf("please enter a valid choice....");
        }
        break;
        }
    } while (choice != 2);
    fclose(p);
    p = fopen("main.txt", "r");
    do
    {
        printf("\n1)insert\n2)delete\n3)min\n4)max\n5)display\n6)exit\n");
        printf("\nenter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            int data;
            while (fscanf(p, "%d", &data) != EOF)
            {
                root = insert(root, data);
            }
        }
        break;
        case 2:
        {
            printf("enter the key element to delete:");
            int key;
            scanf("%d", &key);
            root = delete (root, key);
        }
        break;
        case 3:
        {
            minimum(root);
        }
        break;
        case 4:
        {
            maximum(root);
        }
        break;
        case 5:
        {
            inordertraverse(root);
        }
        break;
        case 6:
        {
            printf("exitting the programme....");
        }
        break;
        default:
        {
            printf("please enter a valid choice....");
        }
        break;
        }
    } while (choice != 6);

    return 0;
}