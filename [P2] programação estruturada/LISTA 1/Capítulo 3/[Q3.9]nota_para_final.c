/* Imaginemos agora uma escola que adote no seu processo de avalia��o a realiza��o de duas
avalia��es bimestrais e que o regime de aprova��o dos alunos seja o seguinte:

i) Se a m�dia das avalia��es bimestrais for superior ou igual a 7,0, o aluno est� aprovado, com m�dia
final igual � m�dia das avalia��es bimestrais.

ii) Se a m�dia das avalia��es bimestrais for inferior a 5,0, o aluno est� reprovado, com m�dia final
igual � m�dia das avalia��es bimestrais.

iii) N�o ocorrendo nenhum dos casos anteriores, o aluno se submete a uma prova final e a sua m�dia
final ser� a m�dia ponderada desta prova final (com peso 4) e a m�dia das avalia��es bimestrais (com peso 6).

Neste caso, o aluno estar� aprovado se a sua m�dia final for superior ou igual a 5,5.

O programa abaixo recebendo as notas das avalia��es bimestrais e, se for o caso, a nota da prova final,
fornece a m�dia final do aluno e a sua condi��o em rela��o � aprova��o.

Programa para verificar aprova��o de um aluno*/

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
