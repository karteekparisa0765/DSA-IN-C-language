#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
struct node
{
    char name[100];
    struct node *next;
};
struct node *createnode(char word[])
{
    struct node *nn = (struct node *)malloc(sizeof(struct node));
    nn->next = NULL;
    strcpy(nn->name, word);
    return nn;
}

struct node *insert(struct node *head, char line[100])
{
    struct node *temp;
    int words = 0;
    int i = 0;
    int j = 0;
    char word[30];
    while (line[i] != '\0')
    {
        j = 0;
        while (!isspace(line[i]))
        {
            word[j] = line[i];
            i++;
            j++;
        }
        word[j] = '\0';
        struct node *nn = createnode(word);
        if (head == NULL)
        {
            head = temp = nn;
        }
        else
        {
            temp->next = nn;
            temp = nn;
        }
        words++;
        while (isspace(line[i]))
        {
            i++;
        }
    }
    printf("total words added are %d", words);
    return head;
}
void display(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%s-->", temp->name);
        temp = temp->next;
    }
}

int occurences(struct node *head, char word[30])
{
    struct node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        if (strcmp(word, temp->name) == 0)
        {
            count++;
        }
        temp = temp->next;
    }
    return count;
}

struct node *insertnew(struct node *head, char word[30])
{
    struct node *nn = createnode(word);
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
struct node *delete(struct node *head, char word[30])
{
    struct node *prev = NULL;
    struct node *temp = head;
    while (temp != NULL)
    {
        if (strcmp(temp->name, word) == 0)
        {
            if (prev == NULL)
            {
                head = temp->next;
                temp = head;
            }
            else
            {
                prev->next = temp->next;
                temp = prev->next;
            }
            continue; // Move to the next iteration
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

int main()
{
    struct node *head = NULL;
    char line[100];
    char word[30];
    char key[30];
    char del[30];
    printf("welcome to the line editor:\n");
    printf("please enter the string into the file:\n");
    FILE *ptr;
    ptr = fopen("names.txt", "w");
    fgets(line, sizeof(line), stdin);
    getchar();
    fputs(line, ptr);
    fclose(ptr);
    int choice;
    do
    {
        printf("please enter the operation to perform on the string");
        printf("\n1)insert\n2)display\n3)occurences\n4)insertnew\n5)delete\n6)exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            head = insert(head, line);
        }
        break;
        case 2:
        {
            display(head);
        }
        break;
        case 3:
        {
            printf("please enter the word for checking the occurences:");
            getchar();
            fgets(word, sizeof(word), stdin);
            word[strlen(word) - 1] = '\0';
            int x = occurences(head, word);
            printf("total occurences of %s is :%d", word, x);
        }
        break;
        case 4:
        {
            printf("enter the word to be inserted:");
            getchar();
            fgets(key, sizeof(key), stdin);
            key[strlen(key) - 1] = '\0';
            head = insertnew(head, key);
        }
        break;
        case 5:
        {
            printf("please enter the word to be deleted from the string:");
            getchar();
            fgets(del, sizeof(del), stdin);
            del[strlen(del) - 1] = '\0';
            head = delete (head, del);
        }
        break;
        case 6:
        {
            printf("exitting the programme...");
        }
        break;
        default:
        {
            printf("please enter the valid choice...");
        }
        break;
        }
    } while (choice != 6);
    return 0;
}