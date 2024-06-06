#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char name[1000];
    struct node *next;
};

void enque(char *name, struct node **front, struct node **rear)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    strcpy(node->name, name);
    node->next = NULL;
    
    if (*front == NULL)
    {
        *front = *rear = node;
    }
    else
    {
        (*rear)->next = node;
        (*rear) = node;
    }
}

void deque(struct node **front, struct node **rear)
{
    if (*front == NULL)
    {
        printf("the queue is empty....\n");
    }
    else
    {
        printf("the dequeued member is: %s\n", (*front)->name);
        struct node *temp = *front;
        *front = (*front)->next;
        free(temp);
        if (*front == NULL)
        {
            *rear = NULL;
        }
    }
}

int main()
{
    char name[1000];
    FILE *p;
    p = fopen("name.txt", "w");
    struct node *front = NULL;
    struct node *rear = NULL;
    
    printf("\nplease enter the choices mentioned below\n");
    printf("\n1) add member\n2) exit\n");
    
    int choice;
    do
    {
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
            {
                printf("please enter the name of the student: ");
                getchar(); // Consume newline character left in the buffer
                fgets(name, sizeof(name), stdin);
                fprintf(p, "%s", name);
                enque(name, &front, &rear);
            }
            break;
            case 2:
            {
                printf("\nexiting the program successfully....\n");
            }
            break;
            default:
            {
                printf("\nplease enter a valid choice...\n");
            }
            break;
        }
    } while (choice != 2);
    fclose(p);

    // Now linking the nodes and opening the file again to read the data into the nodes

    p = fopen("name.txt", "r");
    while (fgets(name, sizeof(name), p) != NULL)
    {
        name[strlen(name) - 1] = '\0'; // Remove the newline character
        enque(name, &front, &rear);
    }
    fclose(p);

    int que;
    do
    {
        printf("\n1) enque\n2) deque\n3) exit\n");
        printf("Please enter your choice: ");
        scanf("%d", &que);
        switch (que)
        {
            case 1:
            {
                printf("please enter the name of the student: ");
                getchar(); // Consume newline character left in the buffer
                fgets(name, sizeof(name), stdin);
                name[strlen(name) - 1] = '\0'; // Remove the newline character
                enque(name, &front, &rear);
                printf("successfully enqueued the element.\n");
            }
            break;
            case 2:
            {
                deque(&front, &rear);
            }
            break;
            case 3:
            {
                printf("exiting the program successfully...\n");
            }
            break;
            default:
            {
                printf("please enter a valid choice.\n");
            }
            break;
        }
    } while (que != 3);

    // Freeing allocated memory
    struct node *temp;
    while (front != NULL)
    {
        temp = front;
        front = front->next;
        free(temp);
    }

    return 0;
}
