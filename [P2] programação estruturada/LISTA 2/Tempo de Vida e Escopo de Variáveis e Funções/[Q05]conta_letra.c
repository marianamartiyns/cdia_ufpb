#include <stdio.h>
#include <string.h>

int contar_letras(char letra, char *string) {
    int i, cont = 0;
    static int total = 0;

    for (i = 0; i < strlen(string); i++) {
        if (string[i] == letra) {
            cont++;
        } total++;
    }

    printf("A letra '%c' apareceu %d vezes.\n", letra, cont);
    printf("Total de letras contadas: %d\n", total);

    return cont;
}

int main() {

    char string[100], letra;
    int cont;

    printf("Digite uma string: ");
    fgets(string, 100, stdin);

    printf("Digite uma letra para contar: ");
    scanf("%c", &letra);

    cont = contar_letras(letra, string);

    return 0;
}
