#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    int coeff;
    int exp;
    struct node *next;
};

struct node *insert(int exp, int coeff, struct node *head)
{
    struct node *nn = (struct node *)malloc(sizeof(struct node));
    nn->coeff = coeff;
    nn->exp = exp;
    nn->next = NULL;
    if (head == NULL)
    {
        head = nn;
    }
    else
    {
        struct node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = nn;
    }
    return head;
}

struct node *createnode(int exp, int coeff)
{
    struct node *nn = (struct node *)malloc(sizeof(struct node));
    nn->coeff = coeff;
    nn->exp = exp;
    nn->next = NULL;
    return nn;
}

void traverse(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        if (temp->next == NULL)
        {
            printf("%dx^%d", temp->coeff, temp->exp);
        }
        else
        {
            printf("%dx^%d+", temp->coeff, temp->exp);
        }
        temp = temp->next;
    }
}

struct node *add(struct node *HEAD1, struct node *HEAD2, struct node *HEAD3)
{
    struct node *p1 = HEAD1;
    struct node *p2 = HEAD2;
    while (p1 != NULL && p2 != NULL)
    {
        if (p1->exp == p2->exp)
        {
            struct node *nn = createnode(p1->exp, p1->coeff + p2->coeff);
            if (HEAD3 == NULL)
            {
                HEAD3 = nn;
            }
            else
            {
                struct node *temp = HEAD3;
                while (temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = nn;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->exp > p2->exp)
        {
            struct node *nn = createnode(p2->exp, p2->coeff);
            if (HEAD3 == NULL)
            {
                HEAD3 = nn;
            }
            else
            {
                struct node *temp = HEAD3;
                while (temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = nn;
            }
            p2 = p2->next;
        }

        else if (p2->exp > p1->exp)
        {
            struct node *nn = createnode(p1->exp, p1->coeff);
            if (HEAD3 == NULL)
            {
                HEAD3 = nn;
            }
            else
            {
                struct node *temp = HEAD3;
                while (temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = nn;
            }
            p1 = p1->next;
        }

        else if (p1 == NULL)
        {
            while (p2 != NULL)
            {
                struct node *nn = createnode(p2->exp, p2->coeff);
                if (HEAD3 == NULL)
                {
                    HEAD3 = nn;
                }
                else
                {
                    struct node *temp = HEAD3;
                    while (temp->next != NULL)
                    {
                        temp = temp->next;
                    }
                    temp->next = nn;
                }
                p2 = p2->next;
            }
        }

        else if (p2 == NULL)
        {
            while (p1 != NULL)
            {
                struct node *nn = createnode(p1->exp, p1->coeff);
                if (HEAD3 == NULL)
                {
                    HEAD3 = nn;
                }
                else
                {
                    struct node *temp = HEAD3;
                    while (temp->next != NULL)
                    {
                        temp = temp->next;
                    }
                    temp->next = nn;
                }
                p1 = p1->next;
            }
        }
    }
    return HEAD3;
}

int main()
{
    int exp;
    int coeff;
    struct node *HEAD1 = NULL;
    struct node *HEAD2 = NULL;
    struct node *HEAD3 = NULL;

    printf("please enter the information of polynomial 1:\n");
    int choice;
    do
    {
        printf("do you want to add new term to polynomail :(1/0)");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            printf("please enter the exp of the term:");
            scanf("%d", &exp);
            printf("please enter the coeff of the term:");
            scanf("%d", &coeff);
            HEAD1 = insert(exp, coeff, HEAD1);
        }
        break;
        case 0:
        {
            printf("exitting the programme...");
        }
        break;
        default:
        {
            printf("please enter a valid choice");
        }
        break;
        }
    } while (choice != 0);
    printf("\n");

    traverse(HEAD1);
    printf("\n");

    printf("please enter the information of polynomial 2:\n");
    do
    {
        printf("do you want to add new term to polynomail :(1/0)");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            printf("please enter the exp of the term:");
            scanf("%d", &exp);
            printf("please enter the coeff of the term:");
            scanf("%d", &coeff);
            HEAD2 = insert(exp, coeff, HEAD2);
        }
        break;
        case 0:
        {
            printf("exitting the programme...");
        }
        break;
        default:
        {
            printf("please enter a valid choice");
        }
        break;
        }
    } while (choice != 0);
    printf("\n");
    traverse(HEAD2);
    printf("\n");

    printf("performing addition...");
    HEAD3 = add(HEAD1, HEAD2, HEAD3);
    traverse(HEAD3);

    return 0;
}