#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
struct node
{
    struct node *prev;
    struct node *next;
    char word[30];
};
typedef struct linehead
{
    struct linehead *p, *n;
    struct node **first;
    int wc;
} LINE;
typedef struct head
{
    LINE *start, *end;
    int lc, twc;
} HEAD;
struct node *createnode(char word[30])
{
    struct node *newnode = (struct node **)malloc(sizeof(struct node *));
    newnode->prev = NULL;
    newnode->next = NULL;
    strcpy(newnode->word, word);
    return newnode;
}
HEAD *createhead()
{
    HEAD *head = (HEAD *)malloc(sizeof(HEAD));
    head->start = NULL;
    head->end = NULL;
    head->lc = 0;
    head->twc = 0;
    return head;
}
LINE *createline() // with line head
{
    LINE *lh = (LINE *)malloc(sizeof(LINE));
    lh->p = NULL;
    lh->n = NULL;
    lh->first = NULL;
    lh->wc = 0;
    return lh;
}

HEAD *insert(HEAD *head, char line[100])
{
    struct node *temp;
    int i = 0;
    int j = 0;
    char word[30];
    LINE *lh = createline();
    if (head->start == NULL)
    {
        head->start = head->end = lh;
    }
    else
    {
        lh->p = head->end;
        head->end->n = lh;
        head->end = lh;
    }
    while (line[i] != '\0')
    {
        j = 0;
        while (!isspaceline(line[i]))
        {
            word[j] = line[i];
            i++;
            j++;
        }
        word[j] = '\0';
        struct node *nn = createnode(word);
        if (lh->first == NULL)
        {
            lh->first = nn;
            temp = nn;
        }
        else
        {
            nn->prev = temp;
            temp->next = nn;
            temp = nn;
        }
        (lh->wc)++;
        while (isspace(line[i]))
        {
            i++;
        }
    }
    head->lc++;
    head->twc = head->twc + lh->wc;
    return head;
}
HEAD *delete(HEAD *head, int n)
{
    if (head->start==NULL)
    {
        printf("empty");
    }
    if(head->start==head->end){
        head->start=head->end=NULL;
        head->twc=0;
        head->lc=0;
        return head;
    }
    if(n==1){
        head->twc=head.
        head->start=head->start->n;
        head->start->p=NULL;
        
    }
}

int main()
{

    return 0;
}