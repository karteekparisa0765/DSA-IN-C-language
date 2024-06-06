#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Define the structure for a graph
typedef struct Graph {
    int numVertices;
    Node** adjLists;
} Graph;

// Function to create a graph with a specified number of vertices
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;

    graph->adjLists = (Node**)malloc(vertices * sizeof(Node*));
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = dest;
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;


    newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = src;
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Function to display the graph
void displayGraph(Graph* graph) {
    for (int v = 0; v < graph->numVertices; v++) {
        Node* temp = graph->adjLists[v];
        printf("Adjacency list of vertex %d\n", v);
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Function to store the graph data to a file
void storeGraph(Graph* graph, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        fprintf(stderr, "Error opening file for writing.\n");
        return;
    }

    fprintf(file, "%d\n", graph->numVertices);

    for (int v = 0; v < graph->numVertices; v++) {
        Node* temp = graph->adjLists[v];
        fprintf(file, "%d", v);
        while (temp) {
            fprintf(file, " %d", temp->vertex);
            temp = temp->next;
        }
        fprintf(file, "\n");
    }

    fclose(file);
}

// Function to load the graph data from a file
Graph* loadGraph(const char* filename) {

    FILE* file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error opening file for reading.\n");
        return NULL;
    }

    int numVertices;
    if (fscanf(file, "%d", &numVertices) != 1) {
        fprintf(stderr, "Error reading the number of vertices.\n");
        fclose(file);
        return NULL;
    }

    Graph* graph = createGraph(numVertices);
            displayGraph(graph);


    for (int v = 0; v < numVertices; v++) {
        int vertex;
        if (fscanf(file, "%d", &vertex) != 1 || vertex != v) {
            fprintf(stderr, "Error reading vertex number.\n");
            fclose(file);
            return NULL;
        }
        while (fscanf(file, "%d", &vertex) == 1) {
            addEdge(graph, v, vertex);
        }
        if (!feof(file)) {
            fscanf(file, "\n");
        }
    }

    fclose(file);
    return graph;
}

// Main function with a menu-driven program
int main() {
    int choice, vertices, src, dest;
    Graph* graph = NULL;
    int running = 1; // Running variable to control the loop

    while (running) {
        printf("\nMenu:\n");
        printf("1. Create a new graph\n");
        printf("2. Add an edge\n");
        printf("3. Display the graph\n");
        printf("4. Store graph data to a file\n");
        printf("5. Load graph data from a file\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of vertices: ");
                scanf("%d", &vertices);
                graph = createGraph(vertices);
                break;
            case 2:
                if (graph == NULL) {
                    printf("Graph not created. Please create a graph first.\n");
                    break;
                }
                printf("Enter source vertex: ");
                scanf("%d", &src);
                printf("Enter destination vertex: ");
                scanf("%d", &dest);
                addEdge(graph, src, dest);
                break;
            case 3:
                if (graph == NULL) {
                    printf("Graph not created. Please create a graph first.\n");
                    break;
                }
                displayGraph(graph);
                break;
            case 4:
                if (graph == NULL) {
                    printf("Graph not created. Please create a graph first.\n");
                    break;
                }
                printf("Enter the filename to store the graph: ");
                char filename[100];
                scanf("%s", filename);
                storeGraph(graph, filename);
                printf("Graph data stored successfully.\n");
                break;
            case 5:
                printf("Enter the filename to load the graph: ");
                scanf("%s", filename);
                graph = loadGraph(filename);
                if (graph == NULL) {
                    printf("Failed to load the graph.\n");
                } else {
                    printf("Graph data loaded successfully.\n");
                }
                break;
            case 6:
                printf("Exiting...\n");
                running = 0; // Set running to 0 to exit the loop
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}
