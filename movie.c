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
    }

    fclose(file);
    return 0;
}
