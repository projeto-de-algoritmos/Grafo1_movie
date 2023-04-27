#include <stdio.h>
#include <string.h>

#define MAX_LINE_SIZE 1024 // tamanho máximo de uma linha do arquivo

int main() {
    char filename[] = "movies_metadata_autor - movies_metadata.csv"; // substitua pelo caminho real do arquivo
    FILE* file = fopen(filename, "r");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo %s", filename);
        return 1;
    }

    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, file)) {
        char* token = strtok(line, ","); // separa a linha em tokens usando a vírgula como delimitador
        while (token != NULL) {
            printf("%s ", token);
            token = strtok(NULL, ","); // avança para o próximo token
        }
        printf("\n");
    }

    fclose(file);
    return 0;
}
