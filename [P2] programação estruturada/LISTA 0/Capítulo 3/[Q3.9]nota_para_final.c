#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){

    setlocale(LC_ALL, "Portuguese");

    float bim1, bim2, medbim, medfinal, notafinal;

    printf("\nDigite as duas notas bimestrais: ");
    scanf("%f %f", &bim1, &bim2);

    medbim = (bim1 + bim2)/2;

    if (medbim >= 7)
        printf("\nO aluno est� APROVADO! Com m�dia %.1f.\n", medbim);

    else{
        if (medbim < 5)
            printf("\nO aluno est� REPROVADO! Com m�dia %.1f o aluno est� �legivel para a final, na qual o m�nimo � 5.0.\n", medbim);

        else{

            notafinal = (55 - 6 * medbim) / 4;

            printf("\nO aluno est� na PROVA FINAL precisando obter uma pontua��o igual ou maior a %.1f.\n", notafinal);

        }
    }
}
