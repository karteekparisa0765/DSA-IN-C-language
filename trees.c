#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

// Function to create a new node
struct node* createnode(int data)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if(newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node in BST
struct node* insert(struct node* root, int data)
{
    if(root == NULL)
        return createnode(data);

    if(data < root->data)
        root->left = insert(root->left, data);
    else if(data > root->data)
        root->right = insert(root->right, data);
    else
        printf("Duplicate element %d cannot be inserted.\n", data);

    return root;
}

// Function to search for a node in BST
struct node* search(struct node* root, int key)
{
    if(root == NULL || root->data == key)
        return root;

    if(key < root->data)
        return search(root->left, key);

    return search(root->right, key);
}

// Function to find the minimum value node in a subtree
struct node* minValueNode(struct node* node)
{
    struct node* current = node;

    // Loop down to find the leftmost leaf
    while(current && current->left != NULL)
        current = current->left;

    return current;
}

// Function to delete a node from BST
struct node* deleteNode(struct node* root, int key)
{
    if(root == NULL)
        return root;

    // If the key to be deleted is smaller than the root's key, then it lies in the left subtree
    if(key < root->data)
        root->left = deleteNode(root->left, key);

    // If the key to be deleted is greater than the root's key, then it lies in the right subtree
    else if(key > root->data)
        root->right = deleteNode(root->right, key);

    // If the key is the same as root's key, then this is the node to be deleted
    else
    {
        // Node with only one child or no child
        if(root->left == NULL)
        {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL)
        {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        struct node* temp = minValueNode(root->right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Function to perform inorder traversal of BST
void inorder(struct node* root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main()
{
    struct node *root = NULL;
    int choice, data;

    do
    {
        printf("\nPlease enter the choice to perform on the tree:\n");
        printf("1) Insertion\n2) Searching\n3) Deletion\n4) Display\n5) Exit\n");
        printf("Please enter the choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element to be inserted: ");
            scanf("%d", &data);
            root = insert(root, data);
            break;
        case 2:
            printf("Enter the element to be searched: ");
            scanf("%d", &data);
            if(search(root, data) != NULL)
                printf("Element %d found in the tree.\n", data);
            else
                printf("Element %d not found in the tree.\n", data);
            break;
        case 3:
            printf("Enter the element to be deleted: ");
            scanf("%d", &data);
            root = deleteNode(root, data);
            break;
        case 4:
            printf("Inorder traversal of the tree: ");
            inorder(root);
            printf("\n");
            break;
        case 5:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (choice != 5);

    return 0;
}
