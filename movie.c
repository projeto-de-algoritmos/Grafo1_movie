#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 1000// tamanho máximo de uma linha do arquivo
typedef struct Node {
    char* title;
    struct Node* next;
} Node;
typedef struct Vertex {
    char* name;
    Node* head;
} Vertex;

typedef struct Graph {
    Vertex* vertices[MAX_SIZE];
    bool visited[MAX_SIZE];
} Graph;

Node* createNode(char* title) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->title = strdup(title);
    newNode->next = NULL;
    return newNode;
}

Vertex* createVertex(char* name) {
    Vertex* newVertex = (Vertex*)malloc(sizeof(Vertex));
    newVertex->name = strdup(name);
    newVertex->head = NULL;
    return newVertex;
}


Graph* createGraph() {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    for (int i = 0; i < MAX_SIZE; i++) {
        graph->vertices[i] = NULL;
        graph->visited[i] = false;
    }
    return graph;
}

void addEdge(Graph* graph, char* src, char* dest) {
    Vertex* srcVertex = NULL;
    Vertex* destVertex = NULL;
    for (int i = 0; i < MAX_SIZE; i++) {
        if (graph->vertices[i] == NULL) {
            break;
        }
        if (strcmp(graph->vertices[i]->name, src) == 0) {
            srcVertex = graph->vertices[i];
        }
        if (strcmp(graph->vertices[i]->name, dest) == 0) {
            destVertex = graph->vertices[i];
        }
    }
    if (srcVertex == NULL) {
        srcVertex = createVertex(src);
        for (int i = 0; i < MAX_SIZE; i++) {
            if (graph->vertices[i] == NULL) {
                graph->vertices[i] = srcVertex;
                break;
            }
        }
    }
    if (destVertex == NULL) {
        destVertex = createVertex(dest);
        for (int i = 0; i < MAX_SIZE; i++) {
            if (graph->vertices[i] == NULL) {
                graph->vertices[i] = destVertex;
                break;
            }
        }
    }
    Node* newNode = createNode(dest);
    newNode->next = srcVertex->head;
    srcVertex->head = newNode;
}


int main() {
    Graph* graph = createGraph();

    FILE* file = fopen( "./output.csv", "r");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo ");
        return 1;
    }

    char line[1024];
    fgets(line, 1024, file); // skip header line

    while (fgets(line, 1024, file)) {
        char* productionCompany = strtok(line, ",");
        char* title = strtok(NULL, ",");
        addEdge(graph, productionCompany, title);
    }

    fclose(file);
    return 0;
}
