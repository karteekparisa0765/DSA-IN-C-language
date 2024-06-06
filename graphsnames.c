#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct graph
{
    int *visited;
    char **vertex;
    struct node **first;

} GRAPH;

typedef struct que
{
    int *s;
    int front;
    int rear;

} QUE;

QUE q;

struct node *createnode(int data)
{
    struct node *nn = (struct node *)malloc(sizeof(struct node));
    nn->data = data;
    nn->next = NULL;
    return nn;
}

GRAPH *creategraph(int n)
{
    GRAPH *g = (GRAPH *)malloc(sizeof(GRAPH));
    g->visited = (int *)malloc(n * sizeof(int));
    g->first = (struct node **)malloc(n * sizeof(struct node *));
    g->vertex = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++)
    {
        g->vertex[i] = (char *)malloc(100 * sizeof(char));
        g->visited[i] = 0;
        // Remove this line to prevent memory leak
        // g->vertex[i] = NULL;
        g->first[i] = NULL; // Initialize the adjacency list to NULL
    }
    return g;
}

void createque(int n)
{
    q.s = (int *)malloc(n * sizeof(int));
    q.front = -1;
    q.rear = -1;
}

void enque(int x)
{
    if (q.front == -1 && q.rear == -1)
    {
        q.front = q.rear = 0;
    }
    else
    {
        q.rear++;
    }
    q.s[q.rear] = x;
}

int deque()
{
    int x;
    if (q.front == -1 || q.front > q.rear)
    {
        printf("underflow");
        return -1;
    }
    else
    {
        x = q.s[q.front];
        q.front++;
    }
    return x;
}

GRAPH *insert(GRAPH *g, int n)
{

    char name[100];
    FILE *ptr = fopen("nodex.txt", "r");
    for (int i = 0; i < n; i++)
    {
        fgets(name, sizeof(name), ptr); // changes
        name[strlen(name) - 1] = '\0';
        strcpy(g->vertex[i], name);
    }
    fclose(ptr);
    int x;
    int data;
    for (int i = 0; i < n; i++)
    {
        do
        {
            printf("Do you have any adjacent vertex for %s:(1/0)", g->vertex[i]);
            scanf("%d", &x);
            if (x == 1)
            {
                printf("Enter the index value of adjacent vertex for %s:", g->vertex[i]);
                scanf("%d", &data);
                struct node *nn = createnode(data);
                if (g->first[i] == NULL)
                {
                    g->first[i] = nn;
                }
                else
                {
                    struct node *tmp = g->first[i];
                    while (tmp->next != NULL)
                    {
                        tmp = tmp->next;
                    }
                    tmp->next = nn;
                }
            }
        } while (x == 1);
    }
    return g;
}

void BFS(GRAPH *g, int v, int n)
{
    if (g->visited[v] == 0)
    {
        createque(n);
        enque(v);
        g->visited[v] = 1;
    }
    while (q.front <= q.rear)
    {
        int u = deque();
        printf("%s ", g->vertex[u]);
        struct node *temp = g->first[u];
        while (temp != NULL)
        {
            int w = temp->data;
            if (g->visited[w] == 0)
            {
                enque(w);
                g->visited[w] = 1;
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

GRAPH *refresh(GRAPH *g, int n)
{
    for (int i = 0; i < n; i++)
    {
        g->visited[i] = 0;
    }
    return g;
}

int main()
{
    char name[100];
    printf("please enter the number of nodes to be inserted:\n");
    int n;
    scanf("%d", &n);
    FILE *ptr;
    ptr = fopen("nodex.txt", "w");
    for (int i = 0; i < n; i++)
    {
        printf("enter the vertex %d:", i + 1);
        getchar();
        fgets(name, sizeof(name), stdin);
        fputs(name, ptr);
    }
    fclose(ptr);
    int choice;
    int data;
    GRAPH *g = creategraph(n);
    do
    {
        printf("1.create Graph\t2.Traverse\n");
        printf("Enter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            g = insert(g, n);
            break;
        case 2:
            printf("Enter the index value of starting vertex:");
            scanf("%d", &data);
            printf("BFS-");
            BFS(g, data, n);
            g = refresh(g, n);
            printf("DFS-");
            // Implement DFS function
            printf("\n");
            break;
        default:
            break;
        }
    } while (choice > 0 && choice < 3);
    printf("The end\n");
    printf("Adding the details into the file...");
    printf("please enter the name of the fukr");

    return 0;
}