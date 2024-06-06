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
    int *vertex;
    int *visited;
    struct node **first;
} GRAPH;

struct que
{
    int *s;
    int front;
    int rear;
} q;
struct node *createnode(int data)
{
    struct node *nn = (struct node *)malloc(sizeof(struct node));
    nn->data = data;
    nn->next = NULL;
    return nn;
}

GRAPH *creategraph(int n)
{
    GRAPH *g = (GRAPH *)malloc(n * sizeof(GRAPH *));
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
        q.front = 0;
        q.rear = 0;
    }
    else
    {
        q.rear++;
    }
    q.s[q.rear] = x;
    return;
}
int deque()
{
    if (q.front == -1 || q.front > q.rear)
    {
        printf("que overflow");
    }

    int x = q.s[q.front];
    q.front++;

    return x;
}

GRAPH *insert(GRAPH *g, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("enter the vertex at %d", i);
        scanf("%d", &g->vertex[i]);
    }
    printf("added vertex properly...");
    for (int i = 0; i < n; i++)
    {
        int x;
        do
        {
            printf("would you like to add adjacent vertex to %d:(0/1)", g->vertex[i]);
            scanf("%d", &x);
            if (x == 1)
            {
                int data;
                printf("please enter the data to be inserted:");
                scanf("%d", &data);
                struct node *new = createnode(data);
                if (g->first[i] == NULL)
                {
                    g->first[i] = new;
                }
                else
                {
                    struct node *temp = g->first[i];
                    while (temp->next != NULL)
                    {
                        temp = temp->next;
                    }
                    temp->next = new;
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
    refresh(g, n);
    if (g->visited[v] == 0)
    {
        createque(n);
        enque(g->vertex[v]);
        g->visited[v] = 1;
    }
    while (q.front < q.rear)
    {
        int u = deque();
        printf("%d ", g->vertex[u]);
        struct node *temp = g->first[u];
        while (temp != NULL)
        {
            int w = temp->data;
            if (g->visited[w] == 0)
            {
                enque(g->vertex[w]);
                g->visited[w] = 1;
            }
            temp = temp->next;
        }
    }
    printf("\n");
    return;
}

void DFS(GRAPH *g, int v, int n)
{
    printf("%d ", g->vertex[v]);
    g->visited[v] = 1;
    struct node  *tmp = g->first[v];
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
            DFS(g, data, n);
            printf("\n");
            break;
        default:
            break;
        }
    } while (choice > 0 && choice < 3);
    printf("The end\n");
    return 0;
}