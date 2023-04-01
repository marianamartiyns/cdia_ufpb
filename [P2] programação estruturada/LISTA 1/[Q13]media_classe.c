#include <stdio.h>
#include <locale.h>

void relatorio(float media_classe, int aprovados, int reprovados, char nomes[][50], float notas[][2]) {

    int i;
    printf("\n\nAluno\tProva 1\tProva 2\tMedia\tSituação\n\n");
    for (i = 0; i < 6; i++) {

        float media = (notas[i][0] + notas[i][1]) / 2.0;

        printf("%s\t%.1f\t%.1f\t%.1f\t", nomes[i], notas[i][0], notas[i][1], media);
        if (media >= 7.0)
            printf("Aprovado\n");
        else
            printf("Reprovado\n");

    }

    printf("\nMedia da classe: %.1f\n", media_classe);
    printf("Quantidade de aprovados: %d (%.1f%%)\n", aprovados, (float)aprovados / 6 * 100);
    printf("Quantidade de reprovados: %d (%.1f%%)\n", reprovados, (float)reprovados / 6 * 100);
}

int main() {

    setlocale(LC_ALL, "Portuguese");
    void exibe_relatorio(float media_classe, int aprovados, int reprovados, char nomes[][50], float notas[][2]);
    char nomes[6][50];
    float notas[6][2], media_classe = 0;
    int aprovados = 0, reprovados = 0, i;

    printf("\n== Digite o nome e as duas notas dos 6 alunos ==\n");
    for (i = 0; i < 6; i++) {

        printf("\nNome do %dº Aluno: ", i +1);
        scanf("%s", nomes[i]);
        printf("Sua 1ª Nota: ", i + 1);
        scanf("%f", &notas[i][0]);
        printf("Sua 2ª Nota: ");
        scanf("%f", &notas[i][1]);

        media_classe += (notas[i][0] + notas[i][1]) / 2.0;

        if ((notas[i][0] + notas[i][1]) / 2.0 >= 7.0)
            aprovados++;
        else
            reprovados++;
    }

    media_classe /= 6;
    relatorio(media_classe, aprovados, reprovados, nomes, notas);
}


