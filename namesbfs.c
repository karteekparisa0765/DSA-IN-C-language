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
    char **vertex; // Change to char **
    struct node **first;
} GRAPH;

typedef struct que
{
    int *s;
    int front;
    int rear;
} QUE;

QUE q;

GRAPH *creategraph(int n)
{
    GRAPH *g = (GRAPH *)malloc(sizeof(GRAPH));
    g->first = (struct node **)malloc(n * sizeof(struct node *));
    g->visited = (int *)malloc(n * sizeof(int));
    g->vertex = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++)
    {
        g->first[i] = NULL;
        g->visited[i] = 0;
        g->vertex[i] = (char *)malloc(100 * sizeof(char));
    }
    return g;
}
void createqueue(int n)
{
    q.s = (int *)malloc(n * sizeof(int));
    q.front = -1;
    q.rear = -1;
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
    char name[100];
    int x;

    for (int i = 0; i < n; i++)
    {
        printf("please enter the vertex:");
        getchar();
        fgets(name, sizeof(name), stdin);
        name[strlen(name) - 1] = '\0';
        strcpy(g->vertex[i], name); // Copy the vertex name
    }
    for (int i = 0; i < n; i++)
    {
        do
        {
            printf("do you want to add any adjacent vertex for %s (1/0)? ", g->vertex[i]);
            scanf("%d", &x);
            if (x == 1)
            {
                printf("enter the adjacent vertex index: ");
                int data;
                scanf("%d", &data);
                struct node *nn = (struct node *)malloc(sizeof(struct node));
                nn->data = data;
                nn->next = NULL;
                if (g->first[i] == NULL)
                {
                    g->first[i] = nn;
                }
                else
                {
                    struct node *temp = g->first[i];
                    while (temp->next != NULL)
                    { // Traverse to the last node in the list
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
        printf("%s ", g->vertex[u]);
        struct node *tmp = g->first[u];
        while (tmp != NULL)
        {
            int w = tmp->data;
            if (g->visited[w] == 0)
            {
                Enqueue(w);
                g->visited[w] = 1;
            }
            tmp = tmp->next;
        }
    }
    printf("\n");
}

int main()
{
    int n;
    printf("please enter the number of vertices: ");
    scanf("%d", &n);
    GRAPH *g = creategraph(n);

    g = insert(g, n);

    int key;
    printf("please enter the target vertex index value for BFS: ");
    scanf("%d", &key);
    BFS(g, key, n);

    return 0;
}
