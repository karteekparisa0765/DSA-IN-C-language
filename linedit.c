#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>//used isspace for that
typedef struct node
{
    struct node *prev;
    struct node *next;
    char word[30];
} NODE;
typedef struct linehead
{
    struct linehead *p, *n;
    NODE *first;
    int wc;
} LINE;
typedef struct head
{
    LINE *start, *end;
    int lc, twc;
} HEAD;
NODE *createnode(char word[30])
{
    NODE *newnode = (NODE *)malloc(sizeof(NODE));
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
HEAD *insert(HEAD *head, char line[100])//for inserting on
{
    char word[30];
    int i = 0, j = 0;
    NODE *last;
    LINE *lh = createline();
    if (head->start == NULL)
    {
        head->start = lh;
        head->end = lh;
    }
    else
    {
        lh->p = head->end;
        head->end->n = lh;
        head->end = lh;
    }//ok 
    while (line[i] != '\0')//taking the string input and checking it until the null of the line is encountered i here s character
    {
        j = 0;
        while (!isspace(line[i]))//until the space in the word is encountered
        {
            word[j] = line[i];
            j++;
            i++;
            if (line[i] == '\0')
                break;
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
    head->twc += lh->wc;
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
        NODE *tmp = lh->first;
        while (tmp != NULL)
        {
            printf("%s ", tmp->word);
            tmp = tmp->next;
        }
        lh = lh->n;
        i++;
    }
    printf("\n");
    printf("No of words:%d\n", head->twc);
    printf("No of lines:%d\n", head->lc);
}

HEAD *delete(HEAD *head, int lno)
{
    LINE *cur_line = head->start;//for accessing the line head
    NODE *cur_node = cur_line->first;//for accessing the words in the linehead
    int count = 1;
    if (head->start == NULL)
    {
        printf("Empty");
        return head;
    }
    if (head->start == head->end)
    {//for only one line
        head->start = head->end = NULL;//deleting the whole line by removing the line head node
        head->lc = 0;
        head->twc = 0;
        return head;
    }
    if (lno == 1)//for first line out of so many
    {
        head->twc -= head->start->wc;//head twc=headtwc-head start line wc
        head->start = head->start->n;//updating the pointer
        head->start->p = NULL;//updating the previous pointer
        (head->lc)--;//decrementing the line count as one line is deleted
        return head;
    }
    while (cur_line->n != NULL && count != lno - 1)
    {
        count++;
        cur_line = cur_line->n;
    }
    if (cur_line->n == head->end && count == lno - 1)//if current line next is a last line
    {
        head->twc -= cur_line->n->wc;
        cur_line->n = NULL;
        head->end = cur_line;
        (head->lc)--;
        return head;
    }
    if (cur_line->n != NULL && count == lno - 1)
    {
        head->twc -= cur_line->n->wc;//for deletinga ny random line
        cur_line->n = cur_line->n->n;
        cur_line->n->p = cur_line;
        (head->lc)--;

        return head;
    }
    printf("The line doesn't exist\n");
}

void find(HEAD *head, char arr[])
{
    LINE *cur_line = head->start;
    NODE *cur_node;
    int count = 0, i = 1, j = 0;
    while (arr[j] != '\n')
    {
        j++;
    }
    arr[j] = '\0';
    if (head->start == NULL)
    {
        printf("Empty\n");
    }
    printf("Ocurrance of %s word is in:\n", arr);
    while (cur_line != NULL)
    {
        count = 0;
        int flag = 0;
        char a[30];
        cur_node = cur_line->first;
        while (cur_node != NULL)
        {
            count++;//WORD NUMBER
            if (strcmp(cur_node->word, arr) == 0)
            {
                flag++;//NUMBER OF SAME WORDS
                printf("%dth line,%dth position\n", i, count);
            }//I IS FOR LINE NUMBRE
            cur_node = cur_node->next;
        }
        cur_line = cur_line->n;
        i++;
    }
}
HEAD *insert_at_random(HEAD *head, char line[100], int x)
{
    LINE *lh = createline();
    char word[30];
    NODE *last;
    int i = 0, k, count = 1;
    while (line[i] != '\0')
    {
        k = 0;
        while (!isspace(line[i]))
        {
            word[k++] = line[i++];
            if (line[i] == '\0')
                break;
        }
        word[k] = '\0';
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
//above code was for the creation of a new line and now we nee to add it in the ll
    if (x == 1)
    {
        lh->n = head->start;
        head->start->p = lh;
        head->start = lh;
        (head->lc)++;
        head->twc += lh->wc;
        return head;
    }
    LINE *tmp = head->start;
    while (tmp != NULL && count != x - 1)
    {
        tmp = tmp->n;
        count++;
    }
    if (tmp != NULL && count == x - 1)
    {
        lh->p = tmp;
        lh->n = tmp->n;
        tmp->n->p = lh;
        tmp->n = lh;
        (head->lc)++;
        head->twc += lh->wc;
        return head;
    }
    printf("Line doesn't exit\n");
    return head;
}

void main()
{
    HEAD *head = createhead();
    char line[100];
    int choice, x;
    do
    {
        printf("1.insert\t2.display\t3.Delete\t4.Search\t5.Insert at random\n");
        printf("Enter your choice:");
        scanf("%d", &choice);
        fflush(stdin);
        switch (choice)
        {
        case 1:
            fflush(stdin);
            getchar();
            printf("Enter the string:");
            fflush(stdin);
            fgets(line, 100, stdin);
            head = insert(head, line);
            break;
        case 2:
            display(head);
            break;
        case 3:
            printf("Enter the line you want to delete:");
            scanf("%d", &x);
            head = delete (head, x);
            break;
        case 4:
            getchar();
            printf("Enter the word you want to search:");
            fgets(line, 100, stdin);
            find(head, line);
            break;
        case 5:
            getchar();
            printf("Enter the string:");
            fgets(line, 100, stdin);
            printf("Enter the string where to be inserted:");
            scanf("%d", &x);
            head = insert_at_random(head, line, x);
            break;
        default:
            break;
        }
    } while (choice > 0 && choice < 6);
    printf("The End\n");
}