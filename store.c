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
    GRAPH *g = (GRAPH *)malloc(n * sizeof(GRAPH));
    g->vertex = (int *)malloc(n * sizeof(int));
    g->visited = (int *)malloc(n * sizeof(int));
    g->first = (struct node **)malloc(n * sizeof(struct node *));

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
    return;
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
    int x;
    if (q.front == -1 || q.front > q.rear)
    {
        printf("que underflow");
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
    for (int i = 0; i < n; i++)
    {
        printf("enter the %dth vertex", i);
        scanf("%d", &g->vertex[i]);
    }
    printf("vertex created...");
    int x;
    for (int i = 0; i < n; i++)
    {
        do
        {
            printf("would you like to add adjacent vertex to the vertex:%d(1/0)", g->vertex[i]);
            scanf("%d", &x);
            if (x == 1)
            {
                printf("enter the index of the data to insert:");
                int data;
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
        printf("%d", g->vertex[u]);
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
    return;
}
void display(GRAPH *graph, int x)
{
    for (int v = 0; v < x; v++)
    {
        struct node *temp = graph->first[v];
        printf("Adjacency list of vertex %d\n", v);
        while (temp)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }}

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
                display(g, n);
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
        getchar();


    

FILE*ptr1 = fopen("adj.txt", "w");
    if (ptr1) {
        printf("Error openingptr for writing.\n");
       
    }
    fprintf(ptr1, "%d\n", n);
    for (int i = 0; i < n; i++) {
        fprintf(ptr1, "%d ", g->vertex[i]);
        struct node* temp = g->first[i];
        while (temp!=NULL) {
            fprintf(ptr1, "%d ", temp->data);
            temp = temp->next;
        }
        fprintf(ptr1, "-1\n");
    }
    fclose(ptr1);
    printf("Graph data stored successfully.\n");



FILE*ptr = fopen("adj.txt", "r");
    if (ptr==NULL) {
        printf("Error openingptr for reading.\n");
    }

    fscanf(ptr, "%d", &n);
    GRAPH* g1 = creategraph(n);
    for (int i = 0; i < n; i++) {
        fscanf(ptr, "%d", &g1->vertex[i]);
        int data;
        while (fscanf(ptr, "%d", &data) != EOF && data != -1) {
            struct node* new_node = createnode(data);
            if (!g1->first[i]) {
                g1->first[i] = new_node;
            } else {
                struct node* temp = g1->first[i];
                while (temp->next) {
                    temp = temp->next;
                }
                temp->next = new_node;
            }
        }
    }
    fclose(ptr);
    printf("Loaded graph:\n");
    display(g1, n);



        return 0;
    }