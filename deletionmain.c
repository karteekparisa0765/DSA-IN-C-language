#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *inorderpre(struct node *root)
{
    if (root == NULL)
        return NULL;

    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

struct node *delete(struct node *root, int data)
{
    struct node *ipre;
    if (root == NULL)
    {
        return NULL;
    }
    else if (data > root->data)
    {
        root->right = delete (root->right, data);
    }
    else if (data < root->data)
    {
        root->left = delete (root->left, data);
    }
    else
    {
        if (root->left == NULL)
        {
            struct node *temp = root;
            free(temp);
            return NULL;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root;
            free(temp);
            return NULL;
        }
        ipre = inorderpre(root);
        root->data = ipre->data;
        root = delete (root->left, ipre->data);
    }
    return root;
}

int search(struct node *root, int data)
{
    if (data == root->data)
    {
        return 1;
    }
    else if (data > root->data)
    {
        return search(root->right, data);
    }
    else if (data < root->data)
    {
       return search(root->left, data);
    }
    else
    {
        return 0;
    }
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
struct node *createnode(int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    printf("would you like to add a left child to node:%d:", node->data);
    printf("\n1)yes\n2)no\n");
    int x;
    scanf("%d",&x);
    switch (x)
    {
    case 1:
    {
        int leftchild;
        printf("please enter the data of the left child:");
        scanf("%d", &leftchild);
        node->left = createnode(leftchild);
    }
    break;
    case 2:
    {
        node->left = NULL;
    }
    break;
    default:
    {
        printf("please make a valid choice...");
    }
    break;
    }

    printf("would you like to add a right child to node:%d:", node->data);
    printf("\n1)yes\n2)no\n");
    int y;
    scanf("%d",&y);
    switch (y)
    {
    case 1:
    {
        printf("please enter the data of the right child:");
        int rightchild;
        scanf("%d", &rightchild);
        node->right = createnode(rightchild);
    }
    break;
    case 2:
    {
    }
    break;
    default:
    {
        printf("please make a valid choice...");
    }
    break;
    }
    return node;
}

struct node *insertnode(struct node *root, int data)
{
    if (root == NULL)
    {
        struct node *ptr = (struct node *)malloc(sizeof(struct node));
        ptr->data = data;
        ptr->left = NULL;
        ptr->right = NULL;
        return ptr;
    }
    else if (data > root->data)
    {
        root->right = insertnode(root->right, data);
    }
    else if (data < root->data)
    {
        root->left = insertnode(root->left, data);
    }
    else if (data == root->data)
    {
        printf("not possible..");
    }
    return root;
}
int main()
{
    printf("\nwelcome to trees\n");
    printf("what would you like to perform:");
    printf("\n1)tree creation\n2)insertion\n3)searching\n4)deletion");
    int data;
    int choice;
    struct node *root;
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
    {
        printf("please enter the data of the root node:");
        scanf("%d", &data);
        root = createnode(data);
    }
    break;
    case 2:
    {
        printf("please enter the data of the root node:");
        scanf("%d", &data);
        root = createnode(data);
        printf("please enter the data to be inserted:");
        int data;
        scanf("%d", &data);
        root = insertnode(root, data);
        inordertraverse(root);
    }
    break;
    case 3:
    {
        printf("please enter the data of the root node:");
        scanf("%d", &data);
        root = createnode(data);
        printf("please enter the element for searching:");
        int key;
        int x = search(root, key);
        if (x == 1)
        {
            printf("element found");
        }
        else
        {
            printf("element not found...");
        }
    }
    break;
    case 4:
    {
        printf("please enter the data of the root node:");
        scanf("%d", &data);
        root = createnode(data);
        printf("please enter the data to be deleted:");
        int key;
        scanf("%d", &key);
        root = delete (root, key);
        inordertraverse(root);
    }
    break;
    default:
    {
        printf("PLEASE MAKE A VALID CHOICE...");
    }
    break;
    }
    return 0;
}