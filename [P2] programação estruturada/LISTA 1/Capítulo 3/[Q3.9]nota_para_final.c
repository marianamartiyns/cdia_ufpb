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

    float Bim1, Bim2, MedBim, PrFinal, MedFinal;

    printf("Digite as duas notas bimestrais");
    scanf("%f %f ", &Bim1, &Bim2);

    MedBim = (Bim1 + Bim2)/4;
    MedFinal = MedBim;

    if ((MedBim < 7) && (MedBim >= 5)){

        printf("Digite a nota da prova final");
        scanf("%f", &PrFinal);

        MedFinal = (MedBim * 6 + PrFinal * 4)/10;
    }

    if (MedFinal > 5.5)
        printf("Aluno aprovado com media final %.2f \n", MedFinal);

    else
        printf("Aluno reprovado com media final %0.2f \n", MedFinal);

    return 0;
}
