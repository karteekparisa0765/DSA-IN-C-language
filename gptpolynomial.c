#include <stdio.h>
#include <stdlib.h>

struct node
{
    float coeff;
    int exp;
    struct node *next;
};

// function prototypes
struct node *createnode(float coeff, int exp);
void traverse(struct node *head);
struct node *append(struct node *head, struct node *ptr);

// node creation function
struct node *createnode(float coeff, int exp)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->coeff = coeff;
    ptr->exp = exp;
    ptr->next = NULL;
    return ptr;
}

// appending function
struct node *append(struct node *head, struct node *ptr)
{
    if (head == NULL)
    {
        return ptr;
    }

    struct node *ptr1 = head;
    while (ptr1->next != NULL)
    {
        ptr1 = ptr1->next;
    }
    ptr1->next = ptr;
    return head;
}

// traversal function
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

int main()
{
    float coeff;
    int exp;

    // nodal creation for the polynomial 1:
    printf("please enter the terms in polynomial 1:");
    int n1;
    scanf("%d", &n1);
    struct node *h1 = NULL;

    for (int i = 0; i < n1; i++)
    {
        printf("please enter the coefficient of term %d:", i + 1);
        scanf("%f", &coeff);
        printf("please enter the exponent of term %d:", i + 1);
        scanf("%d", &exp);
        h1 = append(h1, createnode(coeff, exp));
    }

    // nodal creation for the polynomial 2:
    printf("please enter the terms in polynomial 2:");
    int n2;
    scanf("%d", &n2);
    struct node *h2 = NULL;

    for (int i = 0; i < n2; i++)
    {
        printf("please enter the coefficient of term %d:", i + 1);
        scanf("%f", &coeff);
        printf("please enter the exponent of term %d:", i + 1);
        scanf("%d", &exp);
        h2 = append(h2, createnode(coeff, exp));
    }

    printf("performing polynomial addition:\n");

    struct node *h3 = NULL;
    while (h1 != NULL || h2 != NULL)
    {
        struct node *ptr3;
        if (h1 == NULL)
        {
            ptr3 = createnode(h2->coeff, h2->exp);
            h2 = h2->next;
        }
        else if (h2 == NULL)
        {
            ptr3 = createnode(h1->coeff, h1->exp);
            h1 = h1->next;
        }
        else if (h1->exp > h2->exp)
        {
            ptr3 = createnode(h1->coeff, h1->exp);
            h1 = h1->next;
        }
        else if (h2->exp > h1->exp)
        {
            ptr3 = createnode(h2->coeff, h2->exp);
            h2 = h2->next;
        }
        else // h1->exp == h2->exp
        {
            ptr3 = createnode(h1->coeff + h2->coeff, h1->exp);
            h1 = h1->next;
            h2 = h2->next;
        }

        h3 = append(h3, ptr3);
    }

    traverse(h3);

    // Free memory
    struct node *temp;
    while (h3 != NULL)
    {
        temp = h3;
        h3 = h3->next;
        free(temp);
    }

    return 0;
}
