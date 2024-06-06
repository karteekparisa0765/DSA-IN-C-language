#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int deque();
void enque(int x);
struct node
{
    int data;
    struct node *next;
};
typedef struct graph
{
    int *visited;
    int *vertex;
    struct node **first;
} GRAPH;
typedef struct que
{
    int *s;
    int front;
    int rear;
} Q;
Q q;
GRAPH *creategraph(int n)
{
    GRAPH *g = (GRAPH *)malloc(sizeof(GRAPH));
    g->first = (struct node **)malloc(n * sizeof(struct node *));
    g->vertex = (int *)malloc(n * sizeof(int));
    g->visited = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        g->visited[i] = 0;
        g->first[i] = NULL;
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
void createque(int n)
{
    q.s = (int *)malloc(n * sizeof(int));
    q.front = -1;
    q.rear = -1;
}

GRAPH *insert(GRAPH *g, int n)
{
    int x, data;
    for (int i = 0; i < n; i++)
    {
        printf("please enter the vertex %d", i + 1);
        scanf("%d", &g->vertex[i]);
    }
    for (int i = 0; i < n; i++)
    {
        do
        {

            printf("do you have any adjacent vertex for %d:(1/0)", g->vertex[i]);
            scanf("%d", &x);
            if (x == 1)
            {
                printf("enter the vertex index of the adjacent vertex:");
                scanf("%d", &data);
                struct node *nn = (struct node *)malloc(sizeof(struct node));
                nn->data = data;
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
void enque(int x)
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
GRAPH *refresh(GRAPH *g, int n)
{
    for (int i = 0; i < n; i++)
    {
        g->visited[i] = 0;
    }
    return g;
}

void bfs(GRAPH *g, int v, int n)
{
    g = refresh(g, n); // Refresh visited status of all vertices
    if (g->visited[v] == 0)
    {
        createque(n);      // Create a queue with capacity 'n'
        enque(v);          // Enqueue the starting vertex 'v'
        g->visited[v] = 1; // Mark the starting vertex as visited
    }
    while (q.front <= q.rear) // While the queue is not empty
    {
        int u = deque();                 // Dequeue a vertex from the queue
        printf("%d", g->vertex[u]);      // Print the dequeued vertex
        struct node *temp = g->first[u]; // Get the adjacency list of the dequeued vertex
        while (temp != NULL)             // Traverse the adjacency list
        {
            int w = temp->data;     // Get the adjacent vertex
            if (g->visited[w] == 0) // If the adjacent vertex is not visited
            {
                enque(w);          // Enqueue the adjacent vertex
                g->visited[w] = 1; // Mark the adjacent vertex as visited
            }
            temp = temp->next; // Move to the next node in the adjacency list
        }
    }
}

int deque()
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
int main()
{
    printf("please enter the number of vertex:");
    int n;
    scanf("%d", &n);
    GRAPH *g = creategraph(n);

    g = insert(g, n);
    printf("pleasee enter the target vertex index value of the node to perform the traversal:");
    int key;
    scanf("%d", &key);
    bfs(g, key, n);

    return 0;
}