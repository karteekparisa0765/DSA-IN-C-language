#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
    char word[100];
    struct node *next;
    struct node *prev;
} NODE;
typedef struct linehead
{
    NODE *first;
    struct linehead *next;
    struct linehead *prev;
    int wc;
} LINE;
typedef struct head
{
    int lc;
    int twc;
    LINE *start;
    LINE *end;
} HEAD;
NODE *createnode(char word[30])
{
    NODE *nn = (NODE *)malloc(sizeof(NODE));
    nn->next = NULL;
    nn->prev = NULL;
    strcpy(nn->word, word);
    return nn;
}
LINE *createline()
{
    LINE *lh = (LINE *)malloc(sizeof(LINE));
    lh->first = NULL;
    lh->next = NULL;
    lh->prev = NULL;
    lh->wc = 0;
    return lh;
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
// function for inserting a whole line consisting of words took as user input from user as string

HEAD *insert(HEAD *head, char line[100])
{
    char word[30];
    int i = 0;
    int j = 0;
    NODE *last;
    LINE *lh = createline();
    // already head is present mention in the main function so no need again
    if (head->start == NULL)
    {
        head->start = lh;
        head->end = lh;
    }
    else
    {
        lh->prev = head->end;
        head->end->next = lh;
        head->end = lh;
    }
    // connected the head pointer and the line head
    // now connecting the words
    while (line[i] != '\0')
    {
        j = 0; // to copy from beginning into the word
        while (!isspace(line[i]))
        { // loop until the space is encounter
            word[j] = line[i];
            j++;
            i++; // will stop when the space is encountered
        }
        word[j] = '\0'; // last word is NULL not a newline character
        NODE *nn = createnode(word);
        if (lh->first == NULL)
        {
            lh->first = nn;
            last = nn; // works like a temp pointer
        }
        else
        {
            nn->prev = last;
            last->next = nn;
            last = nn;
        }
        (lh->wc)++;
        while (isspace(line[i]))
        {
            i++;
        } // this line will escape all the spaces and land on the starting position of another word
    }
    head->twc = head->twc + lh->wc;
    (head->lc)++;
    return head;
}

void display(HEAD *head)
{
    LINE *lh = head->start;
    int i = 1;
    while (lh != NULL)
    {
        printf("\n%d.", i);
        NODE *temp = lh->first;
        while (temp != NULL)
        {
            printf("%s ", temp->word);
            temp = temp->next;
        }
        lh = lh->next;
        i++;
    }
    printf("total words:%d", head->twc);
    printf("total lines:%d", head->lc);
}

HEAD *delete(HEAD *head, int lno)
{
    LINE *currline = head->start;
    NODE *curnode = currline->first;
    int count = 1;
    if (head->start == NULL)
    {
        printf("no lines");
    }
    if (head->start == head->end)
    {
        head->end = NULL;
        head->start = NULL;
    }
    if (lno == 1)
    {
        head->twc = head->twc - head->start->wc;
        head->start = head->start->next;
        head->start->prev = NULL;
        (head->lc--);
        return head;
    }
    while (currline->next != NULL && count == lno - 1)
    {
        currline = currline->next;
        count++;
    }
    if (currline->next != NULL && count == lno - 1)
    { // for deelting the random line
        head->twc = head->twc - currline->next->wc;
        currline->next = currline->next->next;
        currline->next->prev = currline;
        (head->lc)--;
        return head;
    }
    if (currline->next == head->end && count == count - 1)
    {
        head->twc = head->twc - currline->next->wc;
        currline->next = NULL;
        currline->next->prev = currline;
        (head->lc)--;

        return head;
    }
    printf("line dont exist");
}
HEAD *insertatrandom(HEAD *head, char line[100], int x)
{
    NODE *last = NULL;
    LINE *lh = createline();
    int i = 0;
    int j = 0;
    int count = 1;
    char word[100];
    while (line[i] != '\0')
    {
        j = 0;
        while (!isspace(line[i]))
        {
            word[j] = line[i];
            i++;
            j++;
            if (line[i] == '\0')
            {
                break;
            }
        }
        word[j] = '\0';
        NODE *nn = createnode(word);
        if (lh->first == NULL)
        {
            lh->first = nn;
            last = nn;
        }
        else
        {
            nn->prev = last;
            last->next = nn;
            last = nn;
        }
        (lh->wc)++;
        while (isspace(line[i]))
            i++;
    }
    if (x == 1)
    {
        lh->next = head->start;
        head->start->prev = lh;
        head->start = lh;
        (head->lc)++;
        head->twc += lh->wc;
        return head;
    }
    LINE *tmp = head->start;
    while (tmp != NULL && count != x - 1)
    {
        tmp = tmp->next;
        count++;
    }
    if (tmp != NULL && count == x - 1)
    {
        lh->prev = tmp;
        lh->next = tmp->next;
        tmp->next->prev = lh;
        tmp->next = lh;
        (head->lc)++;
        head->twc += lh->wc;
        return head;
    }
    printf("Line doesn't exit\n");
}

int main()
{
    return 0;
}