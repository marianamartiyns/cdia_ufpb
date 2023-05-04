//

#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_LINE_LENGTH 100

void modifyData(const char* fileName, const char* name);

int main() {
    modifyData("exer08.txt", "João");

    return 0;
}

void modifyData(const char* fileName, const char* name) {
    char line[MAX_LINE_LENGTH], newName[MAX_NAME_LENGTH], newGrades[MAX_LINE_LENGTH];
    FILE* file = fopen(fileName, "r+"); // abre o arquivo em modo leitura/escrita

    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        char* token = strtok(line, ","); // separa a linha por vírgulas
        if (strcmp(token, name) == 0) { // verifica se o primeiro token é igual ao nome buscado
            printf("Dados atuais: %s", line);
            printf("Digite o novo nome: ");
            fgets(newName, MAX_NAME_LENGTH, stdin);
            printf("Digite as novas notas: ");
            fgets(newGrades, MAX_LINE_LENGTH, stdin);
            fseek(file, -strlen(line), SEEK_CUR); // retrocede o cursor para o início da linha atual
            fprintf(file, "%s,%s\n", newName, newGrades); // escreve os novos dados no arquivo
            printf("Dados atualizados.\n");
            break;
        }
    }

    fclose(file);
}
