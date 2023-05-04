#include <stdio.h>

int main() {

    FILE* file;
    char c;

    file = fopen("exer09.txt", "r+");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // Lê o arquivo caractere por caractere
    while ((c = fgetc(file)) != EOF) {

        switch (c) {

            case 'a':
                fseek(file, -1L, SEEK_CUR); // Retrocede 1 byte
                fputc('4', file); // Escreve '4' no lugar do 'a'
                fseek(file, 0L, SEEK_CUR); // Avança 1 byte para a frente
                break;

            case 'e':
                fseek(file, -1L, SEEK_CUR);
                fputc('3', file);
                fseek(file, 0L, SEEK_CUR);
                break;

            case 'i':
                fseek(file, -1L, SEEK_CUR);
                fputc('1', file);
                fseek(file, 0L, SEEK_CUR);
                break;

            case 'o':
                fseek(file, -1L, SEEK_CUR);
                fputc('0', file);
                fseek(file, 0L, SEEK_CUR);
                break;

            case 'u':
                fseek(file, -1L, SEEK_CUR);
                fputc('5', file);
                fseek(file, 0L, SEEK_CUR);
                break;
        }
    }

    fclose(file);

    return 0;
}


