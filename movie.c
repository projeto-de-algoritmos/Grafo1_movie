#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LINE_SIZE 1000 // tamanho máximo de uma linha do arquivo
typedef struct Node {
    char* title;
    struct Node* next;
} Node;
typedef struct Vertex {
    char* name;
    Node* head;
} Vertex;

typedef struct Graph {
    Vertex* vertices[MAX_LINE_SIZE];
    bool visited[MAX_LINE_SIZE];
} Graph;


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
