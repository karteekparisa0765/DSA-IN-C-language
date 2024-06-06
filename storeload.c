#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void enque(int n);
int deque();
struct node
{
    int data;
    struct node *next;
};
typedef struct graph
{
    struct node **first;
    int *visited;
    int *vertex;

} GRAPH;

struct que
{
    int *s;
    int front;
    int rear;
} q;
void createque(int n)
{
    q.s = (int *)malloc(n * sizeof(int));
    q.front = -1;
    q.rear = -1;
    return;
}

GRAPH *creategraph(int n)
{
    GRAPH *g = (GRAPH *)malloc(n * sizeof(GRAPH));
    g->first = (struct node **)malloc(n * sizeof(struct node *));
    g->vertex = (int *)malloc(n * sizeof(int));
    g->visited = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        g->first[i] = NULL;
        g->visited[i] = 0;
    }

    return g;
}
struct node *createnode(int data)
{
    struct node *nn = (struct node *)malloc(sizeof(struct node));
    nn->data = data;
    nn->next = NULL;
    return nn;
}
GRAPH *insert(GRAPH *g, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("please enter the %dth vertex of the graph:", i);
        int data;
        scanf("%d", &g->vertex[i]);
    }
    int x;
    for (int i = 0; i < n; i++)
    {
        do
        {
            printf("would you like to add on adjacent vertex to %d:(1/0):", g->vertex[i]);
            scanf("%d", &x);
            if (x == 1)
            {
                printf("enter the index value of the node to be inserted:");
                int data;
                scanf("%d", &data);
                struct node *nn = createnode(data);
                if (g->first[i] == NULL)
                {
                    g->first[i] = nn;
                }
                else
                {
                    struct node *temp = g->first[i];
                    while (temp->next != NULL)
                    {
                        temp = temp->next;
                    }
                    temp->next = nn;
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
void BFS(GRAPH *g, int v, int x)
{
    // Reset visited array and create a new queue
    if (g->visited[v] == 0)
    {
        createque(x);
        enque(v);
        g->visited[v] = 1;
    }
    while (q.front <= q.rear)
    {
        int u = deque();
        printf("%d ", g->vertex[u]);  // Added space after the vertex
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

void display(GRAPH *g, int n)
{
    for (int v = 0; v < n; v++)
    {
        struct node *temp = g->first[v];
        printf("Adjacency list of vertex %d\n", v);
        while (temp)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void DFS(GRAPH *g, int v, int n)
{
    printf("%d ", g->vertex[v]);
    g->visited[v] = 1;
    struct node *tmp = g->first[v];
    while (tmp != NULL)
    {
        if (g->visited[tmp->data] == 0)
        {
            DFS(g, tmp->data, n);
            tmp = tmp->next;
        }
        else
        {
            tmp = tmp->next;
        }
    }
}

void enque(int n)
{
    if (q.front == -1 && q.rear == -1)
    {
        q.front = q.rear = 0;
    }
    else
    {
        q.rear++;
    }
    q.s[q.rear] = n;
}

int deque()
{
    if (q.front == -1 || q.front > q.rear)
    {
        printf("error");
    }
    int x = q.s[q.front];
    q.front++;
    return x;
}

int main()
{
    int n, choice, data;
    printf("Enter no of vertices:");
    scanf("%d", &n);
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
            printf("\n");
            break;
        default:
            break;
        }
    } while (choice > 0 && choice < 3);

    printf("adding the graph content into aptr");
    printf("please enter the name of theptr");

    // writing the graphs data to the file
    FILE *ptr;
    ptr = fopen("hero.txt", "w");
    fprintf(ptr, "%d\n", n);
    for (int i = 0; i < n; i++)
    {
        fprintf(ptr, "%d", g->vertex[i]);
        struct node *temp = g->first[i];
        while (temp != NULL)
        {
            fprintf(ptr, "%d", temp->data);
            temp = temp->next;
        }

        fprintf(ptr, "-1\n");
    }
    fclose(ptr);
    printf("graph stored sucessfully...");
    // loading the file
    FILE *ptr1;
    ptr1 = fopen("practice.txt", "r");
    int x1;

    fscanf(ptr1, "%d", &x1);
    GRAPH *g1 = creategraph(x1);

    for (int i = 0; i < x1; i++)
    {
        fscanf(ptr1, "%d", &g->vertex[i]);
        int data;

        while (fscanf(ptr1, "%d", &data) != EOF && data != -1)
        {
            struct node *nn = createnode(data);

            if (g->first[i] == NULL)
            {
                g->first[i] = nn;
            }
            else
            {
                struct node *temp = g->first[i];
                while (temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = nn;
            }
        }
    }
    BFS(g1,0,x1);
    fclose(ptr1);
    return 0;
}