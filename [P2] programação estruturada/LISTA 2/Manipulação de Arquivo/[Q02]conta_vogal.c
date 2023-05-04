#include <stdio.h>
#include <ctype.h>

int isVowel(char c) {
    c = toupper(c);
    return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

int main() {
    FILE *arquivo;
    char caractere;
    int vogais[5] = {0, 0, 0, 0, 0};

    arquivo = fopen("exer02_vogais.txt", "r");

    while ((caractere = fgetc(arquivo)) != EOF) {
        if (isVowel(caractere)) {
            switch (toupper(caractere)) {
                case 'A':
                    vogais[0]++;
                    break;
                case 'E':
                    vogais[1]++;
                    break;
                case 'I':
                    vogais[2]++;
                    break;
                case 'O':
                    vogais[3]++;
                    break;
                case 'U':
                    vogais[4]++;
                    break;
            }
        }
    }

    fclose(arquivo);

    printf("\nNúmero de vogais:\nA: %d\nE: %d\nI: %d\nO: %d\nU: %d\n", vogais[0], vogais[1], vogais[2], vogais[3], vogais[4]);

    return 0;
}

