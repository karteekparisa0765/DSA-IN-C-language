#include <stdio.h>
#include <stdlib.h>
struct node
{
    float coeff;
    int exp;
    struct node *next;
};
//---------------------------------------------------------------------------------------------
// function prototypes
struct node *createnode(float coeff, int exp);
void traverse(struct node *head);
//---------------------------------------------------------------------------------------------

// node creation function

struct node *createnode(float coeff, int exp)
{

    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->coeff = coeff;
    ptr->exp = exp;
    ptr->next = NULL;
    return ptr;
}

// traversal function---------------------------------------------------------------------------
void traverse(struct node *head)
{

    struct node *ptr = head;
    while (ptr != NULL)
    {

        if (ptr->next == NULL)
        {
            printf("%.1fx^%d", ptr->coeff, ptr->exp);
        }
        else
        {

            printf("%.1fx^%d+", ptr->coeff, ptr->exp);
        }

        ptr = ptr->next;
    }
}

//---------------------------------------------------------------------------------------------
//----------------appending function-----------------------------------------------------------
struct node *append(struct node *head, struct node *ptr)
{
    struct node *ptr1;
    ptr1 = head;
    while (ptr1->next != NULL)
    {
        ptr1 = ptr1->next;
    }
    ptr1->next = ptr;
    ptr->next = NULL;
    return head;
}
int main()
{

    // nodal creation for the polynomial 1:
    printf("please enter the terms in the polynomial 1:");
    int n1;
    scanf("%d", &n1);
    float coeff;
    int exp;
    struct node *ptr1[n1];
    for (int i = 0; i < n1; i++)
    {
        printf("please enter the coefficient of term %d:", i + 1);
        scanf("%f", &coeff);
        printf("please enter the exponent of the term %d:", i + 1);
        scanf("%d", &exp);
        ptr1[i] = createnode(coeff, exp);
    }
    // linking the polynomial 1 nodes
    for (int i = 0; i < n1; i++)
    {
        if (i == (n1 - 1))
        {
            ptr1[i]->next = NULL;
        }
        else
        {

            ptr1[i]->next = ptr1[i + 1];
        }
    }

    // nodal creation for the polynomial 2:

    printf("please enter the terms in the polynomial 2:");
    int n2;
    scanf("%d", &n2);
    struct node *ptr2[n2];
    for (int i = 0; i < n2; i++)
    {
        printf("please enter the coefficient of term %d:", i + 1);
        scanf("%f", &coeff);
        printf("please enter the exponent of the term %d:", i + 1);
        scanf("%d", &exp);
        ptr2[i] = createnode(coeff, exp);
    }
    // linking the polynomial 2 nodes:

    for (int i = 0; i < n2; i++)
    {
        if (i == (n2 - 1))
        {
            ptr2[i]->next = NULL;
        }
        else
        {

            ptr2[i]->next = ptr2[i + 1];
        }
    }
    // traverse(ptr1[0]);
    // printf("\n");
    // traverse(ptr2[0]);

    printf("will be performing the polynomial addition:\n");

    struct node *h1;
    struct node *h2;
    struct node *ptr3[n1 + n2];
    struct node *h3 = NULL;
    h1 = ptr1[0];
    h2 = ptr2[0];
    int i = 0;
    struct node *mainhead;
    while (h1 != NULL || h2 != NULL)
    {
        if (h1 == NULL)
        {
            ptr3[i] = createnode(h2->coeff, h2->exp);
            h2 = h2->next;
        }
        if (h2 == NULL)
        {
            ptr3[i] = createnode(h1->coeff, h1->exp);
            h1 = h1->next;
        }
        else if (h1->exp > h2->exp)
        {
            ptr3[i] = createnode(h1->coeff, h1->exp);
            h2 = h2->next;
        }
        else if (h2->exp > h1->exp)
        {
            ptr3[i] = createnode(h2->coeff, h2->exp);
            h1 = h1->next;
        }
        else if (h1->exp == h2->exp)
        {

            ptr3[i] = createnode(ptr1[i]->coeff + ptr2[i]->coeff, ptr1[i]->exp);
            h1 = h1->next;
            h2 = h2->next;
        }

        if (i == 0)
        {
            h3 = ptr3[i];
            mainhead = h3;
        }
        else
        {
            h3 = append(h3, ptr3[i]);
        }

        i++;
    }
    traverse(h3);

    return 0;
}