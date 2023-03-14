#include <stdio.h>
#include <locale.h>
#include <math.h>

int main(){

    setlocale(LC_ALL, 'Portuguese');

    int quant_lados;
    float raio, perim, seno, pi = 3.1416;

    printf("Digite a quantidade de lados do pol�gono: ");
    scanf("%d", &quant_lados);

    printf("Digite o tamanho do raio: ");
    scanf("%f", &raio);

    perim = 2 * quant_lados * sin(pi/quant_lados);

    printf("\nO per�metro do pol�gono de %d lados � %2.f:%2.f\n", quant_lados, raio, perim);

    return 0;
}
