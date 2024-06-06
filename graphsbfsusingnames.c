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
    char **vertex; // changes
    struct node **first;

} GRAPH;

typedef struct que
{
    int *s;
    int front;
    int rear;

} QUE;

QUE q;

GRAPH *creategraph(int x)
{
    GRAPH *g = (GRAPH *)malloc(sizeof(GRAPH));
    g->first = (struct node **)malloc(x * sizeof(struct node *));
    g->visited = (int *)malloc(x * sizeof(int));
    g->vertex = (char **)malloc(x * sizeof(char *)); // changes
    for (int i = 0; i < x; i++)
    {
        g->visited[i] = 0;
        g->first[i] = NULL;
        g->vertex[i] = (char *)malloc(100 * sizeof(char)); // changes
    }
    return g;
}

struct node *createnode(int data)
{
    struct node *nn = (struct node *)malloc(sizeof(struct node));
    nn->next = NULL;
    nn->data = data;
    return nn;
}

void createque(int n)
{
    q.s = (int *)malloc(n * sizeof(int));
    q.front = -1;
    q.rear = -1;
}

void enque(int x)
{
    if (q.front == -1)
    {
        q.front = 0;
    }
    q.rear++;
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
    int x, data;
    char name[100];
    FILE *ptr = fopen("nodex.txt", "r");
    for (int i = 0; i < n; i++)
    {
        fgets(name, sizeof(name), ptr); // changes
        name[strlen(name) - 1] = '\0';
        strcpy(g->vertex[i], name);
    }
    fclose(ptr);

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

GRAPH *refresh(GRAPH *g, int n)
{
    for (int i = 0; i < n; i++)
    {
        g->visited[i] = 0;
    }
    return g;
}

void BFS(GRAPH *g, int v, int n)
{
    g = refresh(g, n);
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
        struct node *tmp = g->first[u];
        while (tmp != NULL)
        {
            int w = tmp->data;
            if (g->visited[w] == 0)
            {
                enque(w);
                g->visited[w] = 1;
            }
            tmp = tmp->next;
        }
    }
    printf("\n");
}

int main()
{
    FILE *ptr;
    ptr = fopen("nodex.txt", "w");
    printf("enter the names of the vertex one by one:");
    char name[100];

    int n, choice, data;
    printf("Enter no of vertices:");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        getchar();
        fgets(name, sizeof(name), stdin);
        fputs(name, ptr);
    }
    fclose(ptr);

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
