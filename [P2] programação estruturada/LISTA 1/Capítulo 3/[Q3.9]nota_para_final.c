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

    return 0;
}
