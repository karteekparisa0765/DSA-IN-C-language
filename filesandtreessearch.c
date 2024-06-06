#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *createnode(int data){
    struct node *node=(struct node *)malloc(sizeof(struct node));
    node->data=data;
    node->left=NULL;
    node->right=NULL;
    return node;
}
struct node *insert(struct node *root, int data)
{
    if (root == NULL)
    {
        root = createnode(data);
    }
    else if (root->data == data)
    {
        printf("duplicate elements cant be inserted...");
    }
    else if(data>root->data){
        root->right=insert(root->right,data);
    }
    else if(data<root->data){
        root->left=insert(root->left,data);
    }
    return root;
}
void search(struct node *root,int data){
    if(root==NULL){
        printf("not present");
    }
    else if(root->data==data){
        printf("element found");
    }
    else if(data>root->data){
        search(root->right,data);
    }
    else if(data<root->data){
        search(root->left,data);
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
int main()
{
    struct node *root = NULL;
    int choice;
    FILE *p;
    p = fopen("node.txt", "w");
    do
    {
        printf("\nplease enter your respective choice:");

        printf("\n1)insert data\n2)exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            int data;
            printf("enter the data to add:");
            scanf("%d", &data);
            fprintf(p, "%d\n", data);
        }
        break;
        case 2:
        {
            printf("exitting the programme successfully...\n");
        }
        break;
        default:
        {
            printf("please enter the right choice....");
        }
        break;
        }
    } while (choice != 2);
    fclose(p);
    p = fopen("node.txt", "r");
    int data;
    while (fscanf(p, "%d", &data) != EOF)
    {
        root = insert(root, data);
    }
    printf("\n");
    inordertraverse(root);
    printf("enter the element for searching");
    int key;
    scanf("%d",&key);
    search(root,key);
    return 0;
}