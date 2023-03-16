/* Imaginemos agora uma escola que adote no seu processo de avaliação a realização de duas
avaliações bimestrais e que o regime de aprovação dos alunos seja o seguinte:

i) Se a média das avaliações bimestrais for superior ou igual a 7,0, o aluno está aprovado, com média
final igual à média das avaliações bimestrais.

ii) Se a média das avaliações bimestrais for inferior a 5,0, o aluno está reprovado, com média final
igual à média das avaliações bimestrais.

iii) Não ocorrendo nenhum dos casos anteriores, o aluno se submete a uma prova final e a sua média
final será a média ponderada desta prova final (com peso 4) e a média das avaliações bimestrais (com peso 6).

Neste caso, o aluno estará aprovado se a sua média final for superior ou igual a 5,5.

O programa abaixo recebendo as notas das avaliações bimestrais e, se for o caso, a nota da prova final,
fornece a média final do aluno e a sua condição em relação à aprovação.

Programa para verificar aprovação de um aluno*/

// forneca a nota minina para ele ir pra final

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
        printf("\nO aluno está APROVADO! Com média %.1f.\n", medbim);

    else{
        if (medbim < 5)
            printf("\nO aluno está REPROVADO! Com média %.1f o aluno está ílegivel para a final, na qual o mínimo é 5.0.\n", medbim);

        else{

            notafinal = (55 - 6 * medbim) / 4;

            printf("\nO aluno está na PROVA FINAL precisando obter uma pontuação igual ou maior a %.1f.\n", notafinal);

        }
    }

    return 0;
}
