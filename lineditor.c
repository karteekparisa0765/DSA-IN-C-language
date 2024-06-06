#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char data[100];
    struct node *next;
};
















struct node *createNode(char *str)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (!newNode)
    {
        return NULL;
    }

    strcpy(newNode->data, str);

    newNode->next = NULL;
    return newNode;
}


















void traverse(struct node *head, int n, int x)
{
    struct node *ptr[0][0];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < x; j++)
        {
            while (ptr[i][j] != NULL)
            {
                if (ptr[i][j]->next == NULL)
                {
                    printf("%s --> NULL\n", ptr[i][j]->data);
                }
                else
                {
                    printf("%s --> ", ptr[i][j]->data);
                }
                ptr[i][j] = ptr[i][j]->next;
            }
        }
    }
}










int main()
{
    printf("please enter the number of the lines:");
    int n;
    scanf("%d", &n);
    int data;
    int x;
    printf("please enter the number of words:");
    scanf("%d", &x);
    struct node *ptr1[n][x];
    char str[100];










    // creation of nodes mam....
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < x; j++)
        {
            fgets(str, sizeof(str), stdin);
            printf("please enter the string in node [%d][%d]:", i, j);
            char str2[100];
            strcpy(str2, str);

            printf("%s\n", str2); // Print to verify the string

            ptr1[i][j] = createNode(str2);
        }
    }














    // Initiating linking the nodes...
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < x; j++)
        {
            // Link the nodes horizontally
            if (j < x - 1)
            {
                ptr1[i][j]->next = ptr1[i][j + 1];
            }
            else
            {
                ptr1[i][j]->next = NULL;
            }

            // Link the nodes vertically
            if (i < n - 1)
            {
                ptr1[i][j]->next = ptr1[i + 1][j];
            }       
        }
    }















    traverse(ptr1[0][0], n, x);

    return 0;
}