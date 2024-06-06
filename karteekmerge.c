#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Structure to represent the graph
struct Graph {
    int numVertices;
    struct Node** adjList;
};

// Function to create a new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with given number of vertices
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjList = (struct Node**)malloc(vertices * sizeof(struct Node));

    for (int i = 0; i < vertices; i++) {
        graph->adjList[i] = NULL;
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

// Function to print the graph
void printGraph(struct Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        struct Node* temp = graph->adjList[i];
        printf("Vertex %d:", i);
        while (temp != NULL) {
            printf(" -> %d", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int vertices, edges, src, dest,choice;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    struct Graph* graph = createGraph(vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        printf("Enter edge %d (src dest): ", i + 1);
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    printf("Graph before saving:\n");
    printGraph(graph);

    // Code for saving the graph to a file goes here
do{
    printf("1.save/t2.load/n");
   scanf("%d",&choice);
switch(choice){
    case 1: FILE *fp = fopen("graph_data.txt", "w");
    if (fp != NULL) {
        for (int i = 0; i < graph->numVertices; i++) {
            struct Node* temp = graph->adjList[i];
            fprintf(fp, "%d:", i);
            while (temp != NULL) {
                fprintf(fp, " -> %d", temp->vertex);
                temp = temp->next;
            }
            fprintf(fp, "\n");
        }
        fclose(fp);
        printf("Graph saved successfully!\n");
    } else {
        printf("Error opening file for writing.\n");
    } break;

    case 2 :// Code for loading the graph from a file goes here
    printf("Loading graph from file...\n");
    struct Graph* loadedGraph = createGraph(vertices);
    fp = fopen("graph_data.txt", "r");
    if (fp != NULL) {
        while (!feof(fp)) {
            int v;
            char c;
            fscanf(fp, "%d%c", &v, &c);
            while (c != '\n') {
                int neighbor;
                fscanf(fp, " -> %d%c", &neighbor, &c);
                addEdge(loadedGraph, v, neighbor);
            }
        }
        fclose(fp);
        printf("Graph loaded successfully!\n");

        printf("Graph after loading:\n");
        printGraph(loadedGraph);
    } else {
        printf("Error opening file for reading.\n");
    }break;
default : break;
}}while(choice>0 && choice<3);
    return 0;
}