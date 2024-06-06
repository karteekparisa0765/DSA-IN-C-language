#include <stdio.h> #include<stdlib.h> #include<string.h>
typedef struct node
{
    int data;
    struct node *link;
} NODE;
typedef struct graph
{
    int *visited, *vertex;
    NODE **first;
} GRAPH;
typedef struct queue
{
    int front, rear;
    int *s;
} QUEUE;
QUEUE q;
GRAPH *creategraph(int n)
{
    GRAPH *g = (GRAPH *)malloc(n * sizeof(GRAPH *));
    g->first = (NODE **)malloc(n * sizeof(NODE *));
    g->visited = (int *)malloc(n * sizeof(int));
    g->vertex = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        g->visited[i] = 0;
        g->first[i] = NULL;
    }
    return g;
}
void createqueue(int n)
{
    q.s = (int *)malloc(n * sizeof(int));
    q.front = -1;
    q.rear = -1;
}
NODE *createnode(int x)
{
    NODE *newnode = (NODE *)malloc(sizeof(NODE));
    newnode->data = x;
    newnode->link = NULL;
    return newnode;
}
void Enqueue(int x)
{
    if (q.rear == -1 && q.front == -1)
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
int Dequeue()
{
    int x;
    if (q.front == -1 || q.front > q.rear)
    {
        printf("Queue overflows\n");
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
    for (int i = 0; i < n; i++)
    {
        printf("Enter the vertex name:");
        scanf("%d", &g->vertex[i]);
    }
    for (int i = 0; i < n; i++)
    {
        do
        {
            printf("Do you have any adjacent vertex for %d:(1/0)", g->vertex[i]);
            scanf("%d", &x);
            if (x == 1)
            {
                printf("Enter the index value of adjacent vertex for %d:", g->vertex[i]);
                scanf("%d", &data);
                NODE *nn = createnode(data);
                if (g->first[i] == NULL)
                {
                    g->first[i] = nn;
                }
                else
                {
                    NODE *tmp;
                    tmp = g->first[i];
                    while (tmp->link != NULL)
                    {
                        tmp = tmp->link;
                    }
                    tmp->link = nn;
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
        createqueue(n);
        Enqueue(v);
        g->visited[v] = 1;
    }
    while (q.front <= q.rear)
    {
        int u = Dequeue();
        printf("%d ", g->vertex[u]);
        NODE *tmp = g->first[u];
        while (tmp != NULL)
        {
            int w = tmp->data;
            if (g->visited[w] == 0)
            {
                Enqueue(w);
                g->visited[w] = 1;
            }
            tmp = tmp->link;
        }
    }
    printf("\n");
}
void DFS(GRAPH *g, int v, int n)
{
    printf("%d ", g->vertex[v]);
    g->visited[v] = 1;
    NODE *tmp = g->first[v];
    while (tmp != NULL)
    {
        if (g->visited[tmp->data] == 0)
        {
            DFS(g, tmp->data, n);
            tmp = tmp->link;
        }
        else
        {
            tmp = tmp->link;
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
    printf("adding the details into the file...");
    printf("please enter the name of the fukr");

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